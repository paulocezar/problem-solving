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

struct node_t {
	bool root;
	node_t* failure;
	node_t* n_output;
	map< char, node_t* > child;
	vector< int > output;
		
	node_t(){ 
		root = false;
		n_output = NULL;
		failure = NULL;
		child.clear();
		output.clear();
	}
	
	node_t* g( char c ) {
		if( !child.count(c) ) return (root?(this):(NULL));
		return child[c];
	}
	
	node_t* next( char c ){
		if( g(c) != NULL ) return g(c);
		child[c] = failure->next(c);
		return child[c];
	}
	
};

const string alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void add( node_t* prefix_trie, string &s, int id ){
	int i = 0, sz = SIZE(s);
	while( i < sz ){
		if( prefix_trie->g(s[i]) != NULL ) prefix_trie = prefix_trie->g(s[i]);
		else break;
		i++;
	}
	while( i < sz ){
		prefix_trie->child[ s[i] ] = new node_t();
		prefix_trie = prefix_trie->g( s[i] );
		i++;
	}
	prefix_trie->output.PB( id );
}

void init( node_t* root ){
	queue< node_t* > q;
	node_t *r, *s, *state;
	
	for( int i = 0; i < SIZE(alph); i++ ){
		char c = alph[i];
		if( (s=root->g(c)) != root ){
			s->failure = root;
			q.push( s );
		}
	}
	
	while( !q.empty() ){
		r = q.front(); q.pop();
		for( int i = 0; i < SIZE(alph); i++ ){
			char c = alph[i];
			if( (s=(r->g(c))) != NULL ){
				q.push( s );
				state = r->failure;
				
				while( state->g(c) == NULL ) state = state->failure;
				state = state->g(c);
				s->failure = state;
				
				s->n_output = (SIZE(state->output) ? (state) : (state->n_output));
			}
		}
	}
}

bool appear[1111];

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio(false);
	int k;
	cin >> k;
	
	while( k-- ){
		string s;
		cin >> s;
		node_t *automata = new node_t();
		int q;
		cin >> q;
		
		REP( i, q ){
			string w; cin >> w;
			add( automata, w, i );
			appear[i] = false;
		}
		automata->root = true;
		init(automata);
		
		REP( i, SIZE(s) ){
			
			//while( automata->g(s[i]) == NULL ) automata = automata->failure;
			automata = automata->next(s[i]);
			
			node_t *aux = automata;
			
			while( aux != NULL ){
				REP( j, SIZE(aux->output) ) appear[ aux->output[j] ] = true;
				aux = aux->n_output;
			}
			
		}
		REP( i, q ) if( appear[i] ) cout << "y\n"; else cout << "n\n";
		
	}
	
	
	return 0;
}

























