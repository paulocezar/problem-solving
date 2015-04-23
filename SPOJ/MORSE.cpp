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

string morse[] = { ".-", "-...", "-.-.", "-..",
					".", "..-.", "--.", "....", 
					"..", ".---", "-.-", ".-..",
					"--", "-.", "---", ".--.",
					"--.-", ".-.", "...", "-",
					"..-", "...-", ".--", "-..-",
					"-.--", "--.." };

struct node_t{
	node_t* chld[2];
	int endhere;
	node_t(){ chld[0] = chld[1] = NULL; endhere = 0; }
};

node_t trie;

string s;
int N;

inline int ind(char ch){ return ((ch=='.')?(0):(1)); }

#define MAXN 10000
int dp[MAXN];

int solve( int ini ){
	if( ini == N ) return 1;
	if( ini > N ) return 0;
	if( dp[ini] == -1 ){
		dp[ini] = 0;
		node_t* cur = &trie;
		int i = 0;
		
		while( ini+i < N ){
			if( cur->chld[ind(s[ini+i])] != NULL ){
				cur = cur->chld[ind(s[ini+i])];
			} else break;
			
			if( cur->endhere ) dp[ini] += (cur->endhere)*solve(ini+i+1);
			i++;
		}
	}
	return dp[ini];
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int d, w;
	string raw, mrs;
	
	cin >> d;
	while( d-- ){
		cin >> s; N = SIZE(s);
		cin >> w;
		trie = node_t();
		while( w-- ){
			cin >> raw;
			mrs = "";
			REP( i, SIZE(raw)) mrs += morse[raw[i]-'A'];
		
			node_t* cur = &trie;
			int i = 0;
			while( cur->chld[ind(mrs[i])] != NULL && i < SIZE(mrs) ){ cur = cur->chld[ind(mrs[i])]; i++; }
			
			while( i < SIZE(mrs) ){
				cur->chld[ind(mrs[i])] = new node_t();
				cur = cur->chld[ind(mrs[i])];
				i++;
			}
			
			(cur->endhere)++;
		}
		
		REP( i, N ) dp[i] = -1;
		cout << solve(0) << "\n";
	
	}
	
	return 0;
}


















