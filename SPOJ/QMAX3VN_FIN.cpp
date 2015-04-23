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

int x, y;

struct node_t{
	int key, pr, best, sz;
	node_t *l, *r;
	node_t(int k) : key(k), pr(rand()), best(k), sz(0), l(NULL), r(NULL) {}
	~node_t(){
		if( l ) delete l;
		if( r ) delete r; 
	}
	void walk( int d = 0 ){
		if(l) l->walk(d+1);
		REP( i, d ) cout << "\t";
		cout << key << endl;
		if(r) r->walk(d+1);
	}
};


void update( node_t* t ){
	if( !t ) return;
	t->sz = 1+((t->l)?(t->l->sz):(0))+((t->r)?(t->r->sz):(0));
	t->best = max( t->key, max(((t->l)?(t->l->best):(-INF)),((t->r)?(t->r->best):(-INF))) );
}


void rotate_right( node_t* &t ){
	node_t* n = t->l;
	t->l = n->r;
	n->r = t;
	t = n;
}

void rotate_left( node_t* &t ){
	node_t* n = t->r;
	t->r = n->l;
	n->l = t;
	t = n;
}


void insert( node_t*& t, int key, int at ){
	if( !t ) t = new node_t(key);
	else {
		int lsz = ((t->l)?(t->l->sz):(0));
		if( lsz >= at ) insert(t->l, key, at);
		else insert(t->r, key, at-lsz-1);
	}
	
	if( t->l && ((t->l->pr) > (t->pr)) ) rotate_right(t);
	else if( t->r && ((t->r->pr) > (t->pr)) ) rotate_left(t);
	
	update(t->l); update(t->r); update(t);
}

int query( node_t* t, int lo, int hi ){
	if( t == NULL ) return -INF;
	//cout << lo << " .. " << hi << endl;
	if( x <= lo && hi <= y ) return t->best;
	//cout << "..." << endl;
	int ans = -INF;
	
	int mid = lo + ((t->l)?(t->l->sz):(0)) - 1;
	//cout << mid << endl;
	if( mid >= x ) ans = max( ans, query(t->l, lo, mid) );
	if( mid+2 <= y ) ans = max( ans, query(t->r, mid+2, hi) );
	if( x <= mid+1 && mid+1 <= y ) ans = max( ans, t->key );
	
	return ans;
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
	
	srand( time(NULL) );
	
	int n;
	
	node_t* treap = NULL;
	n = next_int();
	char wut;
	while( n-- ){
		wut = getchar_unlocked();
		while( wut != 'A' && wut != 'Q' ) wut = getchar_unlocked();
		x = next_int();
		y = next_int();
		if( wut == 'A' ){
			insert( treap, x, y-1 );
			//treap->walk(); cout << "-----" << endl;
		} else printf("%d\n", query( treap, 1, treap->sz ) );
	}
	
	return 0;
}




















