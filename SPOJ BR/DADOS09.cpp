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

inline int opose(int x) {
    switch(x) {
        case 0: return 5;
        case 5: return 0;
        case 1: return 3;
        case 3: return 1;
        case 2: return 4;
        case 4: return 2;
    }
    return -1;
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int best[2][7];
    FILL(best,0);    
    
    int a[2][6];
    int b[2][7];
    REP(i,6) {
        a[0][i] = i+1;
        b[0][i+1] = i;
    }
    
    int n;
    cin >> n;
    int old = 0, cur = 1;
    while (n--) {
        REP(i,6) {
            cin >> a[cur][i];
            b[cur][ a[cur][i] ] = i;
        }
         
         FOR(i,1,6) {
             
             int bface = 0;
             switch (b[cur][i]) {
                 case 0:
                 case 5:
                    bface = max(a[cur][1], max(a[cur][2], max(a[cur][3], a[cur][4])));
                    break;
                case 1:
                case 3:
                    bface = max(a[cur][0], max(a[cur][2], max(a[cur][4], a[cur][5])));
                    break;
                case 2:
                case 4:
                    bface = max(a[cur][0], max(a[cur][1], max(a[cur][3], a[cur][5])));
                    break;
             }
             
             best[cur][i] = bface + best[old][ a[cur][ opose(b[cur][i]) ] ];
                          
         }
                
        old = !old;
        cur = !cur;
    }
    
    int ans = 6;
    FOR(i,1,6) {
        ans = max(ans,best[old][i]);
    }
    cout << ans << "\n";
    
    return 0;
}
















