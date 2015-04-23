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

int k, step;
int gr[30][30];
int seen[30];

void play( int at, int from ){
	
	seen[at] = ((++step)%k) == 0;
	for( int i = 0; gr[at][i] != -1; i++ ){
		if( gr[at][i] != from && !seen[ gr[at][i] ] ){
			if( seen[at] ) cout << char(at+'A') << " ";
			return play( gr[at][i], at );
		}
	}
	cout << "/" << char(at+'A') << "\n";
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	char fr, at;
	string gg;
	cin >> gg;
	while( gg != "#" ){
		
		cin >> at >> fr >> k;
		REP( i, 30 ) gr[i][0] = -1, seen[i] = 0;
		
		int i = 2, sz = SIZE(gg), p = 0, u, v;
		u = gg[0]-'A';
		
		while( i < sz ){
			v = gg[i]-'A';
			gr[u][p++] = v;
			i++;
		hell:
			if( gg[i] == ';' ){
				gr[u][p] = -1;
				p = 0;
				u = gg[++i]-'A';
				i+=2;
				goto hell;
			} else if( gg[i] == '.' ){
				gr[u][p] = -1;
				break;
			}
		}
		
		step = 0;
		play( at-'A', fr-'A' );
		
		cin >> gg;
	}
	return 0;
}




















