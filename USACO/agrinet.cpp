/*
ID: knightp2
PROG: agrinet
LANG: C++
*/
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
#include <fstream>
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
int pa[MAXN], rk[MAXN];

int find(int x) {
    int ax, px = x;
    while (px != pa[px]) px = pa[px];
    while (x != px) {
        ax = pa[px];
        pa[x] = px;
        x = ax;
    }
    return px;
}

bool fUnion(int px, int py) {
    px = find(px);
    py = find(py);
    if (px == py) return false;
    if (rk[px] < rk[py]) swap(px,py);
    pa[py] = px;
    if (rk[px] == rk[py]) rk[px]++;
    return true;
}

struct edge_t {
    int u, v, c;
    explicit edge_t(int uu = 0, int vv = 0, int cc = 0) : u(uu), v(vv), c(cc) {}
    bool operator < (const edge_t &e) const {
        return c < e.c;
    }
};

int main(int argc, char* argv[]) {
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");	
    
    int N;
    fin >> N;
    
    vector< edge_t > edge;
    FOR(u,1,N) FOR(v,1,N) {
        int c;
        fin >> c;
        if (v > u) edge.PB(edge_t(u,v,c));
    }
    sort(ALL(edge));
    
    FOR(i,1,N) pa[i] = i, rk[i] = 0;
    
    int ans = 0;
    REP(i,SIZE(edge)) {
        if (fUnion(edge[i].u,edge[i].v)) ans += edge[i].c;
    }
    fout << ans << "\n";
    
        
        
	return 0;
}

















