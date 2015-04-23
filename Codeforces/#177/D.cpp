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

#define MAXN 80808

vector<int> gr[MAXN];
int treesz[MAXN];

int64 res;
int n;

void doit(int u, int pa = -1) {
    
    treesz[u] = 1;
    
    REP(i, SIZE(gr[u])) {
        if (gr[u][i] == pa) continue;
        doit(gr[u][i],u);
        treesz[u] += treesz[gr[u][i]];
    }
    
    int64 outthere = n - treesz[u];
    int64 pairs = (outthere * (outthere - 1LL)) / 2LL;
     
    REP(i, SIZE(gr[u])) {
        if (gr[u][i] == pa) continue;
        int64 rem = treesz[u] - treesz[gr[u][i]];
        int64 prem = (rem * treesz[gr[u][i]]);
        res += prem * pairs;
    }
    
    
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    cin >> n;
    REP(i, n-1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        gr[u].PB(v);
        gr[v].PB(u);
    }

    res = 0LL;
    doit(0);
    cout << (2LL * res) << "\n";

    
	return 0;
}

















