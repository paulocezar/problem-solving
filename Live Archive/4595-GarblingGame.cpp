#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int DIG = 4;
const int BASE = 10000;
const int TAM = 100;

struct bigint {
    int v[TAM], n;
    bigint(int x = 0): n(1) {
        memset(v, 0, sizeof(v));
        v[n++] = x; fix();
    }
    bigint(const char *s): n(1) {
        memset(v, 0, sizeof(v));
        int sign = 1;
        while (*s && !isdigit(*s)) if (*s++ == '-') sign *= -1;
        char *t = strdup(s), *p = t + strlen(t);
        while (p > t) {
            *p = 0; p = max(t, p - DIG);
            sscanf(p, "%d", &v[n]);
            v[n++] *= sign;
        }
        free(t); fix();
    }
    bigint& fix(int m = 0) {
        n = max(m, n);
        int sign = 0;
        for (int i = 1, e = 0; i <= n || e && (n = i); i++) {
            v[i] += e; e = v[i] / BASE; v[i] %= BASE;
            if (v[i]) sign = (v[i] > 0) ? 1 : -1;
        }

        for (int i = n - 1; i > 0; i--)
            if (v[i] * sign < 0) { v[i] += sign * BASE; v[i+1] -= sign; }
        while (n && !v[n]) n--;
        return *this;
    }

    int cmp(const bigint& x = 0) const {
        int i = max(n, x.n), t = 0;
        while (1) if ((t = (v[i] - x.v[i])) || i-- == 0) return t;
    }
    bool operator <(const bigint& x) const { return cmp(x) < 0; }
    bool operator >(const bigint& x) const { return cmp(x) > 0; }
    bool operator ==(const bigint& x) const { return cmp(x) == 0; }
    bool operator !=(const bigint& x) const { return cmp(x) != 0; }

    
    bigint& operator +=(const bigint& x) {
        for (int i = 1; i <= x.n; i++) v[i] += x.v[i];
        return fix(x.n);
    }
    bigint operator +(const bigint& x) { return bigint(*this) += x; }
    bigint& operator -=(const bigint& x) {
        for (int i = 1; i <= x.n; i++) v[i] -= x.v[i];
        return fix(x.n);
    }
    bigint operator -(const bigint& x) { return bigint(*this) -= x; }
    bigint operator -() { bigint r = 0; return r -= *this; }
    void ams(const bigint& x, int m, int b) { // *this += (x * m) << b;
        for (int i = 1, e = 0; (i <= x.n || e) && (n = i + b); i++) {
            v[i+b] += x.v[i] * m + e; e = v[i+b] / BASE; v[i+b] %= BASE;
        }
    }
    bigint operator *(const bigint& x) const {
        bigint r;
        for (int i = 1; i <= n; i++) r.ams(x, v[i], i-1);
        return r;
    }
    bigint& operator *=(const bigint& x) { return *this = *this * x; }
    // cmp(x / y) == cmp(x) * cmp(y); cmp(x % y) == cmp(x);
    bigint div(const bigint& x) {
        if (x == 0) return 0;
        bigint q; q.n = max(n - x.n + 1, 0);
        int d = x.v[x.n] * BASE + x.v[x.n-1];
        for (int i = q.n; i > 0; i--) {
            int j = x.n + i - 1;
            q.v[i] = int((v[j] * double(BASE) + v[j-1]) / d);
            ams(x, -q.v[i], i-1);
            if (i == 1 || j == 1) break;
            v[j-1] += BASE * v[j]; v[j] = 0;
        }
        fix(x.n); return q.fix();
    }
    bigint& operator /=(const bigint& x) { return *this = div(x); }
    bigint& operator %=(const bigint& x) { div(x); return *this; }
    bigint operator /(const bigint& x) { return bigint(*this).div(x); }
    bigint operator %(const bigint& x) { return bigint(*this) %= x; }
    
};

#define MAXR 300
#define MAXC 300

const int mod = 100000;

int ax[MAXR*MAXC];

string gmap[MAXR];
int len, r, c;

struct state_t {
    vector<int> element_at, was_printed;
    state_t() {
        element_at = vector<int> (len);
        was_printed = vector<int> (len);
        for (int i = 0; i < len; ++i) element_at[i] = i, was_printed[i] = 0;
    }
};

struct change_t {
    vector<int> goes_to, is_printed; 
    change_t() {
        goes_to = vector<int> (len);
        is_printed = vector<int> (len);
    }
    void apply(state_t &at) {
        for (int i = 0; i < len; ++i) {
            at.was_printed[ at.element_at[i] ] += is_printed[i];
            if (at.was_printed[ at.element_at[i] ] >= mod)
                at.was_printed[ at.element_at[i] ] -= mod;
            ax[ goes_to[i] ] = at.element_at[i];
        }
        for (int i  = 0; i < len; ++i) at.element_at[i] = ax[i];   
    }
    
    void increase_casts() {
        for (int i = 0; i < len; ++i) {
            ax[i] = is_printed[i] + is_printed[goes_to[i]];
            if (ax[i] >= mod) ax[i] -= mod;
        }
        for (int i = 0; i < len; ++i) is_printed[i] = ax[i];
        for (int i = 0; i < len; ++i) ax[i] = goes_to[goes_to[i]];
        for (int i = 0; i < len; ++i) goes_to[i] = ax[i];
    }
};

void rotL(int *vet, int i, int j) {
    
    int A = i*c + j;
    int B = i*c + j + 1;
    int C = (i+1)*c + j;
    int D = (i+1)*c + j + 1;
    
    ax[0] = vet[A];
    vet[A] = vet[B];
    vet[B] = vet[D];
    vet[D] = vet[C];
    vet[C] = ax[0]; 

}

void rotR(int *vet, int i, int j) {
    
    int A = i*c + j;
    int B = i*c + j + 1;
    int C = (i+1)*c + j;
    int D = (i+1)*c + j + 1;

    ax[0] = vet[A];
    vet[A] = vet[C];
    vet[C] = vet[D];
    vet[D] = vet[B];
    vet[B] = ax[0]; 

}

change_t garble(bigint steps) {
    change_t res;
    
    int element[len], printed[len];
    for (int i = 0; i < len; ++i) element[i] = i, printed[i] = 0;
    
    for (int i = 0; i < (r-1); ++i) {
        for (int j = 0; j < (c-1); ++j) {
            if (steps > 0) {
                printed[element[i*c+j]]++;
                switch (gmap[i][j]) {
                    case 'L': rotL(element, i, j); break;
                    case 'R': rotR(element, i, j); break;
                    default: break;
                }
                steps -= 1;
            } else break;
        }
    }
    
    for (int i = 0; i < len; ++i) {
        res.goes_to[element[i]] = i;
        res.is_printed[i] = printed[i];
    }
    return res;
} 

int main() {
    ios::sync_with_stdio(false);
    
    bool first = true;
    string sn;
    while (cin >> r >> c) {
        if (first) first = false;
        else cout << "\n";
        
        cin >> sn;
        bigint n(sn.c_str());
        
        len = r*c;
        
        for (int i = 0; i < (r-1); ++i) cin >> gmap[i];
        
        change_t full_board = garble((r-1)*(c-1));        
        change_t remaining = garble(n % ((r-1)*(c-1)));
        state_t board;
        
        bigint fully = n / ((r-1)*(c-1));
        while (fully > 0) {
            if ((fully % 2) != 0) full_board.apply(board);
            full_board.increase_casts();
            fully /= 2;
        }
        remaining.apply(board);
        for (int i = 0; i < len; ++i) cout << board.was_printed[i] << "\n";
    }
    
    
    return 0;
}