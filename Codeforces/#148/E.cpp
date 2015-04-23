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

#define MAXN 3001

vector< pair<int,int> > gr[MAXN];

int depth[MAXN], parent[MAXN], treesz[MAXN];
int chain[MAXN], chainleader[MAXN], cost[MAXN], costdwn[MAXN];

int cur_chain;

void explore(int u) {
	int v;
	treesz[u] = 1;
    costdwn[u] = cost[u];
	for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
		v = gr[u][i].first;
		if (parent[ v ] == -1) {
			parent[ v ] = u;
			depth[ v ] = depth[ u ]+1;
            cost[ v ] = cost[u] + gr[u][i].second;
			explore(v);
            costdwn[ u ] += costdwn[v] - cost[u];
			treesz[ u ] += treesz[ v ];
		}
	}
}

void decompose(int u, bool light = true) {
	if (light) {
		++cur_chain;
		chainleader[ cur_chain ] = u;
	}
	
	chain[ u ] = cur_chain;
	
	int v, ind = -1, mx = -1;
	for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
		v = gr[u][i].first;
        if (parent[ v ] == u && (mx == -1 || treesz[mx] < treesz[v]))
			mx = v, ind = i;
	}
	
	if (mx != -1) {
		decompose(mx, false);
	}
	
	for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
		v = gr[u][i].first;
        if (parent[ v ] == u && v != mx) {
			decompose( v );
		}
	}		
}

int lca(int u, int v) {    
    while (chain[u] != chain[v]) {
		if (depth[ chainleader[chain[u]] ] < depth[ chainleader[chain[v]] ])
            v = parent[ chainleader[ chain[v] ] ];
        else
            u = parent[ chainleader[ chain[u] ] ];
    }
    if (depth[u] < depth[v]) return u;
	return v;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
    int n;
    cin >> n;
    
    REP(i,n-1) {
        int a, b;
        cin >> a >> b;
        gr[a].PB(MP(b,0));
        gr[b].PB(MP(a,1));
    }
    
    FOR(i,1,n) parent[i] = -1;
    parent[1] = 0;
    depth[0] = 0;
    cost[0] = 0;
    explore(1);
    cur_chain = -1;
    decompose(1); parent[1] = 1;
    
    int res = costdwn[1];
    
    FOR(i,2,n) {
        int inv = depth[i] - cost[i];
        int cdw = costdwn[i] - cost[i];
        int ocdw = costdwn[1] - costdwn[i];
        res = min(res, inv + cdw + ocdw);
    }
    
    
    FOR(s,1,n) {
        FOR(ss,s+1,n) {
            
            int lc = lca(s,ss);
            
            int cdw = costdwn[s] - cost[s];
            cdw += costdwn[ss] - cost[ss];
            if (lc == s) {
                cdw -= (costdwn[ss]-cost[ss]);
                cdw -= min(depth[ss]-cost[ss]-(depth[lc]-cost[lc]),cost[ss]-cost[lc]);
            }
            if (lc == ss) {
                cdw -= (costdwn[s]-cost[s]);
                cdw -= max(depth[s]-cost[s]-(depth[lc]-cost[lc]),cost[s]-cost[lc]);
            }
            
            int inv = (depth[s]-cost[s]) + (depth[ss]-cost[ss]) - (depth[lc]-cost[lc]);
            if (lc == s || lc == ss) inv = (depth[lc]-cost[lc]);
            
            int ocdw = costdwn[1] - costdwn[lc];
            
            cout << s << " " << ss << ' ' << lc << " - ";
            cout << inv << ' ' << cdw << ' ' << ocdw << endl;

            res = min(res, inv + cdw + ocdw);
        }
    }   
    
    cout << res << "\n";
    
	
	return 0;
}

















