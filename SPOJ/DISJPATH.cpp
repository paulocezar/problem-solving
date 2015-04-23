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

	ios::sync_with_stdio( false );
	
	int K, N, tc = 1;
	string line;
	
	cin >> K >> N; cin.ignore();
	while( K+N ){
		
		cout << "Case " << tc++ << ":\n";
		
		int flow[2*N+1][2*N+1];
		int cap[2*N+1][2*N+1];
		FILL( flow, 0 );
		FILL( cap, 0 );
		
		// i = out ... N+i = in
		FOR( i, 1, N+1 ){
			cap[N+i][i] = 1;
			
			getline( cin, line );
			istringstream in( line );
			int v;
			while( in >> v ){
				cap[i][v+N] = 1;
			}
		}
		
		int s = 1;
		int t = N+2;
		int parent[2*N+1];
		int q[2*N+1];
		int beg, end;
		
		int maxflow = 0;
		while( maxflow < K ){
			
			FILL( parent, -1 );
			beg = end = 0; q[end++] = s;
			while( beg != end ){
				int u = q[beg++];
				if( u == t ) break;
				FOR( v, 2, 2*N+1 ) if( parent[v] == -1 && cap[u][v] > flow[u][v] ){
					parent[v] = u;
					q[end++] = v;
				}
			}
			
			if( parent[t] == -1 ) break;
			int v = t;
			while( parent[v] != -1 ){
				int u = parent[v];
				flow[u][v]++;
				flow[v][u]--;
				v = u;
			}
			maxflow++;
			
		}
		
		if( maxflow == K ){
				
				while( K-- ){
					
					cout << 1;
					
					int u = 1;
					nxt:
					FOR( v, 2, 2*N+1 ) if( flow[u][v] == 1 ){
						if( v <= N ) cout << " " << v;
						flow[u][v] = 0;
						u = v;
						goto nxt;
					}
					cout << " 2\n";
				}
				
		} else cout << "Impossible\n";
		
		cin >> K >> N; cin.ignore();
		if( K+N ) cout << "\n";
		else break;
	}
	
	return 0;
}


































