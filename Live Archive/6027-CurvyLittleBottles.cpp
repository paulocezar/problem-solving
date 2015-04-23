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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int n;
long double b[16], a[32];

long double f(long double x) {
    long double res = 0.0;
    long double xn = x;
    FOR(i,0,n) {
        res += a[i] * xn;
        xn *= x;
    }
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    const long double pi = acos(-1.0);

    int kase = 1;
    while (cin >> n) {
        FOR(i,0,n) cin >> b[i];
        
        long double xlo, xhi, inc;
        cin >> xlo >> xhi >> inc;
        
        FOR(i,0,2*n) a[i] = 0.0;
        FOR(i,0,n) FOR(j,0,n)
            a[i+j] += b[i]*b[j];
        n = 2*n;
        FOR(i,0,n) a[i] /= (i+1);        

        long double fxlo = f(xlo);
        long double vol = pi * (f(xhi) - fxlo);
        
        cout << "Case " << kase++ << ": " << vol << "\n";
        
        vector<long double> marks;
        
        FOR(mark,1,8) {
            long double nextmark = mark * inc;
            long double lo = xlo, hi = xhi;
            REP(step,128) {
                long double mid = .5*(lo+hi);
                long double cvol = pi*(f(mid) - fxlo);
                if (cvol < nextmark) lo = mid;
                else hi = mid;
            }
            long double cvol = pi*(f(lo) - fxlo);
            if (cvol+1e-6 < nextmark) break;
            marks.PB(lo-xlo);
        }
        
        if (!marks.empty()) {
            REP(i, SIZE(marks)) {
                if (i) cout << " ";
                cout << marks[i];
            }
            cout << "\n";
        } else cout << "insufficient volume\n";
    }
	 
	return 0;
}

















