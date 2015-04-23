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

struct seg_info{
	int sum, suf, pref, best;
	seg_info(){ sum = suf = pref = best = -INF; }
	void merge( seg_info* left, int key, seg_info* right ){
		sum = key + ((left)?(left->sum):(0)) + ((right)?(right->sum):(0));
		suf = max( (right)?(right->suf):(-INF), ((left)?(left->suf >= 0 ? left->suf : 0):(0)) + key + ((right)?(right->sum):(0))  ); 
		pref = max( (left)?(left->pref):(-INF), ((left)?(left->sum):(0)) + key + ((right)?(right->pref >= 0 ? right->pref : 0):(0)) );
		best = max( (left)?(left->best):(-INF), (right)?(right->best):(-INF) );
		best = max( best, max( key, max( sum, max( suf, pref ) ) ) );
		best = max( best, ((left)?(left->suf):(0)) + key + ((right)?(right->pref):(0)) );
		best = max( best, ((left)?(left->suf):(0)) + key );
		best = max( best, key + ((right)?(right->pref):(0)) );
		//cout << "refresh key " << key << " " << sum << " " << suf << " " << pref << " " << best << endl;
	}
};

struct node_t{
	int key, pr, sz;
	seg_info seg;
	
	node_t *l, *r;
	node_t(int k) : key(k), pr(rand()), sz(0), l(NULL), r(NULL) {}
	/*~node_t(){
		if(l) delete l;
		if(r) delete r;
	}*/
	void walk( int d = 0 ){
		if(l) l->walk(d+1);
		REP( i, d ) cout << "\t";
		cout << key << endl;
		if(r) r->walk(d+1);
	}
	
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
	t->seg.merge( ((t->l)?(&(t->l->seg)):(NULL)), t->key, ((t->r)?(&(t->r->seg)):(NULL)) );
}

void insert( node_t* &t, int val, int pos ){
	if(!t) t = new node_t(val);
	else {
		int lsz = ((t->l)?(t->l->sz):(0));
		if( lsz >= pos ) insert(t->l, val, pos);
		else insert(t->r, val, pos-lsz-1);
	}
	
	if( t->l && ((t->l->pr) > (t->pr)) ) rotate_right(t);
	else if( t->r && ((t->r->pr) > (t->pr)) ) rotate_left(t);
	
	update(t->l); update(t->r); update(t);
}

inline int p(node_t* t) { return (t) ? (t->pr) : (-1); }

int x, y;

void erase( node_t* &t, int pos ){
	if(!t) return;
	
	int lsz = ((t->l)?(t->l->sz):(0));
	if( lsz+1 != pos ){
		if( lsz >= pos ) erase(t->l, pos);
		else erase(t->r, pos-lsz-1);
	} else {
		if( !t->l && !t->r ){
			//delete t; 
			t = NULL;
		} else {
			if(p(t->l) < p(t->r)) rotate_left(t); else rotate_right(t);
			erase( t, pos );
		}
	}
	
	if( t ){ update(t->l); update(t->r); } update(t);
}

void replace( node_t* t, int pos, int val ){
	if(!t) return;
	
	int lsz = ((t->l)?(t->l->sz):(0));
	if( lsz+1 != pos ){
		if( lsz >= pos ) replace(t->l, pos, val);
		else replace(t->r, pos-lsz-1, val);
	} else t->key = val;
	
	update(t);
}

seg_info query( node_t* t, int lo, int hi ){
	
	if( x <= lo && hi <= y ){
		//cout << lo << " " << hi << " -- " << t->seg.best << " " << t->seg.suf << " " << t->seg.pref << " " << t->seg.sum << endl;
		return t->seg;
	}
	int mid = lo + ((t->l)?(t->l->sz):(0)) - 1;
	
	seg_info q1, q2, ans;
	bool f1, f2; f1 = f2 = false;
	if( mid >= lo && mid >= x ){ f1 = true; q1 = query(t->l, lo, mid); }
	if( mid+2 <= hi && mid+2 <= y ){ f2 = true; q2 = query(t->r, mid+2, hi); }
	
	if( !f1 && !f2 ){
		ans.best = ans.suf = ans.pref = ans.sum = t->key;
		return ans;
	}
	
	if( f1 && f2 ){
		ans.merge( &q1, t->key, &q2 );
	} else if( f1 ){
		if( x <= mid+1 && mid+1 <= y ) ans.merge( &q1, t->key, NULL );
		else ans = q1;
	} else if( x <= mid+1 && mid+1 <= y ) ans.merge( NULL, t->key, &q2 );
	else ans = q2;
	//cout << lo << " " << hi << " -- " << ans.best << " " << ans.suf << " " << ans.pref << " " << ans.sum << endl;	
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
	
	node_t* treap = NULL;
	char wut;
	
	int N, Q;
	
	N = next_int();
	REP( i, N ){
		x = next_int();
		insert( treap, x, i );
	}
	
	Q = next_int();
	while( Q-- ){
		
		do wut = getchar_unlocked(); while( wut != 'I' && wut != 'D' && wut != 'R' && wut != 'Q' );
		
		switch(wut){
			case 'I' : x = next_int(); y = next_int();
						insert( treap, y, x-1 );
						break;
			case 'D': x = next_int();
						erase(treap, x );
						break;
			case 'R': x = next_int(); y = next_int();
						replace(treap, x, y );
						break;
			case 'Q': x = next_int(); y = next_int();
				printf( "%d\n", query( treap, 1, treap->sz ).best );
			
		}
		//if( wut != 'Q' ) treap->walk(); cout << "--------" << endl;
		
	}
	
	return 0;
}




















