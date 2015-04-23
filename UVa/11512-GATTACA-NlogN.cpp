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

#define FILL(X, V) memset( (X), (V), sizeof((X)) )
#define TI(X) __typeof((X).begin())
#define ALL(V) (V).begin(), (V).end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N - 1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP(double a, double b) { return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1111
 
string S;
int STEP, N, SA[MAXN], RA[MAXN], LCP[3*MAXN], *CUR, *OLD;
 
bool comp( int a, int b ){
	if( OLD[a] != OLD[b] ) return OLD[a] < OLD[b];
	if( a+STEP < N && b+STEP < N ) return OLD[a+STEP] < OLD[b+STEP];
	return a > b;
}
 
bool up(){
	int cnt = 0;
	REP( i, N ){
		if( i && comp( SA[i-1], SA[i] ) ) cnt++;
		CUR[ SA[i] ] = cnt;
	}
	if( cnt == N-1 ) return false;
	return true;
}
 
void buildSA(){
	REP( i, N ) RA[ i ] = S[ SA[i] = i ];
	STEP = 0; OLD = RA, CUR = LCP;
	sort( SA, SA+N, comp );
	if( up() ){
		swap( OLD, CUR );
		for( STEP = 1; STEP < N; STEP *= 2 ){
			sort( SA, SA+N, comp );
			if( !up() ) return;
			swap( OLD, CUR );
		}
	}
}

void buildLCP(){
	REP( i, N ) RA[ SA[i] ] = i;
	LCP[0] = 0;
	for( int i = 0, h = 0; i < N; i++ ){
		if( RA[i] > 0 ){
			int j = SA[ RA[i]-1 ];
			while( ((i + h) < N) && ((j + h) < N) && (S[i+h] == S[j+h]) ) h++;
			LCP[ RA[i] ] = h;
			if( h > 0 ) h--;
		}
	}
}
int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	
	while( t-- ){
		
		cin >> S;
		
		N = SIZE( S );
		buildSA();
		buildLCP();
		
		int ans = 0, ps, times;
		REP( i, N-1 ){
			if( LCP[i+1] > ans ){
				ans = LCP[i+1], ps = i;
				times = 1;
				while( i < N-1 && LCP[i+1] == ans ) times++, i++;
				i--;
			}
		}
		if( ans ){ REP( i, ans ) cout << S[ SA[ps]+i ]; cout << " " << times << "\n"; }
		else cout << "No repetitions found!\n";
		
	}
	
	return 0;
}




















