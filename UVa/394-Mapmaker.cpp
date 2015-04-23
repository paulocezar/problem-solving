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

struct arr{
	int B, D, Co, sz;
	int L[10], U[10], C[10];
	int get( vector< int >& idx ){
		int ans = Co;
		REP( i, D ) ans += C[i]*idx[i];
		return ans;
	}
};

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int N, R;
	cin >> N >> R;
	map< string, arr > array;
	
	string name;
	REP( i, N ){
		cin >> name;
		arr aux;
		cin >> aux.B >> aux.sz >> aux.D;
		
		REP( j, aux.D ) cin >> aux.L[j] >> aux.U[j];
		aux.C[aux.D-1] = aux.sz;
		
		aux.Co = aux.B - aux.C[aux.D-1]*aux.L[aux.D-1];
		RREP( j, aux.D-1 ){
			aux.C[j] = aux.C[j+1]*( aux.U[j+1] - aux.L[j+1] +1 );
			aux.Co -= aux.C[j]*aux.L[j];
		}
		array[name] = aux;
	}
	
	vector< int > idx(10); 
	while( R-- ){
		cin >> name;
		N = array[name].D;
		cout << name << "[";
		REP( i, N ){ if( i ) cout << ", "; cin >> idx[i]; cout << idx[i]; }
		cout << "] = " << array[name].get( idx ) << "\n";
	}
	
	return 0;
}
