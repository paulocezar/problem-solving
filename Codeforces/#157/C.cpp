#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <deque>
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

#define MAXN 100000
int64 a[MAXN];

const int64 mod = 1000000007LL;

int64 fpw(int64 b, int e) {
    int64 res = 1LL;
    while (e > 0) {
        if (e & 1) { res *= b; res %= mod; }
        b *= b; b %= mod;
        e >>= 1;
    }
    return res;
}

int64 q[1010]; int qpt;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    REP(i, n) cin >> a[i];
    sort(a, a+n);
    
    int64 mx = 1LL;
    int64 res = 0LL;
    
    while (mx <= a[n-1]) {
        
        qpt = 0;
        for (int64 i = 1LL; i*i <= mx; ++i) {
            if (mx % i) continue;
            q[qpt++] = i;
            if (i*i != mx) q[qpt++] = (mx/i);
        }
        sort(q, q+qpt);
        
        int64 cur = 1LL;
        
        int cnt = 0, xx = 0, pos = 0;
        while (true) {
            
            while ((xx < qpt) && (q[xx] <= a[pos])) { xx++; cnt++; }
            
            if (xx == qpt) {
                if ((cnt != 1) && ((n-pos) != 1)) {
                    
                    int64 ww = fpw(cnt-1, n-pos);
                    int64 wg = fpw(2LL, n-pos) - 1LL;
                    if (wg < 0LL) wg += mod;
                    
                    cur *= ((wg * ww)%mod);
                    cur %= mod;
                }
                break;  
            } else {
                pos++;
                cur *= int64(cnt);
                cur %= mod;
            }
        }
        
        res += cur;
        if (res >= mod) res -= mod;
        mx++;
    }
    
    cout << res << "\n";
    
	return 0;
}

















