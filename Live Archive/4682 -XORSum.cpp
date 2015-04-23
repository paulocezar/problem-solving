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

struct node_t {
    node_t* chld[2];
    node_t() { chld[0] = chld[1] = NULL; }
};

void add(node_t *cur, int64 val) {
    RREP(bit,31) {
        int go = (val >> bit) & 1;
        if (cur->chld[go] == NULL) cur->chld[go] = new node_t();
        cur = cur->chld[go];
    }    
}

int getmax(node_t *cur, int64 val) {
    int res = 0;
    
    RREP(bit,31) {
        int go = (val >> bit) & 1;
        if (cur->chld[!go] != NULL) {
            res |= (1<<bit);
            cur = cur->chld[!go];
        } else {
            cur = cur->chld[go];    
        }
    }
    
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        node_t *btrie = new node_t();
        
        add(btrie, 0);
        int a, xr = 0;
        int res = 0;
        
        REP(i, n) {
            cin >> a;
            xr ^= a;
            
            res = max(res, getmax(btrie, xr));
            add(btrie, xr);
        }
        
        cout << res << "\n";
    }
    
	 
	return 0;
}

















