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

vector<int> pos[128];

int64 mod;
int64 fpw(int64 a, int b) {
    int64 res = 1LL;
    while (b > 0) {
        if (b&1) { res *= a; res %= mod; }
        a *= a; a %= mod;
        b >>= 1;
    }
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    FOR(i,1,n) {
        int a; cin >> a;
        pos[a].PB(i);
    }
    int t;
    cin >> t;
    while (t--) {
        int lo, hi;
        cin >> lo >> hi >> mod;
        int64 res = 1LL;
        FOR(a,1,100) {
            int amnt = upper_bound(pos[a].begin(), pos[a].end(), hi) -
                        upper_bound(pos[a].begin(), pos[a].end(), lo-1);
            if (amnt) {
                res *= fpw(a%mod,amnt);
                if (res >= mod) res %= mod;
            }
        } 
        cout << res << "\n";
    }
    
	return 0;
}

















