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

const int64 mod = 1000000007LL;

int mx;
int64 fat[2*400000+1];
int64 ifat[2*400000+1];

int64 finv(int64 a) {
    int64 res = 1LL;
    int b = 1000000005;
    
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int64 solve(int n, int m) {   
    while (mx < n+m) {
        mx++;
        fat[mx] = (int64(mx) * fat[mx-1]) % mod;
        ifat[mx] = finv(fat[mx]);
    }
    
    return ((((fat[n+m] * ifat[n])%mod) * ifat[m]) % mod);
}

int main(int argc, char* argv[]) {
	
	mx = 0;
    fat[0] = 1;
    ifat[0] = 1;
    
    int R, N, M, A, B;
    int64 y, z, res;
    
    scanf("%d", &R);
    while (R--) {
        scanf("%d%d%d%d", &N, &M, &A, &B);
        
        res = 0;
        
        for (int i = 0; B+i <= M; ++i) {
            y = solve(B+i, N-A);
            z = solve(M-B-i, A-1);
            
            res = (res + ((y*z)%mod)) % mod;
        }
        
        printf("%d\n", int(res));
    }
    
	 
	return 0;
}

















