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

double dist(pair<double,double> a, pair<double,double> b) {
  double dx = a.first-b.first;
  double dy = a.second-b.second;
  return sqrt(dx*dx + dy*dy);
}

bool used[111];
double d[111][111];
string di[111];
int ans[111], sza;

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int t;
    cin >> t;
    
    while (t--) {
      int n, m;
      cin >> n >> m;
      
      map< string, pair<double,double> > where;
      REP(i, n) {
        string a; int x, y;
        cin >> a >> x >> y;
        where[a] = MP(x,y);
        used[i] = false;
      }
      
      REP(i,n) REP(j,n)
         d[i][j] = ((i==j)?(0):(1e18));
      
      string s1, heard, s2, firing, before, s3;
      map< string, int > id;
      int N = 0;
      
      REP(i,m) {
        cin >> s1 >> heard >> s2 >> firing >> before >> s3;
        if(!id.count(s2)) {
          di[N] = s2;
          id[s2] = N++;
        }
        int u = id[s2];    
        if(!id.count(s3)) {
          di[N] = s3;
          id[s3] = N++;
        }
        int v = id[s3];
        d[u][v] = min(d[u][v], dist(where[s1],where[s3])-dist(where[s1],where[s2]));
      }
      
      REP(k,N) REP(i,N) REP(j,N)
         d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

      REP(i,N) if (d[i][i] < 0) { cout << "IMPOSSIBLE\n"; goto hell; }
     
      sza = 0;
      REP(i,N) {
          REP(u,N) if (!used[u]) {
              
              bool ok = true;
              REP(v,N) if (!used[v] && d[v][u] < 0)
                  ok = false;
              
              if (ok) {
                  if (sza != i) { sza--; break; }
                  ans[sza++] = u;
              }
                            
          }
    
          if (sza == i) { cout << "UNKNOWN\n"; goto hell; }
          used[ans[i]] = true;
      }
      
      REP(i,N) cout << di[ans[i]] << ((i+1==N) ? '\n' : ' ');
      
      hell:;
    }
    
    return 0;
}
















