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
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1024010
#define LGMN 20

int segt[1<<(LGMN+1)];
char todo[1<<(LGMN+1)];

int from, to;
char tp;
string s;

void build( int node, int beg, int end ){
	if( beg == end ){
		segt[node] = ( s[beg] == '1' );
	} else {
		int lft = 2*node+1;
		int rgt = 2*node+2;
		int mid = (beg+end)/2;
		build( lft, beg, mid );
		build( rgt, mid+1, end );
		segt[node] = segt[lft] + segt[rgt];
	}
	todo[node] = '-';
}

void push( int node, int beg, int end, char wut ){
	if( wut == 'F' ){ /* Tudo 1 */
		todo[node] = 'F';
		segt[node] = end-beg+1;		
	} else if( wut == 'E' ){ /* Tudo 0 */
		todo[node] = 'E';
		segt[node] = 0;
	} else if( wut == 'I' ){ /* Inverte */
		if( todo[node] == 'F' ){
			todo[node] = 'E';
			segt[node] = 0;
		} else if( todo[node] == 'E' ){
			todo[node] = 'F';
			segt[node] = end-beg+1;
		} else if( todo[node] == 'I' ){
			todo[node] = '-';
			segt[node] = (end-beg+1) - segt[node];
		} else {
			todo[node] = 'I';
			segt[node] = (end-beg+1) - segt[node];	
		}
	}	
}

void update( int node, int beg, int end ){
	if( beg >= from && end <= to ){
		push( node, beg, end, tp );
	} else {
		int lft = 2*node+1;
		int rgt = 2*node+2;
		int mid = (beg+end)/2;
		
		push( lft, beg, mid, todo[node] );
		push( rgt, mid+1, end, todo[node] );
		todo[node] = '-';
		
		if( mid >= from ) update( lft, beg, mid );
		if( mid+1 <= to ) update( rgt, mid+1, end );
		
		segt[node] = segt[lft] + segt[rgt];
	}
}

int query( int node, int beg, int end, bool one = false, bool zero = false, bool inv = false ){
	
	if( beg >= from && end <= to ){
		return segt[node];
	}
	
	int lft = 2*node+1;
	int rgt = 2*node+2;
	int mid = (beg+end)/2;
	
	push( lft, beg, mid, todo[node] );
	push( rgt, mid+1, end, todo[node] );
	todo[node] = '-';
	
	if( mid < from ) return query( rgt, mid+1, end );
	if( mid+1 > to ) return query( lft, beg, mid );
	
	int s1 = query( lft, beg, mid );
	int s2 = query( rgt, mid+1, end );
	
	return s1+s2;	
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int T;
	cin >> T;
	int tc = 1;
	while(T--){
		
		s = "";
		
		int M, Q, conc;
		string pirates;
		
		cin >> M;
		while( M-- ){
			cin >> conc;
			cin >> pirates;
			while( conc-- ) s += pirates;
		}
		int n = SIZE(s);
		build( 0, 0, n-1 );
		
		cin >> Q;
		cout << "Case " << tc++ << ":\n";
		int qc = 1;
		while( Q-- ){
			cin >> tp >> from >> to;
			if( tp == 'S' ) cout << "Q" << qc++ << ": " << query( 0, 0, n-1 ) << "\n";
			else update( 0, 0, n-1 );
		}
		
	}
	
	return 0;
}
