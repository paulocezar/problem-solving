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

int seen[1<<20];
int64 C[(1<<20)+10];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
	int N, H;
    cin >> N >> H;
    
    int friends[N];
    
    REP(i,N) {
        friends[i] = 0;
        string ff; cin >> ff;
        REP(j,N) if (ff[j] == '1') friends[i] |= (1<<j); 
    }
    
    int t = 1;
    int init = friends[0];
    C[t] = __builtin_popcount(friends[0]);
    int p = H+1, q;
        
    while (t < H) {
        ++t;
        
        if (seen[init]) {
            p = t;
            q = seen[init];
            break;
        }
        seen[init] = t;
        
        int nxt = 0;
        
        C[t] = C[t-1];
        REP(i,N) {
            C[t] += (__builtin_popcount(friends[i]) * ((init & (1<<i)) ? 1 : 2));
            if (init & (1<<i)) nxt ^= friends[i];
        }
        
        init = nxt;
    }
    int len = p-q;
        
    if (H < p) {
        cout << C[H] << "\n";
    } else {
        
        int64 per = (H-q+1) / len;
        int rem = (H-q+1) % len;
        
        int64 res = C[q-1];
        res += (per * (C[p-1] - C[q-1]));
        if (rem) res += C[q+rem-1] - C[q-1];
        cout << res << "\n";
    }
    
	
	return 0;
}

















