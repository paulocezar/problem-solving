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
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector< int64 > lucky;

void build( int64 now ){
	if( now > 1000000000LL ) return;
	lucky.PB( 10LL*now + 4LL );
		build( 10LL*now + 4LL );
	lucky.PB( 10LL*now + 7LL );
		build( 10LL*now + 7LL );
}

double prob( double a, double b, double c, double d ){
	return (min(d,b)-max(c,a)+1)/(d-c+1);
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	build( 0 ); sort( ALL(lucky) );
	
	int64 pl, pr, vl, vr, k;
	cin >> pl >> pr >> vl >> vr >> k;
	
	double ans = 0.0;
	for( int i = 0; i+k-1 < SIZE(lucky); i++ ){
		
		int64 lo = lucky[i];
		int64 hi = lucky[i+k-1];
				
		int64 alo, ahi;
		
		if( i ) alo = lucky[i-1]+1;
		else alo = 1;	
		
		if( i+k < SIZE(lucky) ) ahi = lucky[i+k]-1;
		else ahi = 1000000000;
		
		double p1, p2;
		p1 = 0.0;
		p2 = 0.0;
		
		//cout << alo << " " << lo << endl;
		//cout << hi << " " << ahi << endl;
		
		if( (pl <= alo && alo <= pr) || (alo <= pl && pl <= lo) )
			p1 = prob( alo, lo, pl, pr );
			
		if( (vl <= hi && hi <= vr) || (hi <= vl && vl <= ahi) )
			p2 = prob( hi, ahi, vl, vr );
	
		//cout << p1 << " - " << p2 << endl;
		ans += p1*p2;
		
		p1 = 0.0;
		p2 = 0.0;
		
		if( (vl <= alo && alo <= vr) || (alo <= vl && vl <= lo) )
			p1 = prob( alo, lo, vl, vr );
		
		if( (pl <= hi && hi <= pr) || (hi <= pl && pl <= ahi) )
			p2 = prob( hi, ahi, pl, pr );
		//cout << p1 << " - " << p2 << endl;
		ans += p1*p2;
		if( k == 1 && pl <= lucky[i] && lucky[i] <= pr && vl <= lucky[i] && lucky[i] <= vr )
			ans -= prob(lucky[i],lucky[i],pl,pr)*prob(lucky[i],lucky[i],vl,vr);
		
	}
	
	cout << fixed << setprecision(20) << ans << "\n";
	
	return 0;
}




















