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

#define MAXN 100000
int c4[MAXN+1], c7[MAXN+1];
int e4[MAXN+1], e7[MAXN+1];

int main(int argc, char* argv[]) {
	
    c4[0] = 0, c7[0] = 0;
    e4[0] = 1, e7[0] = 1;
    
    int t = next_int();
    while (t--) {
        int n = next_int();
        
        FOR(i, 1, n) {
            int a = next_int();
            
            c4[i] = c4[i-1], c7[i] = c7[i-1];
            
            while (a > 0) {
                int dig = a%10;
                if (dig == 4) c4[i]++;
                else if (dig == 7) c7[i]++;
                a /= 10;
            }
            
            if (c4[i] == c4[i-1]) e4[i] = e4[i-1] + 1;
            else e4[i] = 1;
            
            if (c7[i] == c7[i-1]) e7[i] = e7[i-1] + 1;
            else e7[i] = 1;   
        }
        
        int64 res = 0;
        int cc4, cc7;
        
        FOR(r,1,n) {
            int l = r;
            while (true) {
                while ((c4[r]-c4[l-1] == 2) || (c7[r]-c7[l-1] == 2)) {
                    if (c4[r]-c4[l-1] == 2) {
                        l -= e4[l-1];
                    } 
                    if (!l) break;
                    if (c7[r]-c7[l-1] == 2) {
                        l -= e7[l-1];
                    }
                    if (!l) break;
                }
                
                if (!l) break;
                
                cc4 = c4[r]-c4[l-1];
                cc7 = c7[r]-c7[l-1];
                
                if (cc4 && cc7) {
                    if (cc4 == 1) res++;
                    else {
                        int ax = floor(log(r-l+1)/log(cc4));
                        if (ax >= cc7) {
                            
                            res++;
                        }
                    }
                } else res++;
                
                
                
                
                if (!l) break;
            }
        }
        printf("%lld\n", res);
        
    }
    
	 
	return 0;
}

















