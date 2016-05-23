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

int cid;
map< vector<int>, int > id;

#define MAXN 10000

vector<int> gr[2][MAXN];
int deg[2][MAXN];
bool rem[2][MAXN];

int cur;

int encode(int u, int pa = -1) {   
    vector<int> ble;
    
    REP(i,SIZE(gr[cur][u])) {
        int v = gr[cur][u][i];
        if(v != pa) ble.PB(encode(v,u));
    }
    
    sort(ALL(ble));
    if(!id.count(ble)) id[ble] = cid++;
    return id[ble];
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    cid = 1;
    id.clear();
    
    int N;
    while(cin >> N) {

        REP(g,2) {
            REP(i,N) {
                gr[  g ][ i ].clear();
                deg[ g ][ i ] = 0;
                rem[ g ][ i ] = false;
            }
        }
        
        int u, v;
        REP(g,2) {
            REP(i, N-1) {
                
                cin >> u >> v;
                
                u--; v--;
                deg[ g ][ u ]++;
                deg[ g ][ v ]++;
                gr[ g ][ u ].PB(v);
                gr[ g ][ v ].PB(u);
            }
        }
        
        queue<int> q[2];
        REP(g,2) {
            REP(i,N) {
                if(deg[ g ][ i ] == 1){
                    q[  g ].push(i);
                    rem[g][i] = true;
                }
            }
        }
        
        REP(g,2) {
            REP(pqp,N-2) {
                u = q[ g ].front();
                    q[ g ].pop();
                
                REP( i, SIZE(gr[g][u]) ) {
                    v = gr[g][u][i];
                    if(!rem[g][v]) {
                        deg[g][ v ]--;
                        if (deg[g][ v ] == 1) {
                            q[g].push( v );
                            rem[g][ v ] = true;
                        }
                    }
                }
            }
        }

        cur = 0;
        int r1 = q[cur].front(); q[cur].pop();
        r1 = q[cur].front();
        int q1 = encode(r1);   
        
        cur = 1;
        int r2 = q[cur].front(); q[cur].pop();
        int r22 = q[cur].front();
        int q2 = encode(r2);
        if(q1 != q2){ 
            q2 = encode(r22);
        }
        
        if(q1 == q2) cout << "S\n";
        else cout << "N\n";
        
    }
    
    return 0;
}















