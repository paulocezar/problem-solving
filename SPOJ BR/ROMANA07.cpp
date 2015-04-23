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

struct edge_t{
    int u, v, c;
    edge_t(int uu = 0, int vv = 0, int cc = 0) : u(uu), v(vv), c(cc) {}
    bool operator < (const edge_t& e) const {
        if (c != e.c) return c < e.c;
        if (u != e.u) return u < e.u;
        return v < e.v;
    }
};

int ways[128], pa[256], rk[256];

int find(int x) {
    int ax, px = x;
    while (px != pa[px]) px = pa[px];
    while (x != px) {
        ax = pa[x];
        pa[x] = px;
        x = ax;
    }
    return px;
}

bool fUnion(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return false;
    if (rk[px] < rk[py]) swap(px,py);
    pa[py] = px;
    if (rk[px] == rk[py]) rk[px]++;
    return true;
}

int main(int argc, char* argv[]) {
    
    ios::sync_with_stdio(false);
    
    int N, P, E;
    cin >> N >> P >> E;
    
    ways[0] = 1;
    REP(i,P) {
        int a; cin >> a;
        REP(len,101) if (len >= a)
            ways[len] += ways[len-a];
    }    
    
    vector<edge_t> edge;
    REP(i,E) {
        int u, v, c;
        cin >> u >> v >> c;
        if (ways[c]) edge.PB(edge_t(u,v,ways[c]));
    }
    
    FOR(i,1,N) pa[i] = i, rk[i] = 0;
    sort(ALL(edge));
    int used = 0;
    int ans = 0;
    
    REP(i, SIZE(edge)) {
        if (fUnion(edge[i].u,edge[i].v)) 
            ans += edge[i].c, used++;
    }
    
    if (used != N-1) cout << "-1\n";
    else cout << ans << "\n";
    
    return 0;
}
















