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

int mintoget[21];
int bestshot, n, ax[20], cost[20], dist[20][20];
int res, rem, with;

void gopro(int at, int seen) {
    if (with > res) res = with;
    if (mintoget[res-with] > rem) return;
    if (res == bestshot) return;
    
    REP(i,n) {
        if (seen & (1<<i)) continue;
        int use = dist[at][i] + cost[i];
        if (use > rem) continue;
        rem -= use; with++;
        gopro(i,seen | (1<<i));
        rem += use; with--;
    }
}

int main(int argc, char* argv[]) {
	
    //ios::sync_with_stdio(false);
    while (scanf("%d", &n) && n) {
        
        REP(i,n) scanf("%d", &cost[i]);
        REP(i,n) REP(j,n) scanf("%d", &dist[i][j]);
        
        REP(i,n) ax[i] = cost[i]; 
        REP(i,n+1) mintoget[i] = 421;
        
        sort(ax,ax+n);
        int now = 0;
        int acm = 0;
        while (acm <= 420) {
            mintoget[now] = acm;
            acm += ax[now];
            now++;
            if (now == n) break;
        }
        if (acm > 420) now--;
        bestshot = now;
        res = 0;
        REP(i,n) {
            if (cost[i] > 420) continue;
            with = 1;
            rem = 420-cost[i];
            gopro(i,1<<i);
        }
        printf("%d\n", res);
    }
	
	
	return 0;
}

















