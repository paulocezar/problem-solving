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

#define MLEN (1<<6)

int64 ax[MLEN][MLEN];
int64 res[MLEN][MLEN];
int64 pot[MLEN][MLEN];

const int64 mod = (1e9 + 7);
int len;

void mult(int64 a[][MLEN], int64 b[][MLEN]) {
    REP(i,len) {
        REP(j, len) {
            ax[i][j] = 0;
            REP(k,len) {
                ax[i][j] += ((a[i][k]*b[k][j])%mod);
                if (ax[i][j] >= mod) ax[i][j] -= mod;
            } 
        }
    }
    REP(i,len) REP(j, len)
        a[i][j] = ax[i][j];
} 

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
    int a;
    int64 b;
    
    cin >> a >> b;
    len = 1<<a;
    
    REP(i,len) REP(j,len) {
        res[i][j] = ((i==j) ? 1 : 0);
        
        pot[i][j] = 1;
        
        FOR(pos,1,a-1) {
            int a = (i>>pos) & 1;
            int b = (j>>pos) & 1;
            if (a == b) {
                int c = (i>>(pos-1)) & 1;
                int d = (j>>(pos-1)) & 1;    
                if (c == d && c == a) {
                    pot[i][j] = 0;
                    break;
                }
            }
        }
    }
    
    b--;
    while (b > 0LL) {
        if (b&1) mult(res,pot);
        mult(pot,pot);
        b >>= 1;
    }
    
    int64 ans = 0;
    REP(i,len) REP(j,len) {
        ans += res[i][j];
        if (ans >= mod) ans -= mod;
    }
    cout << ans << "\n";
	
	return 0;
}

















