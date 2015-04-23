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

#define MAXN 100000

int pa[MAXN], sz[MAXN];

int find(int x) {
    int ax, px = x;
    while (pa[px] != px) px = pa[px];
    while (x != px) {
        ax = pa[x];
        pa[x] = px;
        x = ax;
    }
    return px;
}

bool fUnion(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x,y);
    pa[y] = x;
    sz[x] += sz[y];
    return true;
}

const int64 mod = 1000000007LL;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        REP(i, N) pa[i] = i, sz[i] = 1;
        
        int routes = N;
        while (M--) {
            int u, v;
            cin >> u >> v; u--, v--;
            if (fUnion(u,v)) routes--;
        }

        int64 ways = 1LL;
        REP(i, N) if (pa[i] == i) {
            ways = ways * int64(sz[i]);
            if (ways >= mod) ways %= mod;
        }
        cout << routes << " " << ways << "\n";
    }
    
    
	return 0;
}

















