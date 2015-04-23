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

#define MAXN 55
#define MAXM 250001

int64 total[MAXN];
int64 pref[MAXN];
int64 sufx[MAXN];
int64 best[MAXN];

int inds[MAXM];

#define LOGM 18
 
struct tnode{
	int64 pr, sf, sm, mx;
};
 
tnode segt[ 1<<(LOGM+1) ];
 
void build( int node, int lo, int hi ){
	
	if( lo == hi ){
		
		segt[node].pr = pref[ inds[lo] ];
		segt[node].sf = sufx[ inds[lo] ];
		segt[node].sm = total[ inds[lo] ];
		segt[node].mx = best[ inds[lo] ];
		
	} else {
		
		int mid = (lo+hi)>>1;
		int lft = 2*node + 1, rgt = 2*node + 2;
		build( lft, lo, mid );
		build( rgt, mid+1, hi );
		
		segt[node].sm = segt[lft].sm + segt[rgt].sm;
		
		if( segt[lft].sm + segt[rgt].pr >= segt[lft].pr )
			segt[node].pr = segt[lft].sm + segt[rgt].pr;
		else
			segt[node].pr = segt[lft].pr;
				
		if( segt[rgt].sm + segt[lft].sf >= segt[rgt].sf )
			segt[node].sf = segt[rgt].sm + segt[lft].sf;
		else 
			segt[node].sf = segt[rgt].sf;
 
		segt[node].mx = segt[lft].mx;
		
		if( segt[node].mx < segt[rgt].mx )
			segt[node].mx = segt[rgt].mx;
		
		if( segt[lft].sf+segt[rgt].pr > segt[node].mx ) segt[node].mx = segt[lft].sf+segt[rgt].pr;
			
	}
	
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int n, m;
	cin >> n >> m;
	
	REP( i, n ){
		int sz;
		cin >> sz;
		
		vector< int64 > small = vector<int64>(sz);
		
		total[i] = 0;
		pref[i] = -INF;
		
		REP( j, sz ){
			cin >> small[j];
			total[i] += small[j];
			if( total[i] > pref[i] ) pref[i] = total[i];
		}
		
		sufx[i] = best[i] = -INF;
		int64 cur = 0;
		int64 curt = 0;
		REP( j, sz ){
			
			cur += small[j];
			
			if( cur > best[i] ) best[i] = cur;
			if( cur < 0 ) cur = 0;
			
			if( total[i]-curt > sufx[i] ) sufx[i] = total[i] - curt;
			
			curt += small[j];
		}
			
	}
	
	REP( i, m ){
		cin >> inds[i];
		inds[i]--;	
	}
	
	build( 0, 0, m-1 );
	
	cout << segt[0].mx << "\n";
	
	return 0;
}
