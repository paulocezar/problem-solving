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

#define MAXN 1001
int vis[MAXN][MAXN];
int parent[MAXN][MAXN];

int enc( int A, int B ){
	return (10000*A + B);
}

void printans( int i, int j ){
	//cout << ":: " << i << " " << j << " ";
	if( parent[i][j] < 0 ) return;
	int wth = parent[i][j] / 10;
	int wut = parent[i][j] % 10;
	//cout << wth << " " << wut << endl;
	switch( wut ){
		case 1: printans(wth,j); cout << "fill A\n"; break;
		case 2: printans(i,wth); cout << "fill B\n"; break;
		case 3: printans(wth,j); cout << "empty A\n"; break;
		case 4: printans(i,wth); cout << "empty B\n"; break;
		case 5: printans(i+(j-wth),wth); cout << "pour A B\n"; break;
		case 6: printans(wth,j+(i-wth)); cout << "pour B A\n"; break;
	}
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	FILL( vis, 0 ); int cvis = 0;
	parent[0][0] = -1;
	
	int A, B, N, AA, BB;
	while( cin >> A >> B >> N ){
		cvis++;
		vis[0][0] = cvis;
		
		queue< int > q;
		q.push( enc( A, 0 ) ); vis[A][0] = cvis; parent[A][0] = 1;
		q.push(	enc( 0, B ) ); vis[0][B] = cvis; parent[0][B] = 2;
			
		while( !q.empty() ){
			AA = q.front(); q.pop();
			BB = (AA%10000); AA /= 10000;
			//cout << AA << " " << BB << endl;
			if( BB == N ){ 
				printans( AA, BB ); cout << "success\n";
				break;
			}
			//cout << A << " " << BB << endl;
			if( vis[A][BB] != cvis ){	
				vis[A][BB] = cvis;
				parent[A][BB] = 10*AA + 1;
				q.push( enc( A, BB ) );
			}
			
			//cout << AA << " " << B << endl;
			if( vis[AA][B] != cvis ){	
				vis[AA][B] = cvis;
				parent[AA][B] = 10*BB + 2;
				q.push( enc( AA, B ) );
			}
			
			//cout << 0 << " " << BB  << endl;
			if( vis[0][BB] != cvis ){	
				vis[0][BB] = cvis;
				parent[0][BB] = 10*AA + 3;
				q.push( enc( 0, BB ) );
			}

			//cout << AA << " " << 0 << endl;
			if( vis[AA][0] != cvis ){	
				vis[AA][0] = cvis;
				parent[AA][0] = 10*BB + 4;
				q.push( enc( AA, 0 ) );
			}
			
			//cout << AA-MIN(B-BB, AA) << " " << BB+MIN(B-BB, AA) << endl;
			int NA = AA-MIN(B-BB, AA); 
			int NB = BB+MIN(B-BB, AA);
			if( vis[NA][NB] != cvis ){	
				vis[NA][NB] = cvis;
				parent[NA][NB] = BB*10 + 5;
				q.push( enc( NA, NB ) );
			}
			
			//cout << AA+MIN(BB, A-AA) << " " << BB-MIN(BB, A-AA) << endl;
			NA = AA+MIN(A-AA, BB);
			NB = BB-MIN(A-AA, BB);
			if( vis[NA][NB] != cvis ){	
				vis[NA][NB] = cvis;
				parent[NA][NB] = AA*10 + 6;
				q.push( enc( NA, NB ) );
			}
			
		}
	}
	
	return 0;
}


































