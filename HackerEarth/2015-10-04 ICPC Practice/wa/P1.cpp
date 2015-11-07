#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1000000

bitset< MAXN+10 > bs;
vector< int > primes;

void sieve(){
    primes.clear();
    for (int i = 0; i <= MAXN; ++i) bs[i] = i&1;
    primes.push_back(2);

    for (int i = 3; i*i <= MAXN; i+=2) if (bs[i]) {
        for (int j = i*i; j <= MAXN; j+=i) bs[j] = false;
    }
    for (int i = 3; i <= MAXN; ++i) {
        if (bs[i]) primes.push_back(i);
    }
    primes.push_back(1000003);
    primes.push_back(1000033);
}

#define MAXV 256
#define INF 0x3F3F3F3F3F3F3F3FLL

int64 w[MAXV][MAXV], s[MAXV], rem[MAXV], remx[MAXV];
int mx[MAXV], my[MAXV];
int64 lx[MAXV], ly[MAXV];

void add(int x, int n) {
    s[x] = true;
    for(int y = 0; y < n; y++)
        if(rem[y] != -INF && rem[y] > lx[x] + ly[y] - w[x][y])
            rem[y] = lx[x] + ly[y] - w[x][y], remx[y] = x;
}

int64 kuhn_munkres(int n) {
    for(int i = 0; i < n; i++) mx[i] = my[i] = -1, lx[i] = ly[i] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ly[j] = max(ly[j], w[i][j]);

    for(int i = 0; i < n; i++) {
        memset(s, 0, sizeof s); memset(rem, 0x3f, sizeof rem);

        int st;
        for(st = 0; st < n; st++) if(mx[st] == -1) { add(st, n); break; }
        while(mx[st] == -1) {
            int miny = -1;
            for(int y = 0; y < n; y++)
                if(rem[y] != -INF && (miny == -1 || rem[miny] >= rem[y]))
                    miny = y;

            if(rem[miny]) {
                for(int x = 0; x < n; x++) if(s[x]) lx[x] -= rem[miny];
                for(int y = 0, d = rem[miny]; y < n; y++)
                    if(rem[y] == -INF) ly[y] += d; else rem[y] -= d;
            }

            if(my[miny] == -1) {
                int cur = miny;
                while(remx[cur] != st) {
                    int pmate = mx[remx[cur]];
                    my[cur] = remx[cur], mx[my[cur]] = cur;
                    my[pmate] = -1; cur = pmate;
                }
                my[cur] = remx[cur], mx[my[cur]] = cur;
            } else
                add(my[miny], n), rem[miny] = -INF;
        }
    }

    int64 ret = 0LL;
    for(int i = 0; i < n; i++)
        ret += w[i][mx[i]];
    return ret;
}

int a[512];
int fp[512];

int main(int argc, char* argv[]) {
    
    ios::sync_with_stdio(false);
    
    sieve();

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        fp[i] = lower_bound(primes.begin(), primes.end(), a[i]) - primes.begin();
    }

    N >>= 1;

    for (int ii = 0; ii < N; ++ii) {
        for (int jj = 0; jj < N; ++jj) {
            
            int i = ii<<1;
            int j = (jj<<1) | 1;
            
            if (i > j) swap(i, j);

            if (fp[i] < fp[j]) {
                w[ii][jj] = -(primes[fp[j]-1]-a[i]+primes[fp[j]]-a[j]+1);
            } else {
                w[ii][jj] = -(primes[fp[i]]-a[i]+primes[fp[i]+1]-a[j]+1);
            }
            
        }
    }

    cout << -kuhn_munkres(N) << "\n";

    return 0;
}
