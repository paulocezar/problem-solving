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
#include <iomanip>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) typeof(X.begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

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
	
	string spc = "         ";
	string name;
	cout << "         NAME                     SOUNDEX CODE\n";
	while( cin >> name ){
		cout << spc << name;
		FOR( i, SIZE(name), 25 ) cout << " ";
		int len = -1;
		int i = 0;
		int lst = -1;
		
		while( len < 3 && i < SIZE(name) ){
			switch( name[i] ){
				case 'B': case 'P': case 'F': case 'V': 
				if( lst != 1 ){ if( lst == -1 ) cout << name[0]; else cout << "1"; len++; lst = 1; }
				i++; 
				break;
				case 'C': case 'S': case 'K': case 'G': case 'J': case 'Q': case 'X': case 'Z':
				if( lst != 2 || lst == -1 ){ if( lst == -1 ) cout << name[0]; else cout << "2"; len++; lst = 2; }
				i++; 
				break;
				case 'D': case 'T':
				if( lst != 3 || lst == -1 ){ if( lst == -1 ) cout << name[0]; else cout << "3"; len++; lst = 3; }
				i++; 
				break;
				case 'L':
				if( lst != 4 || lst == -1 ){ if( lst == -1 ) cout << name[0]; else cout << "4"; len++; lst = 4; }
				i++; 
				break;
				case 'M': case 'N':
				if( lst != 5 || lst == -1 ){ if( lst == -1 ) cout << name[0]; else cout << "5"; len++; lst = 5; }
				i++; 
				break;
				case 'R':
				if( lst != 6 || lst == -1 ){ if( lst == -1 ) cout << name[0]; else cout << "6"; len++; lst = 6; }
				i++; 
				break;
				default:
				if( lst == -1 ){ cout << name[0]; len++; }
				lst = 11;
				i++;
				break;
			}
		}
		if( len < 3 ) FOR( i, len, 3 ) cout << "0";
		cout << endl;		
	}
	cout << "                   END OF OUTPUT\n";
	
	return 0;
}
