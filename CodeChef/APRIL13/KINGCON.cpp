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
#include <tr1/unordered_map>
#include <tr1/unordered_set>

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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 3333

int N;

vector< int > gr[ MAXN ];
int low[MAXN], lbl[MAXN], parent[MAXN];
int dfsnum;
int rchild;	// child count of the root 
int root;	// root of the tree 
int arts;	// # of critical vertexes
bool art[MAXN];

void dfs(int u) {
	lbl[u] = low[u] = dfsnum++;
	for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
		int v = gr[u][i];
		if (lbl[v] == -1) {
			parent[v] = u;
			if (u == root) rchild++;
			dfs(v);
			if ((u != root) && (low[v] >= lbl[u]) && (!art[u]))
                art[u] = true, arts++;
			low[u] = min(low[u], low[v]);
		} else if (v != parent[u]) low[u] = min(low[u], lbl[v]);
	}
	if ((u == root) && (rchild > 1))
        art[u] = true, arts++;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int M, K;
        cin >> N >> M >> K;
        REP(i,N) {
            gr[i].clear();
            lbl[i] = -1;
            art[i] = false;
            parent[i] = -1;
        }
        
        int a, b;
        while (M--) {
            cin >> a >> b;
            gr[a].PB(b);
            gr[b].PB(a);
        }
        rchild = 0;
        root = 0;
        arts = 0;
        dfsnum = 0;
        dfs(0);
        cout << arts*K << "\n";
    }
    
	return 0;
}

















