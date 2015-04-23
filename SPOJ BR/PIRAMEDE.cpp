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

#define MAXN 15

int rot[][3] = { {0,1,2}, {0,2,1}, {1,2,0} };

int dim[MAXN+2][3];
int dp[1<<MAXN][MAXN][3];
int N;

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t;
		
	cin >> t;
	while( t-- ){
		
		cin >> N;
		REP( i, N ){ 
			cin >> dim[i][0] >> dim[i][1] >> dim[i][2];
			sort( dim[i], dim[i]+3);
		}
				
		int lmask = 1<<N;
		
		int ans = 0;
		
		// Calcula todas as solucoes com apenas um bloco..
		for( int mask = 1, i = 0; mask < lmask; mask <<= 1, i++ ){
			REP( j, 3 ){
				dp[mask][i][j] = dim[i][rot[j][2]];
				if( dp[mask][i][j] > ans ) ans = dp[mask][i][j];
			}
		}
		
		FOR( mask, 1, lmask ) if( mask & (mask-1) ){   // Varia as 2^N combinaçoes de blocos.. exceto aquelas com apenas um bloco que ja foram calculadas
				REP( j, N ) if( mask & (1<<j) ){	   // Se o j-esimo bloco esta no conjunto sendo analisado..
					REP( k, 3 ) {					   // Considera colocar ele no topo da piramide.. usando todas as possiveis rotacoes
						dp[mask][j][k] = 0;
						int &X = dim[j][rot[k][0]];
						int &Y = dim[j][rot[k][1]];
						int &Z = dim[j][rot[k][2]];
						
						int nmask = mask ^ (1<<j); 					// Considerando os blocos restantes, a solucao para aquela rotacao do j-esimo bloco e a melhor
						REP( jj, N ) if( nmask & (1<<jj) ){			// solucao dos blocos restantes onde o bloco j pode ser colocado por cima + altura do bloco j
							REP( kk, 3 ) if( dim[jj][rot[kk][0]] >= X && dim[jj][rot[kk][1]] >= Y ){
								dp[mask][j][k] = MAX( dp[mask][j][k], Z + dp[nmask][jj][kk] );
							}
						}
						
						if( dp[mask][j][k] > ans ) ans = dp[mask][j][k];
					}
				}
		}
		
		cout << ans << "\n";
		
	}
	
	return 0;
}
