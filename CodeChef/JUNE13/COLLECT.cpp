#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = a.begin(); i != a.end(); i++)

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod = 3046201LL;

int64 fpow(int64 a, int b) {
    int64 res = 1LL;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int f[3000001];
int bit[100001];
int val[100001];
int N;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    cin >> N;
    
    f[0] = 1;
    int64 ff = 1LL;
    for (int i = 1; i <= 30*N; ++i) {
        ff *= int64(i);
        ff %= mod;
        f[i] = ff;
    }
    
    FOR(i, 1, N) {
        int x; cin >> x;
        int idx = i;
        val[i] = x;
        while (idx <= N) {
            bit[idx] += x;
            idx += (idx & -idx);
        }
    }
    
    int Q;
    cin >> Q;
    string cmd;
    int a, b;
    while (Q--) {
        cin >> cmd >> a >> b;
        if (cmd[0] == 'c') {
            int dif = b - val[a];
            val[a] = b;
            while (a <= N) {
                bit[a] += dif;
                a += (a & -a);
            }
        } else {
            int k = b-a+1;
            int sum = 0;
            while (b > 0) {
                sum += bit[b];
                b -= (b & -b);
            }
            a--;
            while (a > 0) {
                sum -= bit[a];
                a -= (a & -a);
            }
            
            int xtr = (sum % k);
            int bsc = k - xtr;
            
            int64 den = (fpow(f[sum/k + 1], xtr) * fpow(f[sum/k], bsc)) % mod;
            den *= f[xtr]; den %= mod;
            den *= f[bsc]; den %= mod;
            den = fpow(den, mod-2);
            
            int64 num = (int64(f[sum]) * int64(f[k])) % mod;
            cout << ((num * den)%mod) << "\n";
                        
        }
    }
    
    
	return 0;
}

















