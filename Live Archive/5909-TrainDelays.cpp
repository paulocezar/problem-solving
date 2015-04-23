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


double best[2048][64];

#define MAXTRAINS 1024
int u[MAXTRAINS], v[MAXTRAINS], dt[MAXTRAINS], dur[MAXTRAINS], pr[MAXTRAINS], dl[MAXTRAINS];

map<string, int> id;

int getid(string &s) {
    if (id.count(s)) return id[s];
    int sz = SIZE(id);
    REP(i,60) { best[sz][i] = ((sz == 1) ? (0.0) : (1e18)); }
    id[s] = sz;
    return sz;
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int t;
    cin >> t;
    while (t--) {
        string from, to;
        cin >> from >> to;
        
        id.clear();
        getid(from);
        getid(to);
        
        int m;
        cin >> m;
        REP(i, m) {
            cin >> from >> to >> dt[i] >> dur[i] >> pr[i] >> dl[i];
            u[i] = getid(from);
            v[i] = getid(to);
        }
        
        bool change;
        double p, q, pd, expected;
        
        do {
            change = false;
            
            REP(i,m) {
                p = pr[i]/100.0;
                q = 1.0 - p;
                pd = p / dl[i];
                
                expected = q * (best[ v[i] ][ (dt[i]+dur[i])%60 ] + dur[i]);
                FOR(d,1,dl[i]) expected += (pd * (best[ v[i] ][ (dt[i]+dur[i]+d)%60 ] + dur[i] + d));
                
                if (expected < 1e-10*1e18 && expected+1e-10 < best[ u[i] ][ dt[i] ]) {
                    best[ u[i] ][ dt[i] ] = expected;
                    change = true;
                    
                    REP(wt,60) {
                        if (expected + ((60-wt+dt[i]) % 60) < best[ u[i] ][ wt ]) {
                            best[ u[i] ][ wt ] = expected + ((60-wt+dt[i]) % 60);
                        }
                    }                    
                }                
            }
            
        } while (change);
        
        double ans = 1e18;
        REP(i,60) ans = min(ans,best[0][i]);
        
        if (ans == 1e18) cout << "IMPOSSIBLE" << "\n";
        else cout << setprecision(10) << ans << "\n";
        
    }
    
    return 0;
}
















