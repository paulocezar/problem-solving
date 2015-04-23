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

#define MAXN 21
#define LINF 200000000LL

int64 w[MAXN];

int mn[MAXN];
int mx[MAXN];

int S, N;


int calc[MAXN][101], calc_now;
int64 dp[MAXN][101];


int64 solve(int pos, int rem) {
    if (pos == N) return ((rem == 0) ? (0LL) : (-LINF));
    
    int64 &res = dp[pos][rem];
    if (calc[pos][rem] == calc_now) return res;
    calc[pos][rem] = calc_now;
    res = -LINF;
    
    for (int wg = mn[pos]; wg <= mx[pos]; ++wg) {
        if (rem >= wg) {
            res = max(res, (int64(wg) * w[pos]) + solve(pos+1,rem-wg));
        }
    }
    
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
    while (cin >> S >> N && (S || N)) {
      
      REP(i,N) w[i] = 0;
      REP(j,S) {
          REP(i,N) {
             int x; cin >> x;
             w[i] += x;
          } 
      }
      
      REP(i,N) cin >> mn[i] >> mx[i];
      
      calc_now++;
      
      int64 maxsum = max(0LL, solve(0, 100));
      int64 med =  int64((double(maxsum) / double(S)) + .5);
      cout << (med/100) << "." << setw(2) << setfill('0') << (med % 100LL) << "\n";    
    }
	
	return 0;
}

















