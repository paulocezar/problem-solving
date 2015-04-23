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

#define MAXN 64
int64 a[MAXN][MAXN];

int64 get(int x0, int y0, int x1, int y1) {
    int64 res = a[x1][y1];
    if (x0) res -= a[x0-1][y1];
    if (y0) res -= a[x1][y0-1];
    if (x0 && y0) res += a[x0-1][y0-1];
    return res;
}

int calc[51][51][51][51], calc_now;
int64 dp[51][51][51][51];

int64 solve(int x0, int y0, int x1, int y1) {
    if (x1 < x0 || y1 < y0) return 0;
    
    int64 &res = dp[x0][y0][x1][y1];
    int &last_calc = calc[x0][y0][x1][y1];
    if (last_calc == calc_now) return res;
    last_calc = calc_now;
    res = 0;
    
    int64 fr = get(x0,y0,x0,y1);
    int64 lr = get(x1,y0,x1,y1);
    int64 fc = get(x0,y0,x1,y0);
    int64 lc = get(x0,y1,x1,y1);
    
    int64 mn = min(fr,min(lr,min(fc,lc)));
    
    if (mn == fr) x0++;        
    else if (mn == lr) x1--;
    else if (mn == fc) y0++;
    else y1--;
    
    if (x1 < x0 || y1 < y0) return res;
    
    fr = get(x0,y0,x0,y1);
    lr = get(x1,y0,x1,y1);
    fc = get(x0,y0,x1,y0);
    lc = get(x0,y1,x1,y1);
    
    res = fr + solve(x0+1,y0,x1,y1);
    res = max(res, lr + solve(x0,y0,x1-1,y1));
    res = max(res, fc + solve(x0,y0+1,x1,y1));
    res = max(res, lc + solve(x0,y0,x1,y1-1));
    
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        REP(i,n) REP(j,m) {
            cin >> a[i][j];
            if (i) a[i][j] += a[i-1][j];
            if (j) a[i][j] += a[i][j-1];
            if (i && j) a[i][j] -= a[i-1][j-1];
        }
        
        calc_now++;
        int64 best = solve(0,0,n-1,m-1);
        int64 rem = a[n-1][m-1] - best;
        
        int64 win = max(best,rem);
        if (best == rem) win *= 2LL;
            
        cout << win << "\n";        
    }
	
	return 0;
}

















