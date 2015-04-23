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

#define MAXN 505
#define LGMN 9

int pop[MAXN][MAXN];
int segmx[1<<(LGMN+1)][1<<(LGMN+1)];
int segmn[1<<(LGMN+1)][1<<(LGMN+1)];

int N;
int xa, ya, xb, yb;
bool update;

void buildY( int nodex, int x, int node, int beg, int end ){
	if( beg == end ){
		segmx[nodex][node] = pop[x][beg];
		segmn[nodex][node] = pop[x][beg];
		return;
	}
	int lft = 2*node+1;
	int rgt = 2*node+2;
	int mid = (beg+end)/2;
	if( !update || ( ya >= beg && ya <= mid ) ) buildY( nodex, x, lft, beg, mid );
	if( !update || ( ya >= mid+1 && ya <= end ) ) buildY( nodex, x, rgt, mid+1, end );
	segmx[nodex][node] = MAX( segmx[nodex][lft], segmx[nodex][rgt] );
	segmn[nodex][node] = MIN( segmn[nodex][lft], segmn[nodex][rgt] );
}

void mergeY( int nodex, int node, int beg, int end ){
	if( beg == end ){
		segmx[nodex][node] = MAX( segmx[2*nodex+1][node], segmx[2*nodex+2][node] );
		segmn[nodex][node] = MIN( segmn[2*nodex+1][node], segmn[2*nodex+2][node] );
		return;
	}
	int lft = 2*node+1;
	int rgt = 2*node+2;
	int mid = (beg+end)/2;
	if( !update || ( ya >= beg && ya <= mid ) ) mergeY( nodex, lft, beg, mid );
	if( !update || ( ya >= mid+1 && ya <= end ) ) mergeY( nodex, rgt, mid+1, end );
	segmx[nodex][node] = MAX( segmx[2*nodex+1][node], segmx[2*nodex+2][node] );
	segmn[nodex][node] = MIN( segmn[2*nodex+1][node], segmn[2*nodex+2][node] );
}

void build( int node, int beg, int end ){
	if( beg == end ){
		buildY( node, beg, 0, 1, N );
		return;
	}
	int lft = 2*node+1;
	int rgt = 2*node+2;
	int mid = (beg+end)/2;
	
	if( !update || ( xa >= beg && xa <= mid ) ) build( lft, beg, mid );
	if( !update || ( xa >= mid+1 && xa <= end ) ) build( rgt, mid+1, end );	
	mergeY( node, 0, 1, N );
}

typedef pair<int,int> ans_t;

ans_t queryy( int nodex, int node, int beg, int end ){
	if( beg >= ya && end <= yb ) return mp( segmx[nodex][node], segmn[nodex][node] );
	
	int lft = 2*node+1;
	int rgt = 2*node+2;
	int mid = (beg+end)/2;
	
	if( mid < ya ) return queryy( nodex, rgt, mid+1, end );
	if( mid+1 > yb ) return queryy( nodex, lft, beg, mid );
	
	ans_t alft, argt, ans;
	alft = queryy( nodex, lft, beg, mid );
	argt = queryy( nodex, rgt, mid+1, end );
	ans.first = MAX( alft.first, argt.first );
	ans.second = MIN( alft.second, argt.second );
	return ans;
}

ans_t query( int node, int beg, int end ){
	if( beg >= xa && end <= xb ) return queryy( node, 0, 1, N );
	
	int lft = 2*node+1;
	int rgt = 2*node+2;
	int mid = (beg+end)/2;

	if( mid < xa ) return query( rgt, mid+1, end );
	if( mid+1 > xb ) return query( lft, beg, mid ); 
	
	ans_t alft, argt, ans;
	
	alft = query( lft, beg, mid );
	argt = query( rgt, mid+1, end );
	ans.first = MAX( alft.first, argt.first );
	ans.second = MIN( alft.second, argt.second );
	return ans;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int lixo;
	cin >> N >> lixo;
	
	FOR( i, 1, N+1 ) FOR( j, 1, N+1 ) cin >> pop[i][j];
	
	update = false;
	build( 0, 1, N );
	update = true;
	
	int Q, v;
	char q;
	cin >> Q;
	while( Q-- ){
		cin >> q;
		if( q == 'c' ){
			cin >> xa >> ya >> v;
			pop[xa][ya] = v;
			build( 0, 1, N );
		} else {
			cin >> xa >> ya >> xb >> yb;
			ans_t ans = query( 0, 1, N );
			cout << ans.first << " " << ans.second << "\n";
		}
	}
	
	return 0;
}
