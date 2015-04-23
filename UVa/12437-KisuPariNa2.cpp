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

#define MAXN 10010
vector<int> gr[MAXN];

int seen[MAXN], seen_now;

int deepest, ddepth, tree_sz;

void go(int u, int depth, bool truly = false) {
    if (depth > ddepth) {
        ddepth = depth;
        deepest = u;
    }
    seen[u] = seen_now;
    tree_sz++;
    
   REP(i, SIZE(gr[u])) if (seen[gr[u][i]] != seen_now) {
       go(gr[u][i], depth+1, truly);
   }
  
   if (!truly) {
       seen[u] = seen_now-1; 
       tree_sz--;
   }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    FOR(kase, 1, t) {
        int n, m;
        cin >> n >> m;
        
        FOR(i, 1, n) gr[i].clear();
        
        while (m--) {
            int u, v;
            cin >> u >> v;
            gr[u].PB(v);
            gr[v].PB(u);
        }
        
        seen_now++;
        vector< pair<int,int> > trees;
        FOR(i, 1, n) if (seen[i] != seen_now) {
            ddepth = -1;
            tree_sz = 0;
            go(i, 0);
            ddepth = -1;
            go(deepest, 0, true);
            trees.PB(MP(tree_sz, ddepth));
        }
        
        int q;
        cout << "Case " << kase << ":\n";
        cin >> q;
        while (q--) {
            int k; cin >> k;
            
            int res = 2e9;
            REP(i, SIZE(trees)) {
                if (trees[i].first >= k) {
                    int seen = trees[i].second+1;
                    int cost = min(seen-1, k-1);
                    if (seen < k) cost += 2*(k-seen);
                    res = min(res, cost);
                }
            }
            
            if (res == 2e9) cout << "impossible\n";
            else cout << res << "\n";
        }
        
    }
    
	 
	return 0;
}














