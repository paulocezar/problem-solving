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

int ds[][2] = {{1,0},{-1,0},{0,1},{0,-1}};

#define MAXN 502
string grid[MAXN];

int id[MAXN][MAXN];
int seen[MAXN][MAXN], seen_now;

int pieces, w, b, n, m;

void flood(int i, int j) {
    if (grid[i][j] == 'W') w++;
    else b++;
    seen[i][j] = seen_now;
    REP(dir,4) {
        int ni = i + ds[dir][0];
        int nj = j + ds[dir][1];
        if (0 <= ni && ni < n && 0 <= nj && nj < m) {
            if (grid[ni][nj] == '.') continue;
            if (seen[ni][nj] == seen_now) continue;
            flood(ni,nj);
        }
    }    
}

#define MAXNN 1000100

vector< int > low, lbl, comp;
vector< bool > stkd;

vector< vector<int> > gr;

stack< int > scc;
int dfsnum, ccomp;

map< pair<int,int>, int > vars;
int val(int x) { return (2*x); }
int neg(int x) { return (2*x + 1); }

int getvar(int a, int b) {
    if (a > b) swap(a,b);
    if (vars.count(MP(a,b))) return vars[MP(a,b)];
    int sz = SIZE(vars);
    gr.PB( vector<int>() );
    gr.PB( vector<int>() );
    vars[MP(a,b)] = sz;
    return sz;
}

void add_true(int x) {
    gr[neg(x)].PB(val(x));
}

void add_xor(int x, int y) {
    gr[val(x)].PB(neg(y));
    gr[val(y)].PB(neg(x));
    gr[neg(x)].PB(val(y));
    gr[neg(y)].PB(val(x));
}

void add_nor(int x, int y) {
    gr[val(x)].PB(neg(y));
    gr[val(y)].PB(neg(x));
}

int N;

void dfs(int u) {
    lbl[u] = low[u] = dfsnum++;
    scc.push(u);
    stkd[u] = true;
    int v;
    REP(i, SIZE(gr[u])) {
        v = gr[u][i];
        if (lbl[v] == -1) dfs(v);
        if (stkd[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == lbl[u]) {
        while (!scc.empty() && scc.top() != u) {
            comp[ scc.top() ] = ccomp;
            stkd[ scc.top() ] = false;
            scc.pop();
        }
        scc.pop();
        stkd[u] = false;
        comp[u] = ccomp++;
    }
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        REP(i,n) cin >> grid[i];
        
        pieces = 0;
        w = 0, b = 0;
        REP(i,n) REP(j,m) if(grid[i][j] != '.') {
            id[i][j] = pieces++;
            if(grid[i][j] == 'B') b++;
            else w++;
        }
        
        bool ok = false;
        if (2*b == w) {
            
            seen_now++;
            REP(i,n) REP(j,m) if (grid[i][j] != '.') {
                if(seen[i][j] != seen_now) {
                    w = 0, b = 0;
                    flood(i,j);
                    if (2*b != w) goto hell;
                }
            }
            vars.clear();
            gr.clear();
            
            REP(i,n) REP(j,m) if (grid[i][j] == 'B') {
                vector<int> ud, lr;
                REP(dir,2) {
                    int ni = i + ds[dir][0];
                    int nj = j + ds[dir][1];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m)
                        if (grid[ni][nj] == 'W') ud.PB( getvar(id[i][j],id[ni][nj]) );
                }
                
                FOR(dir,2,3) {
                    int ni = i + ds[dir][0];
                    int nj = j + ds[dir][1];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m)
                        if (grid[ni][nj] == 'W') lr.PB( getvar(id[i][j],id[ni][nj]) );
                } 
                if (!SIZE(ud) || !SIZE(lr)) goto hell;
                
                if (SIZE(ud) == 1) add_true(ud[0]);
                else add_xor(ud[0],ud[1]);
                
                if (SIZE(lr) == 1) add_true(lr[0]);
                else add_xor(lr[0],lr[1]);
            }
            
            REP(i,n) REP(j,m) if (grid[i][j] == 'W') {
                vector<int> ng;
                REP(dir,4) {
                    int ni = i + ds[dir][0];
                    int nj = j + ds[dir][1];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m)
                        if (grid[ni][nj] == 'B') ng.PB( getvar(id[i][j],id[ni][nj]) );
                }
                
                switch (SIZE(ng)) {
                    case 0: goto hell;
                    case 1: add_true(ng[0]); break;
                    default: 
                        REP(i,SIZE(ng)) FOR(j,i+1,SIZE(ng)-1)
                            add_nor(ng[i],ng[j]);
                }                
            }

            N = SIZE(gr);
            low.assign(N,-1);
            lbl.assign(N,-1);
            stkd.assign(N,false);
            comp.resize(N);
            
            dfsnum = 0; ccomp = 0;

            REP(i,N) if (lbl[i] == -1) dfs(i);
            
            for(int i = 0; i < N; i += 2) if (comp[i] == comp[i+1])
                goto hell;
            
            ok = true;
        }
    hell:
        if (ok) cout << "YES\n";
        else cout << "NO\n";
        
    }
    
    return 0;
}
















