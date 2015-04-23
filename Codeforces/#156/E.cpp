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

const int64 mod = 777777777LL;

int64 good[3][3];

struct node_t {
    int64 res[3][3];
    void merge(node_t &ls, node_t& rs) {
        REP(i, 3) REP(j, 3) {
            res[i][j] = 0;
            REP(ii, 3) REP(jj, 3) {
                res[i][j] += (ls.res[i][ii] * rs.res[jj][j] * good[ii][jj])%mod;
                if (res[i][j] >= mod) res[i][j] -= mod;
            }
        }
    }
};

#define MAXN 77777
#define LGMN 17

node_t segt[1<<(LGMN+1)];

void build(int node, int lo, int hi) {
    if (lo == hi) {
        REP(i, 3) REP(j, 3) segt[node].res[i][j] = (i==j)?1:0;
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        build(ls,lo, mid);
        build(rs,mid+1,hi);
        segt[node].merge(segt[ls], segt[rs]);
    }
}

int pos, val;
void updt(int node, int lo, int hi) {
    if (lo == hi) {
        if (val == -1) {
            REP(i, 3) REP(j, 3) segt[node].res[i][j] = (i==j)?1:0;
        } else {
            REP(i, 3) REP(j, 3) segt[node].res[i][j] = 0;
            segt[node].res[val][val] = 1;
        }
    } else {
        int mid = (lo+hi)>>1;
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        
        if (lo <= pos && pos <= mid) updt(ls,lo, mid);
        else updt(rs,mid+1,hi);
        
        segt[node].merge(segt[ls], segt[rs]);
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    REP(i, 3) REP(j, 3) cin >> good[i][j];
    
    build(0, 0, n-1);
    
    while(m--) {
        cin >> pos >> val; pos--, val--;
        updt(0, 0, n-1);
        int64 ans = 0;
        REP(i, 3) REP(j, 3) ans = (ans + segt[0].res[i][j])%mod;
        cout << ans << "\n";
    }
     
	return 0;
}

















