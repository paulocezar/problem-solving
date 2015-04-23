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

inline void read( int &n ) {
	n = 0;
	bool neg = false;
	char c = getchar_unlocked();
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = true;
		c = getchar_unlocked();
	}
	while ('0' <= c && c <= '9') {
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	n = (neg ? (-n) : (n));
}

struct node_t{
	int key, sz, pr;
	node_t *l, *r;
	node_t( int val = 0 ) : key(val), sz(0), pr(rand()), l(NULL), r(NULL) {}
	~node_t(){ if(l) delete l; if(r) delete r; }
	void walk(int d = 0){
		if( l ) l->walk(d+1);
		REP( i, d ) putchar('\t'); 
		printf("%d\n", key);
		if( r ) r->walk(d+1);
	}
};

void rotate_right(node_t* &t ){
	node_t* n = t->l;
	t->l = n->r;
	n->r = t;
	t = n;
}

void rotate_left(node_t* &t ){
	node_t* n = t->r;
	t->r = n->l;
	n->l = t;
	t = n;
}

void update(node_t* t){
	if(!t) return;
	t->sz = ((t->l)?(t->l->sz):(0)) + 1 + ((t->r)?(t->r->sz):(0));
}

void fix( node_t* &t ){
	if(!t) return;
	update(t->l); update(t->r); update(t);
}

void insert(node_t* &t, int val){
	if( !t ) t = new node_t(val);
	else{
		if( t->key == val ) return;
		if( val < t->key ) insert( t->l, val);
		else insert( t->r, val);
	}
	
	if( t->l && (t->l->pr > t->pr) ) rotate_right(t);
	else if( t->r && (t->r->pr > t->pr) ) rotate_left(t);
	
	fix(t);
}

inline int p( node_t* t ){ return (t ? (t->pr) : (-1)); }

void erase( node_t* &t, int val ){
	if( !t ) return;
	if( t->key != val ) erase( ((val < t->key)?(t->l):(t->r)), val );
	else {
		if( !(t->l) && !(t->r) ){ delete t, t = NULL; }
		else{
			(p(t->l) < p(t->r)) ? rotate_left(t) : rotate_right(t);
			erase( t, val );
		}
	}
	fix(t);
}

int qcount( node_t* t, int val ){
	if( !t ) return 0;
	if( t->key == val ) return (t->l)?(t->l->sz):(0);
	if( val < t->key ) return qcount(t->l, val);
	return ((t->l)?(t->l->sz):(0)) + 1 + qcount(t->r, val);
}

int kth( node_t* t, int k ){
	int lsz = (t->l)?(t->l->sz):(0);
	if( lsz+1 == k ) return t->key;
	if( lsz >= k ) return kth(t->l, k);
	return kth(t->r, k-lsz-1 );
}

int main( int argc, char* argv[] ){
	
	int Q, x;
	char wut;
	
	node_t *treap = NULL;
	read(Q);
	while( Q-- ){
		wut = getchar_unlocked();
		while( wut != 'I' && wut != 'D' && wut != 'K' && wut != 'C' ) wut = getchar_unlocked();
		read(x);
		switch( wut ){
			case 'I': insert(treap,x); break;
			case 'D': erase(treap,x); break;
			case 'C': x = qcount(treap,x); printf("%d\n", x ); break;
			case 'K': 	if( (treap?(treap->sz):(0)) < x ) printf("invalid\n");
						else printf("%d\n", kth(treap,x) );
		}
		//treap->walk(); cout << "--------\n";
	}
	
	return 0;
}




















