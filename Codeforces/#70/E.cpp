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

#define INF 10*10*10
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

int N, M;
int cap[2002][2002];
vector< int > gr[2002];
bool vis[2002];
int parent[2002];

int ds[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int augment( int u ){
	
	if( u == 1 ) return INF;
	vis[u] = true;
	
	REP( i, SIZE(gr[u]) ) if( !vis[gr[u][i]] && cap[u][gr[u][i]] ){
		int r = augment( gr[u][i] );
		if( r ){
			parent[ gr[u][i] ] = u;
			return MIN( r, cap[u][ gr[u][i] ] );
		}
	}
	
	return 0;
	
}

int maxflow(){
	int ans = 0;
	int flow = 0;
	
	parent[0] = -1;
	do{	
		ans += flow;
	
		REP( i, M ) vis[i] = false;
		flow = augment(0);
		
		if (!flow) return ans;
		
		int v = 1;
		while( v != 0 ){
			int u = parent[v];
			cap[u][v] -= flow;
			cap[v][u] += flow;
			v = u;
		}
	} while( flow );
	
	return ans;
}

int main( int argc, char* argv[] ){

	ios::sync_with_stdio( false );
	
	int dim, time_to_die;
	cin >> dim >> time_to_die;
	
	REP( i, 2*dim*dim + 2 ){
		gr[i].clear();
		REP( j, 2*dim*dim + 2 ) cap[i][j] = 0;
	}
	vector< string > labsci(dim), labcap(dim);
	
	int vert[dim][dim][2];
	int malfunc;
	
	N = 2;
	REP( i, dim ){
		cin >> labsci[i];
		REP( j, dim ) if( labsci[i][j] <= '9' && labsci[i][j] >= '1' ){
			cap[0][N] = labsci[i][j]-'0';
			gr[0].pb( N );
			gr[N].pb( 0 );
			vert[i][j][0] = N++;
		} else if( labsci[i][j] == 'Z' ) { malfunc = 100*i + j; labsci[i][j] = 'Y'; }
	}
		
	M = N;
	REP( i, dim ){
		cin >> labcap[i];
		REP( j, dim ) if( labcap[i][j] <= '9' && labcap[i][j] >= '1' ){
			cap[M][1] = labcap[i][j]-'0';
			gr[M].pb( 1 );
			vert[i][j][1] = M++;
		}
	}
		
	int die[dim][dim];
	REP( i, dim ) REP( j, dim ) die[i][j] = time_to_die+1;
	die[ malfunc/100 ][ malfunc%100 ] = 0;
	
	queue< int > q;
	q.push( malfunc );
	int x, y, nx, ny;
	while( !q.empty() ){
		x = q.front(); q.pop();
		y = x%100; x /= 100;
		
		REP( i, 4 ){
			nx = x+ds[i][0];
			ny = y+ds[i][1];
			if( nx >= 0 && nx < dim && ny >= 0 && ny < dim && labsci[nx][ny] != 'Y' && die[nx][ny] > die[x][y]+1 ){
				die[nx][ny] = die[x][y]+1;
				q.push( 100*nx + ny );
			}
		}
	}
		
	int reach[dim][dim];
	REP( i, dim ) REP( j, dim ) if( labsci[i][j] <= '9' && labsci[i][j] >= '1' ){
		
		REP( ii, dim ) REP( jj, dim ) reach[ii][jj] = time_to_die+1;
		reach[i][j] = 0;
		
		if( labcap[i][j] <= '9' && labcap[i][j] >= '1' ){
			cap[ vert[i][j][0] ][ vert[i][j][1] ] = INF;
			gr[ vert[i][j][0] ].pb( vert[i][j][1] );
			gr[ vert[i][j][1] ].pb( vert[i][j][0] );
		}
		
		q.push( 100*i + j );
		while( !q.empty() ){
			x = q.front(); q.pop();
			y = x%100; x/= 100;
			
			REP( dd, 4 ){
				nx = x+ds[dd][0];
				ny = y+ds[dd][1];
				if( nx >= 0 && nx < dim && ny >= 0 && ny < dim && labsci[nx][ny] != 'Y' && reach[nx][ny] > reach[x][y]+1 ){
					if( labcap[nx][ny] <= '9' && labcap[nx][ny] >= '1' ){
						if( reach[x][y]+1 <= die[nx][ny] ){
							cap[ vert[i][j][0] ][ vert[nx][ny][1] ] = INF;
							gr[ vert[i][j][0] ].pb( vert[nx][ny][1] );
							gr[ vert[nx][ny][1] ].pb( vert[i][j][0] );
						}
					} 
					if( reach[x][y]+1 < die[nx][ny] ){
						reach[nx][ny] = reach[x][y]+1;
						q.push( 100*nx + ny );
					}
				}
			}
		}	
	}	
	
	cout << maxflow() << endl;
	
	return 0;
}
