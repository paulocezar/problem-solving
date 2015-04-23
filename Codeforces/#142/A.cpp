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

int l[100][10000], r[100][10000];

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int n, m;
    cin >> n >> m;
    string g[n];    
    REP(i,n) cin >> g[i];
    
    bool ok = true;
    REP(i,n) {
        
        int j1 = 0, j2 = m-1;
        if (g[i][j1] == '1') {
            l[i][j1] = 0;
        } else {
            int jj = m-1;
            l[i][j1] = 1;
            while (jj > 0 && g[i][jj] != '1') {
                l[i][j1]++;
                jj--;
            }
            if (jj == 0) { ok = false; break; }
        }
        
        if (g[i][j2] == '1') {
            r[i][j2] = 0;
        } else {
            int jj = 0;
            r[i][j2] = 1;
            while (jj < m && g[i][jj] != '1') {
                r[i][j2]++;
                jj++;
            }
            if (jj == m) { ok = false; break; }
        }
        
        REP(x,m-1) {
            j1++; j2--;
            if (g[i][j1] == '1') l[i][j1] = 0;
            else l[i][j1] = l[i][j1-1] + 1;
            
            if (g[i][j2] == '1') r[i][j2] = 0;
            else r[i][j2] = r[i][j2+1] + 1;
        }        
        
    }
    
    if (ok) {
        
        int ans = 2e9;
        REP(j,m) {
            int now = 0;
            REP(i,n) now += min(l[i][j], r[i][j]);
            ans = min(ans,now);
        }
        cout << ans << "\n";
    
    } else cout << "-1\n";
    
    return 0;
}
















