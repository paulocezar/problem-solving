/*
 *  Problema:
 *  Tecnica Utilizada:  
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int n;
int coord[10][2];
int cur[10], ans[10];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	cin >> n;
	int tst = 0;
	while( n ){
		
		tst++;
		REP( i, n ) cin >> coord[i][0] >> coord[i][1];
		
		double best = INF;
		double dist;
		REP( i, n ) cur[i] = i;
		
		do {
			dist = 0;
			REP( i, n-1 ) dist += sqrt( SQR( coord[cur[i]][0]-coord[cur[i+1]][0] ) + SQR( coord[cur[i]][1]-coord[cur[i+1]][1] ) );
			if( dist < best ){ best = dist; REP( i, n ) ans[i] = cur[i]; }
		} while( next_permutation( cur, cur+n )  );
		
		cout << "**********************************************************\nNetwork #" << tst << "\n";
		double ttl, cdist;
		ttl = 0.0;
		REP( i, n-1 ){
			cdist = 16. + sqrt( SQR( coord[ans[i]][0]-coord[ans[i+1]][0] ) + SQR( coord[ans[i]][1]-coord[ans[i+1]][1] ) );
			ttl += cdist;
			cout << "Cable requirement to connect (" << coord[ans[i]][0] << "," << coord[ans[i]][1] << ") to (" << coord[ans[i+1]][0] << "," << coord[ans[i+1]][1] << ") is " << fixed << setprecision(2) << cdist << " feet.\n";
		}
		cout << "Number of feet of cable required is " << fixed << setprecision(2) << ttl << ".\n";
		
		cin >> n;
	}
		
	return 0;
}
