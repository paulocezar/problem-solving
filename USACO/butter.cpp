/*
ID: knightp2
PROG: butter
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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int dist[801], at[501];
vector< pair<int,int> > gr[801];

int main(int argc, char* argv[]) {
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    
    int N, P, C;
    cin >> N >> P >> C;
    FOR(i, 1, N) cin >> at[i];

    while (C--) {
        int a, b, c;
        cin >> a >> b >> c;
        gr[a].PB(MP(b,c));
        gr[b].PB(MP(a,c));
    }
    
    int cost = 1e9;
    FOR(k,1,P) {
        
        FOR(i,1,P) dist[i] = 2e9;
        dist[k] = 0;
        priority_queue< pair<int,int> > q;
        q.push(MP(0,k));
        while (!q.empty()) {
            int cst = -q.top().first;
            int u = q.top().second; q.pop();
            if (cst > dist[u]) continue;
            REP(i,SIZE(gr[u])) {
                int v = gr[u][i].first;
                int nc = cst + gr[u][i].second;
                if (nc < dist[v]) {
                    dist[v] = nc;
                    q.push(MP(-nc,v));
                }
            }
        }
        int cur = 0;
        FOR(i,1,N) cur += dist[at[i]];
        cost = min(cost, cur);
    }
    cout << cost << "\n";

        
	return 0;
}

















