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

inline int next_int() {
	int res = 0;
	char c = getchar_unlocked();	
	while( !isdigit(c) ) c = getchar_unlocked();
	
	while( isdigit(c) ){
		res = (res * 10) + (c - '0');
		c = getchar_unlocked();
	}
	
	return res;
}

char bffr[22];

void read( string &s ){
	int N = 0;
	bffr[N] = getchar_unlocked();
	while( !isalpha(bffr[N]) ) bffr[N] = getchar_unlocked();
	while( isalpha(bffr[N]) ){ N++; bffr[N] = getchar_unlocked(); }
	bffr[N] = '\0';
	s = bffr;
}

#define MAXP 1000000
int g[MAXP];

int main( int argc, char* argv[] ){
	
	int t, e, p, j;
	
	t = next_int();
	while( t-- ){
		e = next_int();
		p = next_int();
		j = next_int();
		int score = -1;
		string wnnr;
		
		REP( team, e ){
			string team_name;
			read( team_name );
			
			REP( i, p ) g[i] = next_int();
			multiset< int > goals;
			
			int pos = 0;
			while( pos < j ) goals.insert( g[pos++] );
			
			int points = 0;
			while( pos < p ){
				points += *goals.begin();
				points += *goals.rbegin();
				goals.erase( goals.find(g[pos-j]) );
				goals.insert( g[pos] );
				pos++;
			}
			
			points += *goals.begin();
			points += *goals.rbegin();
			
			if( points > score ){
				score = points;
				wnnr = team_name;
			} else if( points == score && team_name < wnnr ) wnnr = team_name;
			
			
		}
		
		printf("%s %d\n", wnnr.c_str(), score );
		
	}
	
	
	return 0;
}

























