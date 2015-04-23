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
#include <tr1/unordered_map>
#include <tr1/unordered_set>

/*
    although it was probably not needed, using gmp for arbitrary precision..
    http://gmplib.org/
 */
#include <gmpxx.h>

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

mpz_class r;
mpz_class needed(mpz_class rings) {
    return (2*rings*rings + 2*r*rings - rings);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
        
    int kases;
    cin >> kases;
    
    FOR(kase,1,kases) {
        
        mpz_class t;
        cin >> r >> t;
        
        mpz_class ans = 0;
        mpz_class lo = 1, hi = 2e9;
        
        while (lo <= hi) {
            mpz_class mid = (lo + hi) / 2;
            
            if (needed(mid) <= t) {
                ans = mid;
                lo = mid+1;
            } else hi = mid-1;
        }
        cout << "Case #" << kase << ": " << ans << "\n";
    }
    
    
	return 0;
}

















