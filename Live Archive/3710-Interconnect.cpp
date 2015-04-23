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

int pa[32], rk[32], tcnt[32];
int find(int x) {
    int ax, px = x;
    while (px != pa[px]) px = pa[px];
    while (x != px) {
        ax = pa[x];
        pa[x] = px;
        x = ax;
    }
    return px;
}

void fUnion(int px, int py) {
    px = find(px);
    py = find(py);
    if (px == py) return;
    if (rk[px] < rk[py]) swap(px,py);
    pa[py] = px;
    if (rk[px] == rk[py]) rk[px]++;
    tcnt[px] += tcnt[py];
}

map< vector<int>, double > memo;

int all;
double solve(vector<int> comp) {
    if (memo.count(comp)) return memo[comp];
    
    int n = SIZE(comp);
    
    int stay = 0;
    REP(i,n) stay += (comp[i] * (comp[i]-1)) / 2;
    
    vector<int> nw(n-1);
    
    double res = 0.0;
    REP(i,n) FOR(j,i+1,n-1) {
        
        int nxt = 0;
        int ncomp = comp[i] + comp[j];
        
        REP(x,n) if(x != i && x != j) {
            if (ncomp < comp[x]) {
                nw[nxt] = ncomp; ++nxt;
                ncomp = 2e9;
            }
            nw[nxt] = comp[x]; ++nxt;
        }
        if (ncomp != 2e9) nw[nxt] = ncomp;
        
        double merge = double(comp[i] * comp[j]) / double(all - stay);
        double suc = double(all-stay) / double(all);
        double echng = double(comp[i] * comp[j]) / (double(all) * suc * suc);
        res += echng + merge * solve(nw);
    }
    memo[comp] = res;
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
    int n, m;
	while (cin >> n >> m) {
	    REP(i,n) pa[i] = i, rk[i] = 0, tcnt[i] = 1;
        while (m--) {
            int u, v; cin >> u >> v;
            fUnion(u-1,v-1);
        }
        all = (n*(n-1))/2;
        vector<int> shit;
        REP(i,n) if (find(i) == i) shit.PB(tcnt[i]);
        sort(ALL(shit));
        //memo.clear();
        
        vector< int > base; base.PB(n);
        memo[ base ] = 0.0;
        
        cout << fixed << setprecision(10) << solve(shit) << "\n";                        
    }
    
	
	return 0;
}

















