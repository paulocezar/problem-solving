/*
ID: knightp2
PROG: crazy
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

struct point_t {
    int x, y;
    bool operator < (const point_t &p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
};

#define MAXN 1024

map< point_t, int > id;
point_t di[2*MAXN];

point_t cow[MAXN];

int comp[2*MAXN], ncomp;

vector<int> gr[2*MAXN];

vector< vector<int> > poly;

void go(int u) {
    comp[u] = ncomp+1;
    poly[ncomp].PB(u);
    
    REP(i, SIZE(gr[u])) if (!comp[gr[u][i]]) go(gr[u][i]);
}

bool inpoly(vector<int> &pl, point_t &pt) {
  double px = pt.x, py = pt.y;
  int i, j, c = false;
  
  for (i = 0, j = SIZE(pl)-1; i < SIZE(pl); j = i++) {
      double vix = di[pl[i]].x, viy = di[pl[i]].y, vjx = di[pl[j]].x, vjy = di[pl[j]].y;
      if (((viy>py) != (vjy>py)) && (px < (vjx-vix) * (py-viy) / (vjy-viy) + vix)) c = !c;
  }
  
  return c;
}

int main(int argc, char* argv[]) {
    freopen("crazy.in", "r", stdin);
    freopen("crazy.out", "w", stdout);
    
    int N, C;
    cin >> N >> C;
    
    int NN = 0;
    REP(i, N) {
        point_t pu, pv;
        cin >> pu.x >> pu.y >> pv.x >> pv.y;
        if (!id.count(pu)) { id[pu] = NN; di[NN] = pu; NN++; }
        if (!id.count(pv)) { id[pv] = NN; di[NN] = pv; NN++; }
        
        int u = id[pu];
        int v = id[pv];
        gr[u].PB(v);
        gr[v].PB(u);
    }
    
    REP(i, C) cin >> cow[i].x >> cow[i].y;
    
    ncomp = 0;
    REP(i, NN) if (!comp[i]) {
        poly.PB(vector<int>());
        go(i);
        ncomp++;
    }
     
    vector<int> pgr[ncomp];
    vector<int> dgr(ncomp, 0);
    
    REP(i, ncomp) REP(j, ncomp) if (i != j) {
        if (inpoly(poly[i], di[poly[j][0]])) {
            pgr[j].PB(i);
            dgr[i]++;
        }    
    }
    
    queue<int> q;
    REP(i, ncomp) if  (dgr[i] == 0) q.push(i);
    
    int res = 0;
    
    while (!q.empty()) {
        int pl = q.front(); q.pop();
        
        int cur = 0;
        int inside = 0;
        while (cur < C) {
            if (inpoly(poly[pl], cow[cur])) {
                inside++;
                swap(cow[cur], cow[C-1]); C--;
            } else cur++;
        }
        res = max(res, inside);
        
        REP(i, SIZE(pgr[pl])) {
            int v = pgr[pl][i];
            dgr[v]--;
            if (dgr[v] == 0) q.push(v);
        }
    }
    
    res = max(res, C);
    cout << res << "\n";
    
       
	return 0;
}

















