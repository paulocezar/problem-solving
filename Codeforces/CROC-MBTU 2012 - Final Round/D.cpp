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

#define MAXN 100100

double la[MAXN], ya[MAXN], yb[MAXN], lb[MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m;
    double a, b;
    
    cin >> n >> m >> a >> b;
    
    REP(i, n) {
        cin >> ya[i];
        la[i] = sqrt(a*a + (ya[i]*ya[i]));
    }
    
    REP(i, m) cin >> yb[i];
    REP(i, m) cin >> lb[i];
    
    double res = 2e55;
    int ia, ib;
    
    REP(j, m) {
        int lo = 0, hi = n-1, ans;
        
        while (lo <= hi) {
            int len = (hi-lo+1);
            
            if (len == 1) { ans = lo; break; }
                
            if (len == 2) {
                double f1 = la[lo] + sqrt((b-a)*(b-a) + (ya[lo]-yb[j])*(ya[lo]-yb[j]));
                double f2 = la[hi] + sqrt((b-a)*(b-a) + (ya[hi]-yb[j])*(ya[hi]-yb[j]));
                if (f1 < f2) ans = lo;
                else ans = hi;
                break;
            }
            
            int p = len/3;
            
            int m1 = lo + p - 1;
            int m2 = hi - p + 1;
            
            double f1 = la[m1] + sqrt((b-a)*(b-a) + (ya[m1]-yb[j])*(ya[m1]-yb[j]));
            double f2 = la[m2] + sqrt((b-a)*(b-a) + (ya[m2]-yb[j])*(ya[m2]-yb[j]));
            if (f1 < f2) {
                ans = m1;
                hi = m2-1;
            } else if (f1 > f2) {
                ans = m2;
                lo = m1+1;
            } else {
                ans = m1;
                lo = m1+1;
                hi = m2-1;   
            }
        }
        
        double ff = la[ans] + sqrt((b-a)*(b-a) + (ya[ans]-yb[j])*(ya[ans]-yb[j])) + lb[j];
        if (ff < res) {
            res = ff;
            ia = ans+1;
            ib = j+1;
        }  
        
    }
    
    cout << ia << " " << ib << "\n";
	 
	return 0;
}

















