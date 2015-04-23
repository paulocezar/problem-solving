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
#include <tr1/unordered_map>
#include <tr1/unordered_set>


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
tr1::unordered_map< int, int > calc[MAXN];

string name[MAXN];
vector<int> gr[MAXN];

int get(int u, int k) {
    
    if (calc[u].count(k)) return calc[u][k];
    if (k == 0) return 0;
    
    int res = 0;
    
    tr1::unordered_set<string> d1;
    REP(i, SIZE(gr[u])) {
        int v = gr[u][i];
        d1.insert(name[v]);
        
        if (k) res += get(v, k-1);
    }
    if (k == 1) res += SIZE(d1);
    //calc[u][1] = SIZE(d1);
    
    calc[u][k] = res;
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int root, pa;
    
    REP(i, n) {
        cin >> name[i] >> pa;
        pa--;
        if (pa == -1) root = i;
        else gr[pa].PB(i);
    }
    
    int m;
    cin >> m;
    while (m--) {
        int u, k;
        cin >> u >> k; u--;
        cout << get(u, k) << "\n";
    }
	 
	return 0;
}

















