/*
 *  Problema:
 *  Tecnica Utilizada:  
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

#include <map> 
#include <set> 
#include <list>
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
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define pb push_back
#define mp make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int k, n, m, q;
	string name;
	cin >> k >> n >> m >> q;
	
	REP( i, n ) cin >> name;
	
	map< string, list< pair<string, int> > > comp;
	
	cin.ignore();
	REP( i, m ){
		
		string line, bsc;
		char chr;
		int amt;
		
		getline( cin, line );
		istringstream in( line );
		
		in >> name;
		name = name.substr( 0, SIZE(name)-1 );
		while( in >> bsc >> amt ){
			comp[name].pb( mp( bsc, amt) );
			if( !(in>>chr) ) break;
		}	
	}
	
	map< string, int > allie[k];
	
	while( q-- ){
		
		int al;
		string itm;
		cin >> al >> itm;
		al--;
		allie[al][itm]++;
		
		FORIT( i, comp ){
			bool flag = true;
			FORIT( ndd, i->second ){
				TI( allie[al] ) cr = allie[al].find( ndd->first );
				if( cr == allie[al].end() || allie[al][ndd->first] < ndd->second ){
					flag = false;
					break;
				}
			}
			if( flag ){
				FORIT( ndd, i->second ){
					allie[al][ndd->first] -= ndd->second;
					if( allie[al][ndd->first] == 0 ) allie[al].erase( ndd->first );
				}
				allie[al][i->first]++;
				break;
			}
		}
	}
	
	REP( i, k ){
		cout << SIZE( allie[i] ) << "\n";
		FORIT( x, allie[i] ) cout << x->first << " " << x->second << endl;
	}
	
	return 0;
}
