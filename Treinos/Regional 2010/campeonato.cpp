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
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

void init(); map< char, string > raw;
pair<double,double> pos[10];
double d[10][10];

int n;
string rmsg;

double dp[10][10][777];
bool memo[10][10][777];

double solve( int l, int r, int pos ){
	if( pos == n ) return 0;
	if( memo[l][r][pos] ) return dp[l][r][pos];
	memo[l][r][pos] = true;
	dp[l][r][pos] = 0.2 + min( d[l][rmsg[pos]-'0']+solve(rmsg[pos]-'0',r,pos+1),
	 							d[r][rmsg[pos]-'0']+solve(l,rmsg[pos]-'0',pos+1)	);
	return dp[l][r][pos];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	init();
	
	string msg;
	while( getline(cin,msg) ){
		
		rmsg = "";
		
		REP( i, SIZE(msg) ){
			if( i && (raw[ msg[i] ][0] == raw[ msg[i-1] ][0]) ) rmsg += "1";
			rmsg += raw[ msg[i] ];
		}
		
		FILL( memo, false ); n = SIZE(rmsg);
		cout << fixed << setprecision(2) << solve(4,6,0) << "\n";
	}
	
	return 0;
}

void init(){
	raw['a'] = "2";
	raw['b'] = "22";
	raw['c'] = "222";
	raw['d'] = "3";
	raw['e'] = "33";
	raw['f'] = "333";
	raw['g'] = "4";
	raw['h'] = "44";
	raw['i'] = "444";
	raw['j'] = "5";
	raw['k'] = "55";
	raw['l'] = "555";
	raw['m'] = "6";
	raw['n'] = "66";
	raw['o'] = "666";
	raw['p'] = "7";
	raw['q'] = "77";
	raw['r'] = "777";
	raw['s'] = "7777";
	raw['t'] = "8";
	raw['u'] = "88";
	raw['v'] = "888";
	raw['w'] = "9";
	raw['x'] = "99";
	raw['y'] = "999";
	raw['z'] = "9999";
	raw[' '] = "0";
					  pos[2] = MP(0,1); pos[3] = MP(0,2);
	pos[4] = MP(1,0); pos[5] = MP(1,1); pos[6] = MP(1,2);
	pos[7] = MP(2,0); pos[8] = MP(2,1); pos[9] = MP(2,2);
	 				  pos[0] = MP(3,1); pos[1] = MP(3,2);
	
	REP( i, 10 ) REP( j, 10 )
		d[i][j] = sqrt( SQR(pos[i].first-pos[j].first) + SQR(pos[i].second-pos[j].second) )/30.0;	
}




















