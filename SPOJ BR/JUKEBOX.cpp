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
#include <iomanip>
#include <numeric> 
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFF

#define FILL(X, V) memset( (X), (V), sizeof((X)) )
#define TI(X) __typeof((X).begin())
#define ALL(V) (V).begin(), (V).end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N - 1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); ++i)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN(double a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int CMP(double a, double b) { return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 33
string song[MAXN], art[MAXN]; int n;
vector< string > subs[ MAXN ];
string art_name[ 6 ];
vector< string > art_subs[ 6 ];
map< string, int > art_id;  int id; 
map< string, int > subs_ct;

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );
	
	while( cin >> n && n ){
	
		art_id.clear(); id = 0;
		subs_ct.clear();
		set< string > aux;
		
		REP( i, n ){
			subs[i].clear();
			cin >> song[i] >> art[i];
			if( art_id.find( art[i] ) == art_id.end() ){
				art_name[ id ] = art[i];
				art_subs[ id ].clear();
				aux.clear();
				FOR( j, 1, SIZE(art_name[ id ]) ) FOR( k, 0, SIZE(art_name[id])-j ){ 
					string ss = art_name[id].substr( k, j );
					if( aux.insert( ss ).second ) art_subs[id].PB( ss );
				}
				art_id[ art[i] ] = id++;
			}
			aux.clear();
			FOR( j, 1, SIZE(song[i]) ) FOR( k, 0, SIZE(song[i])-j ){
				string ss = song[i].substr( k, j );
				if( aux.insert( ss ).second ){ subs[i].PB( ss ); subs_ct[ ss ]++; }
			}
		}
		
		int ans = INF;
		int mx[id];
		REP( mask, (1<<id) ){
			REP( pos, id ) if( mask & (1<<pos) ) REP( j, SIZE( art_subs[pos] ) ) subs_ct[ art_subs[pos][j] ]++;
			
			int cur = 0; FILL( mx, 0 );
			int done = 0;
			REP( pos, n ){
				int aid = art_id[ art[pos] ];
				bool ok = false;
				REP( j, SIZE( subs[pos] ) ) if( subs_ct[ subs[pos][j] ] == 1 ){
					cur += SIZE( subs[pos][j] );
					done++;
					//cout << "\t" << subs[pos][j] << "\n";
					mx[ aid ] = MAX( mx[aid], SIZE( subs[pos][j] ) );
					ok = true;
					break;
				}
				if( !ok ) mx[ aid ] = INF;
			}
			REP( pos, id ) if( (mx[pos] == INF) && !(mask & (1<<pos)) ){ cur = INF; goto hell; }
			REP( pos, id ) if( mask & (1<<pos) ){
				bool ok = false;
				if( mx[pos] != -1 ) ok = true;
				
				REP( j, SIZE( art_subs[pos] ) ) if( subs_ct[ art_subs[pos][j] ] == 1 ){
					if( mx[pos] == INF ){
						cur += SIZE( art_subs[pos][j] );
						done++;
						//cout << "\t" << art_subs[ pos ][ j ] << "\n";
					} else if( SIZE(art_subs[pos][j]) < mx[pos] ) {
						//cout << "\t" << art_subs[ pos ][ j ] << "\n";
						cur = cur - mx[pos] + SIZE( art_subs[pos][j] );
					}
					ok = true;
					break;
				}
				if( !ok ){ cur = INF; break; }
			}
		hell:
		//cout << " --------- " << cur << " \n";
			REP( pos, id ) if( mask & (1<<pos) ) REP( j, SIZE( art_subs[pos] ) ) subs_ct[ art_subs[pos][j] ]--;
			if( done == n ) ans = MIN( ans, cur );
		}
		cout << ans << "\n";
		
	}
	
	return 0;
}




















