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

string grid[501];
int sm[501][501];
char aok[10][16][501][501];

int get(int x1, int y1, int x2, int y2) {
    int res = sm[x2][y2];
    if(x1) res -= sm[x1-1][y2];
    if(y1) res -= sm[x2][y1-1];
    if(x1&&y1) res += sm[x1-1][y1-1];
    return res;
}

bool ok(int gr, int pat, int x1, int y1) {
    if(gr == 1) return (grid[x1][y1] == '.');
    
    char &old = aok[int(log2(gr))][pat][x1][y1];
    if (old) return ((old == 1) ? true : false);
    
    int x2 = x1+gr-1;
    int y2 = y1+gr-1;
    int xm = x1 + (gr/2) - 1;
    int ym = y1 + (gr/2) - 1;     
    int need = (gr/2)*(gr/2);
        
    if(pat & 1) {
        int black = get(x1,y1,xm,ym);
        if(black != need) {
            old = 2; return false;
        }
    } else {
        if(!ok(gr/2,pat,x1,y1)) {
            old = 2;
            return false;
        }
    }
    
    if(pat & 2) {
        int black = get(x1,ym+1,xm,y2);
        if(black != need) {
            old = 2; return false;
        }
    } else {
        if(!ok(gr/2,pat,x1,ym+1)) {
            old = 2;
            return false;
        }
    }
    
    if(pat & 4) {
        int black = get(xm+1,y1,x2,ym);
        if(black != need) {
            old = 2; return false;
        }
    } else {
        if(!ok(gr/2,pat,xm+1,y1)) {
            old = 2;
            return false;
        }
    }
    
    if(pat & 8) {
        int black = get(xm+1,ym+1,x2,y2);
        if(black != need) {
            old = 2; return false;
        }
    } else {
        if(!ok(gr/2,pat,xm+1,ym+1)) {
            old = 2;
            return false;
        }
    }
    
    old = 1;
    return true;
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int n, m;
    cin >> n >> m;
    
    REP(i,n) cin >> grid[i];
    
    REP(i,n) REP(j,m) {
        sm[i][j] = (i?sm[i-1][j]:0)
                    + (j?sm[i][j-1]:0)
                    - ((i&&j)?sm[i-1][j-1]:0)
                    + ((grid[i][j]=='*')?1:0);
    }
    
    int gr = max(n,m);
    gr = log2(gr);
    gr = (1<<gr);
    
    int64 ans = 0;
    while (gr >= 4) {
        REP(i,n) {
            if (i+gr-1 >= n) break;
            REP(j,m) {
                if (j+gr-1 >= m) break;
                for(int pat = 0; pat < 16; pat++) {  
                    
                    if (ok(gr,pat,i,j)) {
                        ans++;
                        break;   
                    }
                }
            }
        }
        
        gr >>= 1;
    }
    
    cout << ans << "\n";
    
    return 0;
}
















