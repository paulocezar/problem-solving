#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int DIG = 4;
const int BASE = 10000;
const int TAM = 32;

struct bigint {
    int v[TAM], n;
    bigint(int x = 0): n(1) {
        memset(v, 0, sizeof(v));
        v[n++] = x; fix();
    }
    bigint(char *s): n(1) {
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
    
    operator string() const {
        ostringstream s; s << v[n];
        for (int i = n - 1; i > 0; i--) {
            s.width(DIG); s.fill('0'); s << abs(v[i]);
        }
        return s.str();
    }
    friend ostream& operator <<(ostream& o, const bigint& x) {
        return o << (string) x;
    }
    
    bigint& operator +=(const bigint& x) {
        for (int i = 1; i <= x.n; i++) v[i] += x.v[i];
        return fix(x.n);
    }
    bigint operator +(const bigint& x) { return bigint(*this) += x; }
};

bigint dp[2][1024];

int phi[1024][32];
int chi[1024][32];

int make_absorbing(int state, int alph) {
    if (!chi[state][alph]) return phi[state][alph];
    if (chi[state][alph] == -1) return -1;
    chi[state][alph] = -1;
    phi[state][alph] = make_absorbing(phi[state][alph], alph);
    chi[state][alph] = 0;
    return phi[state][alph];
}

int main(int argc, char* argv[]) {
    
    ios::sync_with_stdio(false);
        
    int T;
    cin >> T;
    while (T--) {
        
        string z;
        cin >> z;
        int Z = z.size();
        
        int K, S, L, N;
        cin >> K;
        cin >> S;
        cin >> L;
        
        for (int s = 1; s <= K; ++s) {
            dp[0][s] = 0;
        }
        
        for (int i = 0; i < L; ++i) {
            int u; cin >> u;
            dp[0][u] = 1;
        }
        
        for (int s = 1; s <= K; ++s) {
            for (int a = 0; a < Z; ++a) {
                cin >> phi[s][a];
            }
        }
        
        for (int s = 1; s <= K; ++s) {
            for (int a = 0; a < Z; ++a) {
                cin >> chi[s][a];
            }
        }
        
        cin >> N;
        
        for (int s = 1; s <= K; ++s) {
            for (int a = 0; a < Z; ++a) {
                make_absorbing(s,a);
            }
        }
        
        int cur = 1, old = 0;
        for (int i = 1; i <= N; ++i) {
            
            for (int state = 1; state <= K; ++state) {
                dp[cur][state] = 0;
                for (int a = 0; a < Z; ++a) {
                    if (phi[state][a] > 0) {
                        dp[cur][state] += dp[old][phi[state][a]];
                    }
                }
            }
            
            cur = 1-cur;
            old = 1-old;
        }
        
        cout << dp[old][S] << "\n";
        if (T) cout << "\n";
    }
    
    return 0;
}

















