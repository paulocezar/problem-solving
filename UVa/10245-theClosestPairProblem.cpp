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

#define MAXN 10001

pair< double, double > point[MAXN];

struct comp{
	bool operator()( const pair<double,double>& a, const pair<double,double>& b ) const {
		if( a.second != b.second ) return a.second < b.second;
		return a.first < b.first;
	}
};

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int N;
	cin >> N;
	while( N ){
		REP( i, N ) cin >> point[i].first >> point[i].second;
		
		// Ordena os pontos pelo X que vai ser o eixo percorrido no line sweep
		sort( point, point+N );
		
		// Comeca a menor distancia com um valor grande o suficiente
		double h = 1e10;
		
		// Conjunto de pontos ativos, usa uma função que ordena eles pelo y
		set< pair<double,double>, comp > active;
		int pactive = 0;
		
		// Começa a varrer o eixo X
		REP( i, N ){
			
			// Tira os pontos que estavam no conjuntos de ativos e nao tem mais chance de melhorarem a menor distancia
			while( pactive < i && point[pactive].first < point[i].first-h ){ 
				active.erase( point[pactive] );
				pactive++;
			}
			
			// Limita os pontos a serem verificados numa box de interesse
			set< pair<double,double> >:: iterator lb,ub;
			lb = active.lower_bound( make_pair( -1000000, point[i].second-h) );
			ub = active.upper_bound( make_pair( +1000000, point[i].second+h) );
			
			// Verifica se algum dos pontos na box melhora a distancia
			while( lb != ub ){
				double hh = sqrt( SQR( point[i].second-(lb->second) ) + SQR( point[i].first-(lb->first) ) );
				if( hh < h ) h = hh;
				lb++;
			}
			
			// Adiciona o ponto atual no conjunto de ativos
			active.insert( point[i] );			
		}
		
		if( h > 10000.0 ) cout << "INFINITY\n";
		else cout << fixed << setprecision( 4 ) << h << "\n";
					
		cin >> N;
	}
	
	return 0;
}
