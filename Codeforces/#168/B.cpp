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
int64 val[MAXN];

vector<int> gr[MAXN];
bitset< MAXN+10 > seen;

pair<int64, int64> solve(int u) {
    int64 inc = 0LL, dec = 0LL;
    seen[u] = true;
    REP(i, SIZE(gr[u])) {
        if (!seen[gr[u][i]]) {
            pair<int64,int64> r = solve(gr[u][i]);
            if (r.first > inc) inc = r.first;
            if (r.second > dec) dec = r.second;
        }
    }
    val[u] += inc;
    val[u] -= dec;
    if (val[u] < 0LL) inc -= val[u];
    if (val[u] > 0LL) dec += val[u];
    return MP(inc,dec);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    REP(i, n-1) {
        int u, v;
        cin  >> u >> v; u--, v--;
        gr[u].PB(v);
        gr[v].PB(u);
    }
    REP(i, n) cin >> val[i];
    seen.reset();
    pair<int64, int64> res = solve(0);
    cout << (res.first + res.second) << "\n";

    return 0;
}

















