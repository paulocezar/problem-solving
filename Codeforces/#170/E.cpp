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

#define MAXN 512

int x[MAXN], y[MAXN];
vector< pair<int,double> > gr[MAXN];
double dist[MAXN];
int indeg[MAXN];
int pa[MAXN];

inline int cost(int &i, int &j) {
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    REP(i, n) cin >> x[i] >> y[i];
    
    REP(i, n) REP(j, n) {
        if (i == j) continue;
        if (y[i] > y[j]) {
            gr[i].PB(MP(j,cost(i,j))), indeg[j]++;
        }
    }

    int cand = 0;
    int who;
    REP(i, n) if (!indeg[i]) who = i, cand++;
    bool ok = true;
    if (cand != 1) {
        REP(i, n) pa[i] = -1, dist[i] = 2e60;
        dist[who] = 0.0;
        pa[who] = who;

        bool change;
        do {
            change = false;
            
            REP(i, n) REP(j, SIZE(gr[i])) {
                int v = gr[i][j].first;
                if ((dist[i]+gr[i][j].second-dist[v]) < 1e-9) {
                    pa[v] = i;
                    dist[v] = dist[i]+gr[i][j];
                    change = true;
                }
            }

        } while (change);
        double res = 0.0;
        REP(i, n) {
            if (pa[i] == -1) ok = false;
            else res += dist[i] - dist[pa[i]]; 
        }
    } else ok = false;

	return 0;
}

















