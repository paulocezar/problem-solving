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
#include <bitset>
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

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 250000

struct state_t {
	int len, link;
	map< char, int > next;
};

int sz, last;
state_t state[2*MAXN];

void automata_init(){
	sz = last = 0;
	state[0].len = 0;
	state[0].link = -1;
	++sz;
}

void automata_extend( char c ){
	int cur = sz++;
	state[cur].len = state[last].len+1;
	int p;
	for( p = last; p != -1 && !state[p].next.count(c); p = state[p].link )
		state[p].next[c] = cur;
	if( p == -1 ) state[cur].link = 0;
	else{
		int q = state[p].next[c];
		if( state[p].len+1 == state[q].len ) state[cur].link = q;
		else {
			int clone = sz++;
			state[clone].len = state[p].len+1;
			state[clone].next = state[q].next;
			state[clone].link = state[q].link;
			for( ; p != -1 && state[p].next[c]==q; p=state[p].link )
				state[p].next[c] = clone;
			state[q].link = state[cur].link = clone;
		}
	}
	last = cur;
}

int main( int argc, char* argv[] ){
	
	automata_init();
	
	char c = getchar_unlocked();
	
	while( !('a'<=c&&c<='z') ) c = getchar_unlocked();
	while( 'a'<=c&&c<='z' ){
		automata_extend(c);
		c = getchar_unlocked();
	}
	
	while( !('a'<=c&&c<='z') ) c = getchar_unlocked();
	
	int ans = 0;
	
	int cur_state = 0;
	int cur_len = 0;
	
	while( 'a'<=c&&c<='z' ){
		
		while( cur_state && !state[cur_state].next.count(c) ){
			cur_state = state[cur_state].link;
			cur_len = state[cur_state].len;
		}
		
		if( state[cur_state].next.count(c) ){
			cur_state = state[cur_state].next[c];
			cur_len++;
		}
		
		ans = max( ans, cur_len );
		c = getchar_unlocked();
	}
	printf("%d\n", ans );
	
	
	return 0;
}

























