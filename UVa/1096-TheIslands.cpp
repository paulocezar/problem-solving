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

#define PB push_back
#define MP make_pair

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 111
int calc[4][MAXN][MAXN], calc_now;
double dp[4][MAXN][MAXN];
double dist[MAXN][MAXN];
int x[MAXN], y[MAXN];

int n, b1, b2;

double solve( int put, int xx, int yy ){
	
	int now = max(xx,yy)+1;
	if( now == n-1 ) return dist[xx][now]+dist[yy][now];
	
	double &res = dp[put][xx][yy];
	if( calc[put][xx][yy] == calc_now ) return res;
	calc[put][xx][yy] = calc_now;
	res = 2e9;

// put: 0 ~  none, 1 ~ at xx, 2 ~ at yy	

	if( now == b1 || now == b2 ){
		
		if( put == 1 ) res = dist[yy][now] + solve(3,xx,now);
		else if( put == 2 ) res = dist[xx][now] + solve(3,now,yy);
		else res = min( dist[xx][now]+solve(1,now,yy), dist[yy][now] + solve(2,xx,now) );
		
	} else res = min( dist[xx][now]+solve(put,now,yy), dist[yy][now] + solve(put,xx,now) );
	
	
	return res;
	
}

vector< int > fwd, bwd;
void build( int put, int xx, int yy ){
	
	int now = max(xx,yy)+1;
	if( now == n-1 ){ fwd.PB(now); return; }
	
	double &res = dp[put][xx][yy];
	
	if( now == b1 || now == b2 ){
		
		if( put == 1 ){
			bwd.PB(now);
			build(3,xx,now);
		} else if( put == 2 ){
			fwd.PB( now );
			build(3,now,yy);
		} else if( res == (dist[xx][now]+solve(1,now,yy)) ){
			fwd.PB( now );
			build(1,now,yy);
		} else {
			bwd.PB( now );
			build(2,xx,now);
		}
		
	} else if( res == (dist[xx][now]+solve(put,now,yy)) ){
		fwd.PB(now);
		build(put,now,yy);
	} else {
		bwd.PB(now);
		build(put,xx,now);
	}
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int tc = 1;
	while( (cin >> n >> b1 >> b2) && (n||b1||b2) ){
		
		for( int i = 0; i < n; i++ )
			cin >> x[i] >> y[i];
		
		for( int i = 0; i < n; i++ ) for( int j = i; j < n; j++ )
			dist[i][j] = dist[j][i] = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );

		calc_now++;
		cout << "Case " << tc++ << ": " << fixed << setprecision(2) << solve(0,0,0) << "\n";
		fwd.clear();
		bwd.clear();
		
		build(0,0,0);
		cout << "0";
		for( size_t i = 0, sz = fwd.size(); i < sz; i++ )
			cout << " " << fwd[i];
		for( size_t i = bwd.size(); i > 0; i-- )
			cout << " " << bwd[i-1];
		cout << " 0\n";
	}
	
	return 0;
}

























