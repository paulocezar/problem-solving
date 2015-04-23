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

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int xi[100000], xf[100000];

int next_int() {
    int res = 0, sig = 1;
    char c = getchar_unlocked();
    while (!isdigit(c) && (c != '-')) c = getchar_unlocked();
    if (c == '-') {
        sig = -1;
        c = getchar_unlocked();
    }
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    return (sig * res);
}

int main( int argc, char* argv[] ){
    
    int N, C, ya, yb;
    N = next_int();
    C = next_int();
    
    REP(i,N) {
        xi[i] = next_int();
        ya = next_int();
        xf[i] = next_int();
        yb = next_int();
        if (xi[i] > xf[i]) swap(xi[i],xf[i]);
    }
    
    sort(xi,xi+N);
    sort(xf,xf+N);
    
    int from, to;
    REP(i,C) {
        from = next_int();
        to = next_int();
        int af = lower_bound(xi,xi+N,from) - xi;
        int bf = (xf+N) - upper_bound(xf,xf+N,to);
        printf("%d\n", af+bf);
    }
    
    
    
    
    return 0;
}
















