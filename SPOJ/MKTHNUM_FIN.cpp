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

struct node_t{
	vector<int> sa;
	node_t *esq, *dir;
	node_t(){ esq = dir = NULL; sa.clear(); }
};

#define MAXN 100000
int a[MAXN];

void build( node_t* node, int lo, int hi ){
	if( lo == hi ){
		node->sa.PB(a[lo]);
	} else {
		node->esq = new node_t();
		node->dir = new node_t();
		int mid = (lo+hi)/2;
		build( node->esq, lo, mid );
		build( node->dir, mid+1, hi );
		int pe = 0, pd = 0;
		int se = SIZE( node->esq->sa ), sd = SIZE( node->dir->sa );
		while( pe < se && pd < sd ){
			if( (node->esq->sa)[pe] < (node->dir->sa)[pd] ) node->sa.PB((node->esq->sa)[pe++]);
			else node->sa.PB( (node->dir->sa)[pd++] );
		}
		if( pe == se ){
			while( pd < sd ) node->sa.PB( (node->dir->sa)[pd++] );
		} else while( pe < se ) node->sa.PB( (node->esq->sa)[pe++] );
	}
}

int from, to, mn, mx, sintr, n, k;
node_t* interest[32];

void query( node_t* node, int lo, int hi ){
	if( from <= lo && hi <= to ){
		interest[sintr++] = node;
		mn = min( mn, node->sa[0] );
		mx = max( mx, node->sa.back() );
	} else {
		int mid = (lo+hi)/2;
		if( mid >= from ) query( node->esq, lo, mid );
		if( mid+1 <= to ) query( node->dir, mid+1, hi );
	}
}

int clt( int key ){
	int ans = 0;
	REP( i, sintr )
		ans += lower_bound( ALL(interest[i]->sa), key ) - (interest[i]->sa).begin();
	return ans;
}

bool check( int key ){
	REP( i, sintr ) if( binary_search(ALL(interest[i]->sa), key) ) return true;
	return false;
}

int query( node_t* root ){
	sintr = 0; mn = INF; mx = -INF;
	query( root, 0, n-1 );
	int lo = mn, hi = mx, mid, lessthan;
	while( lo <= hi ){
		mid = lo + (hi-lo)/2;
		lessthan = clt(mid);
		if( lessthan < k ) lo = mid+1;
		else if( lessthan > k ) hi = mid-1;
		else {
			if( check(mid) ) return mid;
			lo = mid+1;
		}
	}
	return lo;
}

inline int next_int() {
	int n = 0, neg = 1;
	char c = getchar_unlocked();
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = -1;
		c = getchar_unlocked();
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return neg*n;
}

int main( int argc, char* argv[] ){
	
	int m;
	
	n = next_int();
	m = next_int();
	
	REP( i, n ) a[i] = next_int();
		
	node_t root;
	build( &root, 0, n-1 );
	
	while( m-- ){
		from = next_int();
		to = next_int();
		k = next_int();
		from--, to--, k--;
		//cout << query( &root ) << "\n";
		printf("%d\n", query(&root));
	}
	
	return 0;
}




















