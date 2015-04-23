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

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

double dp[128][1024], f[1024];
int calc[128][1024], c[1024], calc_now;

double solve(int pos, int bud) {
    if(pos == -1) return 1.0;
    
    double &res = dp[pos][bud];
    int &last_calc = calc[pos][bud];
    
    if(last_calc == calc_now) return res;
    last_calc = calc_now;
    res = 0;
    double fail = 1.0;
    for(int buy = 1; buy*c[pos] <= bud; buy++) {
        fail *= f[pos];
        res = max(res, (1.0-fail)*solve(pos-1,bud-buy*c[pos]));
    }
        
    return res;
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int N, B;
    while(cin >> N >> B && (N || B)) {
        REP(i,N) cin >> c[i] >> f[i];
        calc_now++;
        cout << fixed << setprecision(3) << solve(N-1,B) << "\n";
    }
    
    return 0;
}
















