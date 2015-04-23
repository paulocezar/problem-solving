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

#define MAXN 100001
#define LGMN 17

struct node_t{
	int lft, rgt, mx;
	node_t( int _lft = 0, int _rgt = 0, int _mx = 0 ) : lft(_lft), rgt(_rgt), mx(_mx) {}
};

node_t segt[1<<(LGMN+1)];
int a[MAXN];

void build( int node, int beg, int end ){
	if( beg == end ){
		segt[node].lft = segt[node].rgt = segt[node].mx = 1;
	} else {
		int lft = 2*node+1;
		int rgt = 2*node+2;
		
		int mid = (beg+end)/2;
		
		build( lft, beg, mid );
		build( rgt, mid+1, end );
		
		segt[node].mx = MAX( segt[lft].mx, segt[rgt].mx );
		if( a[mid] == a[mid+1] ) segt[node].mx = MAX( segt[node].mx, segt[lft].rgt + segt[rgt].lft );
		
		if( a[beg] == a[mid+1] ){
			segt[node].lft = segt[lft].lft + segt[rgt].lft;
			segt[node].mx = MAX( segt[node].mx, segt[node].lft );
		} else segt[node].lft = segt[lft].lft;
		
		if( a[mid] == a[end] ){
			segt[node].rgt = segt[lft].rgt + segt[rgt].rgt;
			segt[node].mx = MAX( segt[node].mx, segt[node].rgt );
		} else segt[node].rgt = segt[rgt].rgt;	
	}
}

int from, to;

node_t query( int node, int beg, int end ){
	
	if( beg >= from && end <= to ) return segt[node];
	
	int ilft = 2*node+1;
	int irgt = 2*node+2;
	int mid = (beg+end)/2;
	
	if( mid < from ) return query( irgt, mid+1, end );
	if( mid+1 > to ) return query( ilft, beg, mid ); 
	
	node_t ans, lft, rgt;
	lft = query( ilft, beg, mid );
	rgt = query( irgt, mid+1, end );
	
	ans.mx = MAX( lft.mx, rgt.mx );
	if( a[mid] == a[mid+1] ) ans.mx = MAX( ans.mx, lft.rgt + rgt.lft );
	
	if( a[beg] == a[mid+1] ){
		ans.lft = lft.lft + rgt.lft;
		ans.mx = MAX( ans.mx, ans.lft );
	} else ans.lft = lft.lft;
	
	if( a[mid] == a[end] ){
		ans.rgt = lft.rgt + rgt.rgt;
		ans.mx = MAX( ans.mx, ans.rgt );
	} else ans.rgt = rgt.rgt;
	
	return ans;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int N, Q;
	cin >> N;
	while( N ){
		cin >> Q;
		
		FOR( i, 1, N+1 ) cin >> a[i];
		build( 0, 1, N );
		
		while( Q-- ){
			cin >> from >> to;
			cout << query( 0, 1, N ).mx << "\n";
		}
		
		cin >> N;
	}
	
	return 0;
}
