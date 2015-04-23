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

int a[128];
int bb[128][128];
int b[128][128];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    REP(i, n) REP(j, n) {
        cin >> b[i][j];
	    bb[i][j] = b[i][j];
    }
    
    REP(i,n) {
        bool in = false;
        int cur = (i+1 < n) ? b[i][i+1] : 0;
        FOR(j, i+2, n-1) {
            in = true;
            cur &= b[i][j];
            b[i][j] |= b[i][j-1];
        }
        if (in) a[i] |= cur;
    }
    
    REP(i,n) {
        bool in = false;
        int cur = b[i][0];
        FOR(j, 1, i-1) {
            in = true;
            cur &= b[i][j];
            b[i][j] |= b[i][j-1];
        }
        if (in) a[i] |= cur;
    }
    
    REP(i, n) FOR(j, i+1, n) {
        a[i] |= bb[i][j];
        a[j] |= bb[i][j];
    }
    
    REP(i, n) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
    
    
    
	return 0;
}

















