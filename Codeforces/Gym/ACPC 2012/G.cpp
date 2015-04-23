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



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    const double pi = acos(-1.0);

    int n;
    cin >> n;
    double res = 0.0;
    
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        double a1 = atan2(y1, x1);
        double a2 = atan2(y2, x2);
        if (a1 < 1e-8) a1 += 2.0*pi;
        if (a2 < 1e-8) a2 += 2.0*pi;
        
        a1 = (180.0*a1)/pi;
        a2 = (180.0*a2)/pi;
        if (fabs(360-a1) < 1e-8) a1 = 0;
        if (fabs(360-a2) < 1e-8) a2 = 0;
        res += min(360.0-fabs(a1-a2), fabs(a1-a2)) / 360.0; 
    }


    cout << fixed << setprecision(13);
    cout << res << "\n";
	 
	return 0;
}

















