#include <map> 
#include <set> 
#include <list>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int sgn(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(double a, double b) { return sgn(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 150
#define MAXP 302

int x[MAXP], y[MAXP];
int n, v, xa[MAXN], xb[MAXN], ya[MAXN], yb[MAXN];
double dist[MAXP][MAXP], d[MAXP];
vector<int> graph[MAXP];

int det(int x1, int y1, int x2, int y2, int x3, int y3) {
    return x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
}

bool intersect( int i, int j, int k ){
	int p1 = det(x[i], y[i], x[j], y[j], xa[k], ya[k]);
    int p2 = det(x[i], y[i], x[j], y[j], xb[k], yb[k]);
    int p3 = det(xa[k], ya[k], xb[k], yb[k], x[i], y[i]);
    int p4 = det(xa[k], ya[k], xb[k], yb[k], x[j], y[j]);
 
    if( p1 == 0 || p2 == 0 || p3 == 0 || p4 == 0 ) return false;
 
    int s1 = p1 / ABS(p1);
    int s2 = p2 / ABS(p2);
    int s3 = p3 / ABS(p3);
    int s4 = p4 / ABS(p4);
    return s1 != s2 && s3 != s4;
}

void solve(){
	REP( i, v ) d[i] = 2e9;
	d[0] = 0.0;
	priority_queue< pair<double,int> > q; q.push( MP(0,0) );
	while( !q.empty() ){
		double f = -q.top().first;
		int u = q.top().second; q.pop();
		if( cmp( d[u], f ) ) continue;
		if( u == 1 ) break;
		REP( i, SIZE(graph[u]) ){
			int v = graph[u][i];
			if( cmp( f+dist[u][v], d[ v ] ) == -1 ){
				d[ v ] = f + dist[u][v];
				q.push( MP(-d[v], v) );
			}
		}
	}
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> n;
	while( x[0] || y[0] || x[1] || y[1] || n ){
		
		v = 2;
		REP( i, n ){
			cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
			x[v] = xa[i]; y[v] = ya[i]; v++;
			x[v] = xb[i]; y[v] = yb[i]; v++;
		}
		
		REP( i, v ) graph[i].clear();
		REP( i, v ) FOR( j, i+1, v ){
			bool ok = true;
			REP( k, n ) if( intersect( i, j, k ) ){
				ok = false;
				break;
			}
			if( ok ){
				graph[i].PB( j );
				graph[j].PB( i );
				dist[i][j] = dist[j][i] = sqrt( SQR(x[i]-x[j]) + SQR(y[i]-y[j]) );
			}
		}
		solve();
		cout << fixed << setprecision(2) << d[1] << "\n";
		cin >> x[0] >> y[0] >> x[1] >> y[1] >> n;
	}

	return 0;
}




















