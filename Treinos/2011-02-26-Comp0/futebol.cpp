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

#define MAXT 16
string names[MAXT];
double p[MAXT][MAXT], ans[2][MAXT];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int t;
	cin >> t;
	FOR( ct, 1, t+1 ){
		
		REP( i, MAXT ) { cin >> names[i]; ans[0][i] = 1.0; }
		REP( i, MAXT ) REP( j, MAXT ){ cin >> p[i][j]; p[i][j] /= 100.0; }
		
		int old = 0, cur = 1;
		for( int sz = 2; sz <= MAXT; sz *= 2 ){
			
			REP( i, MAXT ) ans[cur][i] = 0;
			int step = sz/2;
			
			for( int fr = 0; fr < MAXT; fr += sz ){
				int to = fr+step;
				
				int i = fr;
				while( i < to ){
					int j = to;
					while( j < to+step ){
						//cout << i << " " << j << endl; cout << p[i][j] << " " << p[j][i] << endl;
						ans[cur][i] += ans[old][i]*ans[old][j]*p[i][j];
						ans[cur][j] += ans[old][j]*ans[old][i]*p[j][i];	
						j++;
					}
					i++;
				}
				
			}
			//REP( i, MAXT ) cout << names[i] << " " << fixed << setprecision(2) << 100.0*ans[old][i] << "\n";
			
			old = !old;
			cur = !cur;
		}
		cout << "Cenario #" << ct << ":\n";
		REP( i, MAXT ){
			cout << left << setw(11) << names[i];
			if( int(100.0*ans[old][i]) < 100 ) cout << " ";
			if( int(100.0*ans[old][i]) < 10 ) cout << " ";
			cout << fixed << setprecision(2) << 100.0*ans[old][i] << "\n";
		}
		cout << "\n";	
	}
	
	return 0;
}


































