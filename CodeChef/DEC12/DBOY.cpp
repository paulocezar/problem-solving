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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

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

template<typename T> T inline SQR(const T &a) { return a*a; }
template<typename T> T inline ABS(const T &a) { return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN(double a){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP(double a, double b){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 512

int h[MAXN], k[MAXN];
int mn[2*MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        
        int mx = -1;
        REP(i, n) { cin >> h[i]; mx = max(mx, h[i]); }
        REP(i, n) cin >> k[i];
        
        mn[0] = 1;
        FOR(i, 1, 2*mx) {
            mn[i] = 0;
            REP(j, n) if (i >= k[j] && mn[i-k[j]]) {
                if (mn[i]) mn[i] = 1 + min(mn[i]-1, mn[i-k[j]]);
                else mn[i] = 1 + mn[i-k[j]];
            }
        }
        int res = 0;
        REP(i, n) res += mn[ 2*h[i] ];
        cout << res-n << "\n";
    }
	 
	return 0;
}

















