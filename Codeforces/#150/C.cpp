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

#define MAXN 100000

int n, a[MAXN];
int nxt[MAXN];

void brute() {
    set<int> seen;
    
    REP(i, n) {
        
        seen.insert(a[i]);
        
        int cur = a[i];
        int j = i+1;
        
        while (j < n) {
            cur |= a[j]; j++;
            seen.insert(cur);
        }
        
    }
    
    cout << SIZE(seen) << "\n";
}

void solve() {
    set<int> seen;
    
    REP(i,n) {
        
        int cur = a[i];
        int j = i+1;
        int add = 0;
        
        while (true) {
            if (seen.count(cur)) {
                break;
            }
            
            nxt[add] = cur; add++;
            if (j < n) {
                cur |= a[j];
                j++;
            } else break;
        }
        
        j = 0;
        while (j < add) {
            seen.insert(nxt[j]);
            j++;
        }
    }
    
    cout << SIZE(seen) << "\n";
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    cin >> n;
    REP(i,n) cin >> a[i];
    solve();
	 
	return 0;
}

















