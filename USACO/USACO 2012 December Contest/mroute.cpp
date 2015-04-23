/*
ID: knightp2
PROG: mroute
LANG: C++
*/
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
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = a.begin(); i != a.end(); i++)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR(const T &a) { return a*a; }
template<typename T> T inline ABS(const T &a) { return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN(double a){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP(double a, double b){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 512

struct edge_t {
    int v, l, c;
    edge_t(int vv = 0, int ll = 0, int cc = 0) : v(vv), l(ll), c(cc) {}
};

vector< edge_t > gr[MAXN];

int lat[MAXN];
int cap[MAXN];

int main(int argc, char* argv[]) {
    freopen("mroute.in", "r", stdin);
    freopen("mroute.out", "w", stdout);
    
    int N, M, X;
    cin >> N >> M >> X;
    
    set<int> seen;
    vector<int> cand;
    
    int res = int(2e9);
    
    REP(i, M) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (seen.insert(d).second) cand.PB(d);
        if (a == b) {
            if (1 == N) res = min(res, c + X/d);
            continue;
        }
        gr[a].PB(edge_t(b,c,d));
        gr[b].PB(edge_t(a,c,d));
    }
    
    if (N != 1) REP(ic, SIZE(cand)) {
        int minCap = cand[ic];
        
        FOR(i,1,N) { lat[i] = int(2e9); cap[i] = -1; }
                
        lat[1] = 0;
        cap[1] = int(2e9);
        
        priority_queue< pair<int, pair<int,int> > > q;
        q.push(MP(0,MP(int(2e9), 1)));
        
        while (!q.empty()) {
            
            int u = q.top().second.second;
            int C = q.top().second.first;
            int L = -q.top().first; q.pop();
            
            if (L > lat[u]) continue;
            if (C < cap[u]) continue;
            
            if (u == N) break;
            
            REP(i, SIZE(gr[u])) {
                if (gr[u][i].c < minCap) continue;
                int v = gr[u][i].v;
                if ((L + gr[u][i].l < lat[v]) ||
                    ((L + gr[u][i].l == lat[v]) && (min(cap[u], gr[u][i].c) > cap[v]))) {
                        cap[v] = min(cap[u], gr[u][i].c);
                        lat[v] = L + gr[u][i].l;
                        q.push(MP(-lat[v],MP(cap[v],v)));
                    }
            }   
        }
        
        if (lat[N] != int(2e9)) res = min(res, lat[N] + X/cap[N]);
    }
    
    cout << res << "\n";
        
	return 0;
}

















