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

int xp[3];
char like[7][7];

vector< int > team[3];
int dif, lk;

void bt( int cur ){
	
	if( cur == 7 ){
		
		int sz[3];
		REP( i, 3 ) if( SIZE(team[i]) == 0 ) return; else sz[i] = SIZE(team[i]);
		sort( sz, sz+3 ); 
		
		int curDif = INF;
		
		REP( i, 3 ) REP( j, 3 ) if( i != j ){
			REP( k, 3) if( k != i && k != j ){
				curDif = MIN( curDif, MAX( xp[0]/sz[i], MAX( xp[1]/sz[j], xp[2]/sz[k] ) ) - MIN( xp[0]/sz[i], MIN( xp[1]/sz[j], xp[2]/sz[k] ) ) );
			}
		}
		//cout << curDif << endl;
		
		if( curDif < dif ){
			dif = curDif;
			lk = 0;
		}
		if( curDif == dif ){
			
			int ct = 0;
			REP( i, 3 ){
				
				REP( j, SIZE(team[i]) )
					REP( k, SIZE(team[i]) )
						ct += like[ team[i][j] ][ team[i][k] ];	
			}
			
			if( ct > lk ) lk = ct;
		}
		
		return;
	}
	
	REP( i, 3 ){
		team[i].pb( cur );
		bt( cur+1 );
		team[i].pop_back();
	}
	
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	map< string, int > id;
	id["Troll"] = 0;
	id["Anka"] = 1;
	id["Chapay"] = 2;
	id["Cleo"] = 3;
	id["Dracul"] = 4;
	id["Snowy"] = 5;
	id["Hexadecimal"] = 6;
	
	FILL( like, 0 );
	
	int n;
	cin >> n;
	REP( i, n ){
		string a, likes, b;
		cin >> a >> likes >> b;
		like[id[a]][id[b]] = 1;
	}
	cin >> xp[0] >> xp[1] >> xp[2];
	sort( xp, xp+3 );
	
	dif = INF;
	lk = 0;
	
	REP( i, 3 ) team[i].clear();
	
	bt( 0 );
	cout << dif << " " << lk << "\n";
	
	return 0;
}
