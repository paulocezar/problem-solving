/*
ID: knightp2
PROG: wifi
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

#define MAXN 2048
int64 x[MAXN], A, B;

bool calc[MAXN];
int64 dp[MAXN];

int64 solve(int to) {
    if (to == -1) return 0;
    if (calc[to]) return dp[to];
    calc[to] = true;
    int64 &res = dp[to];
    res = int64(1e15);
    
    RFOR(from, to, 0) {
        int64 cur = solve(from-1) + A + B*(x[to]-x[from]);
        if (cur < res) res = cur;
    }
        
    return res;
}

int main(int argc, char* argv[]) {
    freopen("wifi.in", "r", stdin);
    freopen("wifi.out", "w", stdout);
    
    int N;
    cin >> N >> A >> B;
    A = 2LL*A;
    
    REP(i, N) cin >> x[i];
    sort(x, x+N);
        
    int64 res = solve(N-1);
    if (res & 1LL) cout << (res>>1) << ".5\n";
    else cout << (res>>1) << "\n";
    
	return 0;
}

















