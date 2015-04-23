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

int fpw(int64 a, int64 b) {
    int64 res = 1LL;
    while (b > 0LL) {
        if (b & 1LL) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }    
    return res;
}

//int calc[5002][5002], calc_now;
int dp[5002][5002];

int n0, n1;
int fat[5002], inv[5002];
    
/*
int64 solve(int rem0, int rem1) {
    
    if (mem.count(MP(rem0,rem1))) return mem[MP(rem0,rem1)];
    
    int64 res = 0;
    
    if (rem0) {
        rem0--;
        if ((n0-rem0-1) == rem1) {
            int64 xx = fat[rem0+rem1] * inv[rem0]; xx %= mod;
            xx *= inv[rem1];
            xx %= mod;
            res += xx;
            res %= mod;
        } else {
            res += solve(rem0,rem1);
            res %= mod;
        }
        rem0++;
    }
    
    if (rem1) {
        rem1--;
        if ((n0-rem0) == rem1) {
            int64 xx = fat[rem0+rem1] * inv[rem0]; xx %= mod;
            xx *= inv[rem1];
            xx %= mod;
            res += xx;    
            res %= mod;
        } else {
            res += solve(rem0,rem1);
            res %= mod;
        }
        rem1++;
    }
    
    return (mem[MP(rem0,rem1)] = res);    
}
*/    
    
int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
    fat[0] = 1;
    inv[0] = 1;
    
    FOR(i,1,5000) {
        fat[i] = ((int64(i) * int64(fat[i-1])) % mod);
        inv[i] = fpw(fat[i],mod-2);
    }
    
	int t;
    cin >> t;
    while (t--) {
        
        string s;
        cin >> s;
        
        n0 = 0, n1 = 0;
        REP(i,SIZE(s)) if (s[i] == '4') n0++;
        else n1++;
        
        FOR(rem0,0,n0) FOR(rem1,0,n1) {
            int &res = dp[rem0][rem1];
            res = 0;
                
            if (rem0) {
                rem0--;
                if ((n0-rem0-1) == rem1) {
                    int xx = (int64(fat[rem0+rem1]) * int64(inv[rem0])) % mod;
                    xx = (int64(xx) * int64(inv[rem1])) % mod;
                    res += xx;
                } else {
                    res += dp[rem0][rem1];
                }
                rem0++;
            }
    
            if (rem1) {
                rem1--;
                if ((n0-rem0) == rem1) {
                    int xx = (int64(fat[rem0+rem1]) * int64(inv[rem0])) % mod;
                    xx = (int64(xx) * int64(inv[rem1])) % mod;
                    res += xx;
                    if (res >= mod) res -= mod;
                } else {
                    res += dp[rem0][rem1];
                    if (res >= mod) res -= mod;
                }
                rem1++;
            }
        }
        
        cout << dp[n0][n1] << "\n";
    }
	
	return 0;
}

















