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

const int64 mod = 1000000007LL;
int64 N[3];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int64 all = 1LL;
        for (int i = 0; i < 3; ++i) {
            cin >> N[i];
            all *= (N[i]%mod);
            all %= mod;
        }
        int64 eq = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = i+1; j < 3; ++j) {
                int64 rp = min(N[i], N[j]);
                int k = 0;
                while (k == i || k == j) ++k;
                eq += ((rp%mod) * (N[k]%mod))%mod; eq %= mod;
            }
        }
        int64 alleq = min(N[0], min(N[1], N[2])) % mod;
        all = (((all-eq)%mod) + mod)%mod;
        all += (2LL * alleq) % mod;
        all %= mod;
        cout << all << "\n";
    }
	 
	return 0;
}

















