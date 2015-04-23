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

double ax[128][128], p[128][128];
int gr[128][128], deg[128], grn;


int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int N, A, B, C;
    while (cin >> N >> A >> B >> C) {
        
        grn++;
        FOR(i,1,N) deg[i] = 0;
        
        REP(i,N-1) {
            int u, v;
            cin >> u >> v;
            gr[u][v] = gr[v][u] = grn;
            deg[u]++;
            deg[v]++;
        }
        
        FOR(i,1,N) FOR(j,1,N)
            if(i == B || i == C)
                p[i][j] = (i==j)?(1.0):(0.0);
            else if(gr[i][j] == grn)
                p[i][j] = 1.0/double(deg[i]);
            else p[i][j] = 0.0;
        
        REP(stp,15) {
            FOR(i,1,N) FOR(j,1,N) {
                ax[i][j] = 0.0;
                FOR(k,1,N)
                    ax[i][j] += p[i][k]*p[k][j];
            }
            FOR(i,1,N)FOR(j,1,N) p[i][j] = ax[i][j];
        }
        
        cout << fixed << setprecision(6) << p[A][B]/(p[A][B]+p[A][C]) << "\n";
        
    }
    
    return 0;
}
















