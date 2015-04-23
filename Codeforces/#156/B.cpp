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

int64 gsum(int64 from, int64 to) {
    int64 res = 0;
    if (from <= to) {
        int64 n = to-from+1;
        res += ((from+to)*n)/2LL;
    }
    return res; 
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, x, y; int64 c;
    cin >> n >> x >> y >> c;
    
    int lo = 0, hi = c;
	int ans = c;
    
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        
        int64 got = 1;
        
        int64 up = min(mid, x-1);
        int64 dw = min(mid, n-x);
        int64 lf = min(mid, y-1);
        int64 rt = min(mid, n-y);
        
        
        int64 rlup = min(mid-up, int64(y-1));
        int64 rrup = min(mid-up, int64(n-y));
        int64 rldw = min(mid-dw, int64(y-1));
        int64 rrdw = min(mid-dw, int64(n-y));
        
        got += (up + dw + lf + rt);
        got += ((rlup+rrup)*up + (rldw+rrdw)*dw);
        
        got += gsum(up-lf+rlup, up-1);
        got += gsum(up-rt+rrup, up-1);
        
        got += gsum(dw-lf+rldw, dw-1);
        got += gsum(dw-rt+rrdw, dw-1);
        
        if (got >= c) {
            ans = mid;
            hi = mid-1;
        } else lo = mid+1; 
        
    }
    
    cout << ans << "\n";
     
	return 0;
}

















