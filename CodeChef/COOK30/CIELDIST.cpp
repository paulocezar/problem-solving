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
    
   int t, ds, dt, d;
   cin >> t;
   while (t--) {    
       cin >> ds >> dt >> d;
       int ax = 0, ar = ds;
       int bx = d, br = dt;
       if (ar > br) swap(ar,br);
       
       double res = -1.0;
       
       if (d >  (ds+dt)) {
           res = fabs((ax+ar) - (bx-br));
       } else if((bx-br) < (ax-ar)) {
           res = fabs((bx-br) - (ax-ar));
       } else {
           res = 0.0;
       }

       cout << fixed << setprecision(13) << res << "\n";

   }
	 
	return 0;
}

















