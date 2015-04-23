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

const double pi = acos(-1.0);
const double pre = 1000.0;


double A, B, best, res;

void doit(double lo, double hi) {
    
    while (hi-lo > EPS) {        
        double m1 = (2.0*lo + hi)/3.0;
        double m2 = (lo + 2.0*hi)/3.0;
        double f1 = A*sin(m1) + B*cos(m1);
        double f2 = A*sin(m2) + B*cos(m2);
        
        if (CMP(f1, f2) == -1) lo = m1;
        else hi = m2;
    }
    
    double cur = A*sin(lo) + B*cos(lo);
    
    if (CMP(cur, best) == 1) {
        best = cur;
        res = lo;
    } else if (CMP(cur,best) == 0) {
        res = min(res, lo);
    }
    
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cout << fixed << setprecision(2);
    
    cin >> t;
    while (t--) {
        cin >> A >> B;
        
        best = A*sin(0.0) + B*cos(0.0);
        res = 0.0;
        
        doit(0, pi * .5);
        doit(pi * .5, pi);
        doit(pi, 1.5 * pi);
        doit(1.5 * pi, 2.0 * pi);
        
        cout << res << " " << best << '\n';
    }
    	 
	return 0;
}

















