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

#define MAXV (50*50+2)

int ppa[MAXV], pa[MAXV], curflow[MAXV], seen[MAXV], last_seen;
string grid[64];
vector< vector<int> > gr, cap, flow, rev;

inline void add_edge(int from, int to, int cft, int ctf) {
    int sf = SIZE(gr[from]), st = SIZE(gr[to]);
    gr[from].PB(to);
    cap[from].PB(cft);
    flow[from].PB(0);
    rev[from].PB(st);
    
    gr[to].PB(from);
    cap[to].PB(ctf);
    flow[to].PB(0);
    rev[to].PB(sf);
}

int source, sink;

inline int residual(int u, int i) {
    return (cap[u][i] - flow[u][i]);
}

bool augment() {
    last_seen++;
    
    queue<int> q;
    q.push(source);
    
    curflow[source] = 2e9;
    pa[source] = source;
    seen[source] = last_seen;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == sink) return true;
        
        REP(i, SIZE(gr[u])) {
            int v = gr[u][i];
            if (seen[v] != last_seen && residual(u,i) > 0) {
                q.push(v);
                pa[v] = u;
                ppa[v] = i;
                seen[v] = last_seen;
                curflow[v] = min(curflow[u],residual(u,i));
            }
        }
        
    }
    
    return false;
}

void update() {
    int x = sink;
    while (x != source) {
        flow[ pa[x] ][ ppa[x] ] += curflow[sink];
        flow[ x ][ rev[pa[x]][ppa[x]] ] -= curflow[sink];
        x = pa[x];
    }
}

int maxflow() {
    int res = 0;
    while (augment()) {
        res += curflow[sink];
        update();
    }
    return res;
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int t;
    cin >> t;
    while (t--) {
        int w, h;
        cin >> w >> h;
        int d, f, b;
        cin >> d >> f >> b;
        
        REP(i,h) cin >> grid[i];

        gr.assign(2+w*h,vector<int>());
        cap.assign(2+w*h,vector<int>());
        flow.assign(2+w*h,vector<int>());
        rev.assign(2+w*h,vector<int>());
        source = 0, sink = 1;
        
#define vertex(a,b) ((a)*w+(b)+2)
#define boundary(i,j)  ((i==0)||(j==0)||(i==(h-1))||(j==(w-1)))
        
        int ans = 0;
        REP(i,h) REP(j,w) {
            
            if (grid[i][j] == '#') {
                if (boundary(i,j)) {
                    add_edge(source,vertex(i,j),1e9,0);
                } else {
                    add_edge(source,vertex(i,j),d,0);
                }
            } else {
                if (boundary(i,j)) {
                    ans += f;
                    add_edge(source,vertex(i,j),1e9,0);
                } else {
                    add_edge(vertex(i,j),sink,f,0);
                }
            }
            
            if (i+1 < h) add_edge(vertex(i,j), vertex(i+1,j), b, b);
            if (j+1 < w) add_edge(vertex(i,j), vertex(i,j+1), b, b);
                                    
        }
        ans += maxflow();
        cout << ans << "\n";
        
    }
    
    return 0;
}
















