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

int ds[][2] = { {1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1} };

string ans[5] = { "11111", "01111", "00 11", "00001", "00000" };
string grid[5];
int minMoves;

bool ok( int x, int y ){ return (x>=0)&&(x<5)&&(y>=0)&&(y<5); }

void bt( int mov, int x, int y ){
	
	REP( i, 5 ) REP( j, 5 ) if( grid[i][j] != ans[i][j] ) goto hell;
	if( mov < minMoves ) minMoves = mov;
	return; 
hell:
	
	if( mov == 10 ) return;

	REP( i, 8 ){
		int nx = x+ds[i][0];
		int ny = y+ds[i][1];
		if( ok( nx, ny ) ){
			grid[x][y] ^= grid[nx][ny];
			grid[nx][ny] ^= grid[x][y];
			grid[x][y] ^= grid[nx][ny];
			bt( mov+1, nx, ny );
			grid[x][y] ^= grid[nx][ny];
			grid[nx][ny] ^= grid[x][y];
			grid[x][y] ^= grid[nx][ny];	
		}
	}
	
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int sts, x, y;
	
	cin >> sts;
	cin.ignore();
	
	while( sts-- ){
		
		minMoves = INF;
		REP( i, 5 ) getline( cin, grid[i] );
		REP( i, 5 ) REP( j, 5 ) if( grid[i][j] == ' ' ){ x = i; y = j; break; }
		
		bt( 0, x, y );
		
		if( minMoves != INF ) cout << "Solvable in " << minMoves << " move(s).\n";
		else cout << "Unsolvable in less than 11 move(s).\n";
		
	}
	
	return 0;
}
