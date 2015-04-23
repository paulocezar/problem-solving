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

int next_int() {
    int res = 0;
    char c = getchar_unlocked();
    while (!isdigit(c)) c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    return res;
}

char get_wut() {
    char c = getchar_unlocked();
    while (c != 'E' && c != 'P') c = getchar_unlocked();
    return c;
}

#define MAXN 1001

struct edge_t {
    int v, c, t;
    edge_t(int vv = 0, int cc = 0, int tt = 0) : v(vv), c(cc), t(tt) {}
};

int tcost[MAXN], ttime[MAXN], stops[MAXN];
vector< edge_t > gr[MAXN];

struct state_t {
    int u, cst, ttm, stp;
    state_t(int uu = 0, int cc = 0, int tt = 0, int ss = 0) : u(uu), cst(cc), ttm(tt), stp(ss) {}
};

char wut;

class comp {
public:
    bool operator() (const state_t &a, const state_t &b) const {
        if (wut == 'P'){
            if (a.cst != b.cst) return a.cst > b.cst;
            if (a.ttm != b.ttm) return a.ttm > b.ttm;
        } else {
            if (a.ttm != b.ttm) return a.ttm > b.ttm;
            if (a.cst != b.cst) return a.cst > b.cst;
        }
        if (a.stp != b.stp) return a.stp > b.stp;
        return a.u < b.u;        
    }    
};


int main( int argc, char* argv[] ){
    
    int N, F;

    N = next_int();
    F = next_int();
    wut = get_wut();
    
    int from = next_int();
    int to = next_int();
    int u, v, c, t;
    
    while (F--) {
        u = next_int();
        v = next_int();
        c = next_int();
        t = next_int();
        gr[u].PB(edge_t(v,c,t));
    }
    

    FOR(x,1,N) tcost[x] = INF, ttime[x] = INF, stops[x] = INF;
    priority_queue< state_t, vector<state_t>, comp > q;
    
    tcost[from] = 0;
    ttime[from] = 0;
    stops[from] = 0;
    
    q.push(state_t(from,0,0,0));
    while (!q.empty()) {
        u = q.top().u;
        c = q.top().cst;
        t = q.top().ttm;
        int s = q.top().stp; q.pop();
        
        if (c > tcost[u]) continue;
        if (t > ttime[u]) continue;    
        if (s > stops[u]) continue;

        if (u == to) {
            cout << c << " " << t << " " << (s-1) << "\n";
            return 0;
        }
        
        REP(i,SIZE(gr[u])) {
            v = gr[u][i].v;
            int nc = c + gr[u][i].c;
            int nt = t + gr[u][i].t;
            int ns = s + 1;
            
            bool best = false;
            switch(wut) {
                case 'P':
                if ((nc < tcost[v])
                    || (nc == tcost[v] && nt < ttime[v])
                    || (nc == tcost[v] && nt == ttime[v] && ns < stops[v])
                    ) best = true;
                break;
                case 'E':
                if ((nt < ttime[v])
                    || (nt == ttime[v] && nc < tcost[v])
                    || (nc == tcost[v] && nt == ttime[v] && ns < stops[v])
                    ) best = true;
                break;
            }
            
            if (best) {
                tcost[v] = nc;
                ttime[v] = nt;
                stops[v] = ns;
                q.push(state_t(v,nc,nt,ns));            
            }
        }
        
    }
    cout << "-1\n";
    
    return 0;
}
















