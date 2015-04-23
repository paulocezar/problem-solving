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

int next_int(){
	int res = 0;
	char c = getchar_unlocked();
	while( !isdigit(c) ) c = getchar_unlocked();
	while( isdigit(c) ){
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;
}

#define MAXN 300001
char lft[MAXN], rgt[MAXN];
int lvl[MAXN];

int main( int argc, char* argv[] ){
	
	int n = next_int();
	
	set< int > tree;
	int64 C = 0;
	
	int x = next_int(); tree.insert(x);
	printf("%lld\n", C );
	
	n--;
	while(n--){
		x = next_int();
		set<int>::iterator prv, nxt = tree.upper_bound(x);
		
		if( nxt == tree.begin() ){ // no previous..
			
			lvl[x] = lvl[*nxt]+1;
			C += lvl[x];
			lft[*nxt] = 1;
			
		} else if( nxt == tree.end() ) { // no next
			
			prv = nxt; prv--;
			
			lvl[x] = lvl[*prv]+1;
			C += lvl[x];
			rgt[*prv] = 1;
			
		} else {
			
			prv = nxt; prv--;
			
			if( lft[*nxt] ){
				lvl[x] = lvl[*prv]+1;
				C += lvl[x];
				rgt[*prv] = 1;
			} else {
				lvl[x] = lvl[*nxt]+1;
				C += lvl[x];
				lft[*nxt] = 1;
			}
			
		}
		
		tree.insert(x);
		printf("%lld\n", C );
	}
	
	return 0;
}

























