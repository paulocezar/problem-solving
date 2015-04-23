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

int gr[222][222];
map< string, int > pt;
string name;

bool comp( const string& a, const string& b  ){
	if( gr[0][pt[a]] != gr[0][pt[b]] ) return gr[0][pt[a]] > gr[0][pt[b]];
	return a < b;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );

	string sna, snb, act, trsh;
	int na, nb;
	cin >> name;
	
	int n;
	cin >> n;
	
	FILL( gr, 0 );
	
	int cr = 1;
	pt[name] = 0;
	
	while( n-- ){
		cin >> sna;
		cin >> act;
		
		if( pt.find(sna) == pt.end() ) pt[sna] = cr++;
		na = pt[sna];
		
		if( act == "posted"){
			cin >> trsh;
			cin >> snb;
			cin >> trsh;
			snb = snb.substr( 0, SIZE(snb) - 2 );
			
			if( pt.find(snb) == pt.end() ) pt[snb] = cr++;
			nb = pt[snb];
			
			gr[na][nb]+=15;
			gr[nb][na]+=15;
		} else if( act == "commented" ){
			cin >> trsh;
			cin >> snb;
			cin >> trsh;
			snb = snb.substr( 0, SIZE(snb) - 2 );
			
			if( pt.find(snb) == pt.end() ) pt[snb] = cr++;
			nb = pt[snb];
			
			gr[na][nb] += 10;
			gr[nb][na] += 10;
		} else {
			cin >> snb;
			cin >> trsh;
			snb = snb.substr( 0, SIZE(snb) - 2 );
			
			if( pt.find(snb) == pt.end() ) pt[snb] = cr++;
			nb = pt[snb];
			
			gr[na][nb] += 5;
			gr[nb][na] += 5;
		}
		
	}
	
	vector< string > out;
	FORIT( xx, pt ) out.pb( xx->first );
	
	sort( out.begin(), out.end(), comp );
	
	REP( i, SIZE(out) ) if( out[i] != name ) cout << out[i] << endl;
	
	return 0;
}
