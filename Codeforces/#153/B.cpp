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

#define MAXN 128
int q[MAXN], s[MAXN], p[MAXN], aux[MAXN];


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, k;
    cin >> N >> k;
    FOR(i, 1, N) cin >> q[i];
    FOR(i, 1, N) cin >> s[i];
    
    FOR(i, 1, N) p[i] = i;
    
    bool eq = true;
    FOR(i, 1, N) if (s[i] != p[i]) eq = false;
    
    if (eq) {
        cout << "NO\n"; return 0;
    }
    
    int norm = 0, inv = 0;
    
    REP(step, k+1) {
        
        eq = true;
        FOR(i, 1, N) if (p[i] != s[i]) eq = false;
        
        if (eq) { norm = step; break; }
        if (step == k) break;
        
        FOR(i, 1, N)
            aux[ i ] = p[ q[i] ];
        FOR(i, 1, N) p[i] = aux[i];
    }
    
    FOR(i, 1, N) p[i] = i;
    
    REP(step, k+1) {
        
        eq = true;
        FOR(i, 1, N) if (p[i] != s[i]) eq = false;
        
        if (eq) { inv = step; break; }
        if (step == k) break;
        
        FOR(i, 1, N)
            aux[ q[i] ] = p[ i ];
        FOR(i, 1, N) p[i] = aux[i];
    }
    
    bool ok = false;
    // if (norm % 2 == k % 2 || inv % 2 == k % 2) cout << "YES\n";
    // else cout << "NO\n";
    
    if (norm || inv) {
        
        if (norm == k || inv == k) ok = true;
        
        if (norm) {
            if (((k-norm) % 2) == 0) {
                
                int gg = (norm-1);
                if (inv) gg += inv-1;
                else gg++;
                
                if (gg) ok = true;
            }
        }

        if (inv) {
            if (((k-inv) % 2) == 0) {
                
                int gg = (inv-1);
                if (norm) gg += norm-1;
                else gg++;
                
                if (gg) ok = true;
            }
        }
    }
    
    if (ok) cout << "YES\n";
    else cout << "NO\n";
     
	return 0;
}














