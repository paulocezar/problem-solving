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

/*inline int next_int() {
	int n = 0, neg = 1;
	char c = getchar_unlocked();
	if( c == EOF ) exit(0);
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = -1;
		c = getchar_unlocked();
		if( c == EOF ) exit(0);
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return neg*n;
}*/

#define MAXN 6666
#define MAXD 5

const int64 mod = 747474747LL;

int64 dist[MAXN];
int64 pt[MAXN][MAXD];

bool done[MAXN];


int N, D;
void prim() {
    
    int u = 0, nu = -1; int64 wg;
    
    REP(v, N) {
        done[v] = false;
        dist[v] = 0LL;
        REP(j, D) dist[v] += (pt[u][j]-pt[v][j]) * (pt[u][j]-pt[v][j]);
        if ((nu == -1) || (dist[v] >= wg)) {
            wg = dist[v];
            nu = v;
        } 
    }
    done[0] = true;
    
    REP(stp,N-1) {
        u = nu;
        nu = -1;
        done[u] = true;
        REP (v, N) {
            if (done[v]) continue;
            int64 nwg = 0LL;
            REP(i,D) nwg += (pt[u][i]-pt[v][i]) * (pt[u][i]-pt[v][i]);
            if (nwg > dist[v]) dist[v] = nwg;
            if ((nu == -1) || (dist[v] >= wg)) {
                wg = dist[v];
                nu = v;
            }
        }
    }
    
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> D;
        
        REP(i, N) REP(j, D)
            cin >> pt[i][j];
        
        prim();
        
        dist[0] = 1LL;
        int64 res = 1LL;
        REP(i,N) res = (res * (max(1LL,dist[i])%mod))%mod;
        cout << res << "\n";
    }
    
	return 0;
}

















