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
    
    int pr[5], ir[5];
    
    int par = 0, impar = 0;
    
    REP(i, 15) {
        int x; cin >> x;
        
        if (x & 1) ir[impar++] = x;
        else pr[par++] = x;
        
        if (par == 5 && i+1 != 15)
            REP(j, 5) cout << "par[" << j << "] = " << pr[j] << "\n";
        
        if (impar == 5 && i+1 != 15)
            REP(j, 5) cout << "impar[" << j << "] = " << ir[j] << "\n";
        par %= 5; impar %= 5;    
    }
	
    REP(j, impar) cout << "impar[" << j << "] = " << ir[j] << "\n";
    REP(j, par) cout << "par[" << j << "] = " << pr[j] << "\n"; 
    
	return 0;
}

















