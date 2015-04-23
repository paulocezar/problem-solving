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

char stree[2000];
int X, pos;

int best[111][2501];
int cur;

struct node_t{
	node_t *l, *r;
	int *nbest;
	node_t(){
		l = r = NULL;
		nbest = NULL;
	}
	node_t( int cap ){
		l = r = NULL;
		nbest = best[cur]; cur++;
		REP( i, X+1 ) nbest[i] = cap+i;
	}
};

node_t* build( ){
	
	while( stree[pos] != '(' 
			&& !('0' <= stree[pos] && stree[pos] <= '9') ) pos++;
	
	node_t* ans = NULL;
	if( stree[pos] == '(' ){
		pos++;
		ans = new node_t();
		ans->l = build();
		ans->r = build();
		
		REP( i, X+1 ){
			best[0][i] = best[1][i] = 0;
			REP( j, i+1 ){
				best[0][i] = max( best[0][i], min( (1+j)*(1+j), ans->l->nbest[i-j] ) );
				best[1][i] = max( best[1][i], min( (1+j)*(1+j), ans->r->nbest[i-j] ) );
			}
		}
		
		ans->nbest = best[cur]; cur++;
		REP( i, X+1 ){
			ans->nbest[i] = 0;
			REP( j, i+1 ){
				ans->nbest[i] = max( ans->nbest[i], best[0][j]+best[1][i-j] );
			}
		}
	} else {
		int leaf = 0;
		while( '0' <= stree[pos] && stree[pos] <= '9' ){
			leaf = 10*leaf	+ (stree[pos]-'0');
			pos++;
		}
		ans = new node_t(leaf);
	}
	return ans;
}

int main( int argc, char* argv[] ){
	
	//ios::sync_with_stdio( false );

	int t;
	node_t* tree;
	
	scanf("%d", &t );
	while( t-- ){
		
		gets(stree);
		while( !stree[0] || stree[0] == '\n' ) gets(stree);
		
		scanf("%d", &X );
		pos = 0; cur = 2;
		tree = build(); 
		printf("%d\n", tree->nbest[X] );
		
	}

	return 0;
}




















