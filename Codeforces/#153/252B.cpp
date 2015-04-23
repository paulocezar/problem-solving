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

#define MAXN 100000
int a[MAXN];

bitset< MAXN > _inc, _dec;
bitset< MAXN > _incr, _decr;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n; cin >> n;
    REP(i, n) cin >> a[i];
	
    _inc[0] = true;
    _dec[0] = true;
    FOR(i, 1, n-1) {
        _inc[i] = (_inc[i-1] && (a[i-1] <= a[i]));
        _dec[i] = (_dec[i-1] && (a[i-1] >= a[i]));
    }
    
    _incr[n-1] = true;
    _decr[n-1] = true;
    RFOR(i, n-2, 0) {
        _incr[i] = (_incr[i+1] && (a[i] <= a[i+1]));
        _decr[i] = (_decr[i+1] && (a[i] >= a[i+1]));
    }
    
    int ii = -1, jj = -1;
    
    REP(i, n-2) {
        REP(x, 3) REP(y, 3) {
            if (a[i+x] != a[i+y]) {
                swap(a[i+x], a[i+y]);
                
                bool iin = (a[i] <= a[i+1]) && (a[i+1] <= a[i+2]);
                bool din = (a[i] >= a[i+1]) && (a[i+1] >= a[i+2]);
                
                if (!iin && !din) {
                    ii = i+x+1, jj = i+y+1;
                    goto hell;
                }
                
                bool bin = i ? (_inc[i-1] && (a[i-1] <= a[i])) : true;
                bool bdc = i ? (_dec[i-1] && (a[i-1] >= a[i])) : true;
                
                bool ain = ((i+3) < n) ? (_incr[i+3] && a[i+2] <= a[i+3]) : true;
                bool adc = ((i+3) < n) ? (_decr[i+3] && a[i+2] >= a[i+3]) : true;
                
                bool _incrsin = bin && iin && ain;
                bool _decrsin = bdc && din && adc;
                
                if (!_incrsin && !_decrsin) {
                    ii = i+x+1;
                    jj = i+y+1;
                    goto hell;
                }
                
                swap(a[i+x], a[i+y]);
            }
        }
    } 
    
hell:     
    cout << ii;
    if (ii != -1) cout << " " << jj;
    cout << "\n";
    
	return 0;
}

















