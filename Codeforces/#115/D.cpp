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

#define MAXEV 200

char ev[MAXEV];

int l1, r1, l2, r2;
double p1, q1, p2, q2;

//char calc[201][201][MAXEV];
double dp[2][201][201];


/*double solve( int hp1, int hp2, int pos ){
	
	if( hp2 <= 0 ) return 1.0;
	if( hp1 <= 0 ) return 0.0;
	
	if( pos == MAXEV ) return 0.0;
	
	if( calc[hp1][hp2][pos] ) return dp[hp1][hp2][pos];
	calc[hp1][hp2][pos] = 1;
	double &ret = dp[hp1][hp2][pos];
	
	if( ev[pos] == 0 ){
		
		ret = p1*solve(hp1,hp2,pos+1);	
		FOR( dmg, l1, r1 )
			ret += q1*solve(hp1,hp2-dmg,pos+1 );
			
	} else {
		
		ret = p2*solve(hp1,hp2,pos+1 );
		FOR( dmg, l2, r2 )
			ret += q2*solve(hp1-dmg,hp2,pos+1 );
			
	}
	return ret;
	
}*/

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int hp1, dt1, hp2, dt2;
	
	cin >> hp1 >> dt1 >> l1 >> r1 >> p1; 
	cin >> hp2 >> dt2 >> l2 >> r2 >> p2;

	p1 /= 100.0;
	p2 /= 100.0;

	q1 = (1.0-p1)*(1.0/(r1-l1+1.0));
	q2 = (1.0-p2)*(1.0/(r2-l2+1.0));
	

	int mmc = (dt1/__gcd(dt1,dt2))*dt2;
	
	int sz = 0;
	for( int i = 0; i < mmc && sz < MAXEV; i++ ){
		if( i%dt1 == 0 ) ev[sz++] = 0;
		if( i%dt2 == 0 ) ev[sz++] = 1;
	}
	
	int x = 0;
	while( sz < MAXEV ) ev[sz++] = ev[x++];
	
	
	int old = 0, cur = 1;
	
	RREP( pos, MAXEV+1 ){
		
		
		FOR( h1, 0, hp1 ) FOR( h2, 0, hp2 ){
			
			double &ret = dp[cur][h1][h2];
			
			if( h2 == 0 ) ret = 1.0;
			else if( h1 == 0 ) ret = 0.0;
			else if( pos == MAXEV ) ret = 0.0;
			else if( ev[pos] == 0 ){
				
				ret = p1*dp[old][h1][h2];

				FOR( dmg, l1, r1 )
					ret += q1*((h2>=dmg)?dp[old][h1][h2-dmg]:1.0);
				
			} else {
				
				ret = p2*dp[old][h1][h2];
				FOR( dmg, l2, r2 )
					ret += q2*((h1>=dmg)?dp[old][h1-dmg][h2]:(h2?0.0:1.0));	
			}
			
		}
		old = !old;
		cur = !cur;
		
	}
	
	
	cout << dp[old][hp1][hp2] << "\n";

		
	return 0;
}

























