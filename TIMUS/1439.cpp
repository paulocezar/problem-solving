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
	int key, pr, sz;
	node_t *l, *r;
	node_t(int k) : key(k), pr(rand()), sz(0), l(NULL), r(NULL) {}
};

void rotate_right( node_t* &t ){
	node_t *n = t->l;
	t->l = n->r;
	n->r = t;
	t = n;
}

void rotate_left( node_t* &t ){
	node_t *n = t->r;
	t->r = n->l;
	n->l = t;
	t = n;
}

void update( node_t* t ){
	if(!t) return;
	t->sz = 1 + ((t->l)?(t->l->sz):(0)) + ((t->r)?(t->r->sz):(0));
}

void fix( node_t* &t ){
	if( !t ) return;
	update(t->l); update(t->r); update(t);
}

void insert( node_t* &t, int val ){
	if( !t ) t = new node_t(val);
	else{
		if( val < t->key ) insert( t->l, val );
		else insert( t->r, val );
	}
	
	if( t->l && (t->l->pr > t->pr) ) rotate_right(t);
	else if( t->r && (t->r->pr > t->pr) ) rotate_left(t);
	fix(t);
}

int lcount(node_t* t, int val){
	int ans;
	if( !t ) ans = 0;
	else{
		if( t->key <= val ){
			ans = (t->l)?(t->l->sz):(0);
			ans++;
			ans += lcount(t->r,val);
		} else {
			ans = lcount(t->l,val);
		}
	}
	return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N, M, where, realpos;
	char wut;
	cin >> N >> M;
	node_t* treap = NULL;
	
	while( M-- ){
		cin >> wut >> where;
		int lo = 0, hi = N;
		
		while( lo <= hi ){
			
			int mid = (lo+hi)/2;
			int deleted = lcount(treap,mid);
			
			if( mid-deleted < where )
				lo = mid+1;
			else hi = mid-1;
			
		}
		
		realpos = lo;
		if( wut == 'L' ) cout << realpos << "\n";
		else insert(treap, realpos);
	}
	
	return 0;
}




















