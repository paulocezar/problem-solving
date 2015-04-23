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

inline int next_int() {
    int res = 0;
    char c = getchar_unlocked();
    while (!isdigit(c)) c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    return res;
}

#define MAXN 200000
int x[MAXN], y[MAXN];

int main(int argc, char* argv[]) {
	
    int n, R1, R2, q, d1, d2, inA, inB, ax, ay, bx, by, tc = 1;
    n = next_int();
    
    while (n) {
        REP(i,n) {
            x[i] = next_int();
            y[i] = next_int();
        }
    
        ax = next_int();
        ay = next_int();
        bx = next_int();
        by = next_int();
        q = next_int();
        
        REP(i,n) {
            d1 = (ax-x[i])*(ax-x[i]) + (ay-y[i])*(ay-y[i]);
            d2 = (bx-x[i])*(bx-x[i]) + (by-y[i])*(by-y[i]);
            
            x[i] = d1;
            y[i] = d2;
        }
        
        sort(x,x+n);
        sort(y,y+n);
        
        printf("Case %d:\n", tc);
        REP(qq,q) {
            R1 = next_int();
            R2 = next_int();
            R1 *= R1;
            R2 *= R2;
            
            inA = upper_bound(x,x+n,R1) - x;
            inB = upper_bound(y,y+n,R2) - y;
            
            printf("%d\n", max(0, n-inA-inB));
        }
        
        tc++;
        n = next_int();
    }
    
	 
	return 0;
}

















