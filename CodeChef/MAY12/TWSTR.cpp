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
	map<char,node_t*> chld;
	map<int,char> pr;
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	int N;
	cin >> N;
	
	node_t *trie = new node_t();
	
	REP( i, N ){
		string s; int v;
		cin >> s >> v;
		node_t *aux = trie;
		int pos = 0;
		while( pos < SIZE(s) && (aux->chld).count(s[pos]) ){
			(aux->pr)[v] = s[pos];
			aux = (aux->chld)[s[pos]];
			pos++;
		}
		while( pos < SIZE(s) ){
			(aux->chld)[s[pos]] = new node_t();
			(aux->pr)[v] = s[pos];
			aux = (aux->chld)[s[pos]];
			pos++;
		}
	}
	
	int Q;
	cin >> Q;
	while( Q-- ){
		string q;
		cin >> q;
		int pos = 0;
		int go = -2000000000;		
		
		node_t *aux = trie;
		while( pos < SIZE(q) ){
			if( (aux->chld).count(q[pos]) ){
				aux = (aux->chld)[q[pos]];
				pos++;
			} else {
				cout << "NO\n";
				goto hell;
			}
		}
		
		FORIT( x, aux->pr ) if( x->first > go ){
			go = x->first;
		}
		
		while( (aux->pr).count(go) ){
			q += (aux->pr)[go];
			aux = (aux->chld)[ (aux->pr)[go] ];
		}
		cout << q << "\n";
	hell:;
	}
	
	return 0;
}

























