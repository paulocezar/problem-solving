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

int len[1024];
int dis[1024];
int idis[1024];
int dep[1024];
int idep[1024];

vector<int> gr[1024];
vector<int> igr[1024];

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int N;
    while (cin >> N && N) {
        REP(i,N) {
            gr[i].clear();
            igr[i].clear();
            dis[i] = 0;
            idep[i] = 0;
        }
        
        queue< int > q;
        REP(i,N) {
            int u; cin >> u;
            cin >> len[u];
            cin >> dep[u];
            if(dep[u] == 0) q.push(u);
            REP(k,dep[u]) {
                int v; cin >> v;
                gr[v].PB(u);
                igr[u].PB(v);
                idep[v]++;
            }
        }
            
        int mx = 0;
        while(!q.empty()) {
            int sz = SIZE(q);
            REP(rm,sz) {
                int u = q.front(); q.pop();
                mx = max(mx,dis[u]+len[u]);
                REP(i,SIZE(gr[u])) {
                    int v = gr[u][i];
                    dis[v] = max(dis[v],dis[u]+len[u]);
                    dep[v]--;
                    if(dep[v] == 0) q.push(v);
                }
            }
        }
        
        REP(i,N) {
            idis[i] = mx-len[i];
            if(idep[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int sz = SIZE(q);
            REP(rm,sz) {
                int u = q.front(); q.pop();
                
                REP(i,SIZE(igr[u])) {
                    int v = igr[u][i];
                    idis[v] = min(idis[v],idis[u]-len[v]);
                    idep[v]--;
                    if(idep[v] == 0) q.push(v);
                }
            }
        }
        
        cout << "Prazo: " << mx << " dias\n";
        REP(u,N) {
            cout << "Tarefa #" << u << ": min=" << dis[u] << ", max=" << idis[u] << "\n";
        }
        cout << "---\n";
        
        
    }
    
    
    return 0;
}
















