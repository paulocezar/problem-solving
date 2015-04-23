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

#define MAXN 55

int N, M, A;
int cap[MAXN][MAXN];
int parent[MAXN];
int q[MAXN];

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	cin >> N >> M >> A;	
	while( N+M+A ){
		
		FOR( i, 1, N+1 ) FOR( j, 1, N+1 ) cap[i][j] = 0;
		
		int o, d, c;
		REP( i, M ){
			cin >> o >> d >> c;
			cap[o][d] += c;
		}
		
		vector< pair<int,int> > paths;
		do{
			
			FILL( parent, -1 );
			parent[1] = 0;
			
			int beg = 0, end = 0;
			q[end++] = 1;
			while( beg != end ){
				o = q[beg++];
				RFOR( i, N+1, 1 ) if( cap[o][i] && parent[i] == -1 ){
					parent[i] = o;
					q[end++] = i;
					if( i == N ) goto hell;
				}
			}
			
			hell:
				o = N;
				int flow = INF;
				int days = 0;
				while( parent[o] > 0 ){
					days++;
					flow = MIN( flow, cap[parent[o]][o] );
					o = parent[o];
				}
				if( o == 1 ){
					paths.pb( mp( days, flow ) );
					o = N;
					while( parent[o] > 0 ){
						cap[parent[o]][o] -= flow;
						o = parent[o];
					}
				}
		} while( parent[N] != -1 );
		
		sort( paths.begin(), paths.end() );
		int ans = 0;
		while( A > 0 ){
			for( int i = 0; i < SIZE(paths) && paths[i].first <= ans; i++ )	 A -= paths[i].second;			
			ans++;
		}
		cout << ans-1 << "\n";
		
		cin >> N >> M >> A;
	}
	
	return 0;
}
