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

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 100001
vector< pair<int,int> > gr[MAXN];
vector< int64 > ar[MAXN];

int64 d[MAXN];

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int n, m;
    cin >> n >> m;    
    
    int a, b, c;
    REP(i,m) {
        cin >> a >> b >> c;
        gr[a].PB(MP(b,c));
        gr[b].PB(MP(a,c));
    }
    
    FOR(i,1,n) {
        d[i] = LINF;
        int k; cin >> k;
        ar[i].resize(k);
        REP(j,k) cin >> ar[i][j];
    }
    
    priority_queue< pair<int64,int> > q;
    q.push(MP(0,1));
    d[1] = 0;
    
    while (!q.empty()) {
        int dis = -q.top().first;
        int u = q.top().second; q.pop();
        
        if (dis > d[u]) continue;
        if (u == n) break;
        
        TI(ar[u]) td = lower_bound(ALL(ar[u]), dis);
        if (td != ar[u].end()) {
            while(*td == dis) {
                dis++;
                td++;
                if(td == ar[u].end()) break;
            }
        }
        
        REP(i,SIZE(gr[u])) {
            int v = gr[u][i].first;
            int64 nd = dis + gr[u][i].second;
            if (nd < d[v]) {
                d[v] = nd;
                q.push(MP(-nd,v));
            }
        }
                                        
    }    
    if (d[n] == LINF) cout << "-1\n";
    else cout << d[n] << "\n";
    
    return 0;
}
















