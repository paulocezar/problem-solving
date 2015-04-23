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
#include <tr1/unordered_set>

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

tr1::unordered_set<int> seen;

int a[55];

vector<int> val;
vector<int64> els;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    
    int n, k;
    cin >> n >> k;
    
    REP(i, n) cin >> a[i];
    
    sort(a,a+n);
    
    tr1::unordered_set<int> seen;
    
    REP(i, n) {
        seen.insert(a[i]);
        val.PB(a[i]);
        els.PB(1LL<<i);
    }
    
    REP(i, n) {
        if (SIZE(val) >= k) break;
        int nn = SIZE(val);
        REP(j, nn) {
            if (els[j] & (1LL<<i)) continue;
            if (seen.count(val[j]+a[i])) continue;
            val.PB(val[j]+a[i]);
            els.PB(els[j]|(1LL<<i));
            seen.insert(val[j]+a[i]);
        }
    }
    
    REP(day, k) {
        vector<int> res;
        REP(i, n) if (els[day] & (1LL<<i)) res.PB(a[i]);
        cout << SIZE(res);
        REP(i, SIZE(res)) cout << " " << res[i];
        cout << "\n";
    }
        
    
    
	 
	return 0;
}

















