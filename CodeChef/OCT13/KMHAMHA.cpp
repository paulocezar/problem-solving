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

#define MAXN 1024

int N, M;
vector< int > gr[MAXN];
bool seen[MAXN];		
int m[MAXN], m1[MAXN]; 

int dfs(int u) {
	if (u < 0) return 1;
	if (seen[u]) return 0;
	seen[u] = true;
	for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
		if (dfs(m1[ gr[u][i] ])) {
			m[u] = gr[u][i];
			m1[ gr[u][i] ] = u;
			return 1;
		}
	}
	return 0;
}

int dfsExp(int u) {
	for (int i = 0; i < N; ++i) seen[i] = false;
	return dfs(u);
}


int bipMatch() {
	for (int i = 0; i < N; ++i) m[i] = -1;
	for (int i = 0; i < M; ++i) m1[i] = -1;
	int aug, ans = 0;
	do {
		aug = 0;
		bool first = true;
		for (int i = 0; i < N; ++i) if (m[i] < 0) {
			if (first) aug += dfsExp(i);
			else aug += dfs(i);
			first = false;
		}
		ans += aug;
	} while (aug);
	return ans;
}

int x[MAXN], y[MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int enemies;
        cin >> enemies;
        
        map<int, int> hashx, hashy;
        N = 0, M = 0;
        REP(i, enemies) {
            cin >> x[i] >> y[i];
            if (!hashx.count(x[i])) hashx[x[i]] = N++;
            if (!hashy.count(y[i])) hashy[y[i]] = M++;
        }
        
        REP(i, N) gr[i].clear();
        REP(i, enemies) {
            gr[hashx[x[i]]].push_back(hashy[y[i]]);
        }
        
        cout << bipMatch() << "\n";
    }
        
        
	return 0;
}

















