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

struct node_t{
	int cnt;
	node_t* child[10];
	
	node_t(){
		REP( i, 10 ) child[i] = NULL;
		cnt = 0;
	}
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int n;
	node_t* trie = new node_t();
	
	cin >> n;
	
	if( n == 1 ){
		string s;
		cin >> s;
		cout << SIZE(s) << "\n";
		return 0;
	}
	
	string s;
	REP( si, n-1 ){
		cin >> s;
		int i = 0;
		node_t* aux = trie;
		while( i < SIZE(s) ){
			(aux->cnt)++;
			if( aux->child[ s[i]-'0' ] != NULL ) aux = aux->child[ s[i]-'0' ];
			else break;
			i++;	
		}
		while( i < SIZE(s) ){
			aux->child[ s[i]-'0' ] = new node_t();
			aux = aux->child[ s[i]-'0' ];
			(aux->cnt)++;
			i++;
		}
	}
	
	int ans = 0;
	
	cin >> s;
	int i = 0;
	node_t* aux = trie;
	while( i < SIZE(s) ){
		if( aux->cnt == n-1 ) ans = i;
		if( aux->child[ s[i]-'0' ] != NULL ) aux = aux->child[ s[i]-'0' ];
		else break;
		i++;	
	}
	cout << ans << "\n";
	
		
	return 0;
}

























