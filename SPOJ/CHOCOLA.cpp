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



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    while (t--) {
        int m, n;
        cin >> m >> n;
        
        int vv, hh;
        priority_queue<int> v, h;
        REP(i, m-1) {
            cin >> vv;
            v.push(vv);
        }
        REP(i, n-1) {
            cin >> hh;
            h.push(hh);
        }
        
        int res = 0;
        int v_cuts = 0, h_cuts = 0;
        
        while (!v.empty() || !h.empty()) {
            
            vv = hh = -1;
            if (!v.empty()) vv = v.top();
            if (!h.empty()) hh = h.top();
            
            if (vv > hh) {
                v.pop();
                v_cuts++;
                res += vv*(h_cuts+1);
            } else {
                h.pop();
                h_cuts++;
                res += hh*(v_cuts+1);
            }
        }
        cout << res << "\n";
    }
	 
	return 0;
}

















