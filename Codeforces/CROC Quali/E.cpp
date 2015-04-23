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
	map< string, node_t* > child;
	int reached;
};

string s;
int spos;

void build( node_t* node ){
	
	while( spos < SIZE(s) ){
		
		spos++;
		string cur = "";
		
		while( s[spos] != '>' ) cur += s[spos++];
		
		if( cur[0] == '/' ){ spos++; return; }
		
		bool flag = false;

		if( cur[SIZE(cur)-1] == '/' ){
			flag = true;
			cur.erase(SIZE(cur)-1);
		}


		if( !(node->child.count(cur)) ) node->child[cur] = new node_t();
		
		node->child[cur]->reached++;

		spos++;
		if( flag ) continue;
		else build( node->child[cur] );
		
	}	
}

int N;
string qry[222];

//map< pair<node_t*,int>, int > memo;

int ans = 0;

void solve( node_t* node, int pos ){
	//if( pos == N ) ans += node->reached;
	//if( memo.count(MP(node,pos)) ) return memo[MP(node,pos)];
	
	//int ans = 0;
	//memo[MP(node,pos)];
	FORIT( x, node->child ){
		if( x->first == qry[pos] ){
			if( pos == N-1 ){ ans += x->second->reached; solve(x->second,pos); }
			else solve( x->second, pos+1 );
			
		} else solve( x->second, pos );
	}
	//return ans;
}

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	node_t* pref_trie = new node_t();
	
	cin >> s; spos = 0;
	build( pref_trie );
	
	int q;
	cin >> q; cin.ignore();
	while( q-- ){
		getline(cin,s);
		istringstream iss(s);
		
		N = 0;
		while( iss >> qry[N] ) N++;
		
		//memo.clear();
		ans = 0;
		solve(pref_trie,0);
		cout << ans << "\n";
		
	}
	
		
	return 0;
}

























