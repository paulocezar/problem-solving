#include <iostream>
#include <cstring>
#include <map>
#include <list>
#include <cmath>

using namespace std;

#define MAXV 205

int cap[MAXV]; 
list< int > graph[MAXV];
int flow[MAXV][MAXV];
char used[MAXV];

char has_path( int u ){
	
	list< int >::iterator v;
	if( u == 1 ) return 1;
	
	used[u] = 1;
	for( v = graph[u].begin(); v != graph[u].end(); v++ ){
		 if( used[*v] == 0 && flow[u][*v] > 0  ){
		 	if( has_path( *v ) ){
			 	flow[u][*v]--;
			 	flow[*v][u]++;
			 	used[u] = 0;
			 	return 1;
		 	}
		}
	}
	
	used[u] = 0;
	return 0;
}

int find_maxFlow(){

	int cur_flow = 0;

	while( has_path( 0 ) ) cur_flow++;
	return cur_flow;

}

int main(){

	int ncases, busCap, n, m, i, j, cid, neigh;
	int tm, hr, min, maxFlow;
	list< int >::iterator v;

	memset( used, 0, sizeof( used ) );

	scanf("%d", &ncases );
	while( ncases-- ){

		scanf("%d %d", &n, &m ); getchar();
		map< int, int > id;
		
		for( i = 0; i <= n+1; i++ )
			graph[i].clear();

		cid = n+2;
		for( i = 0; i < m; i++ ){
			scanf("%2d:%2d", &hr, &min );
			tm = hr*100 + min;
			if( id.find( tm ) == id.end() ){
				 graph[cid].clear();
				 id[tm] = cid;
				 cap[cid] = 1;
				 cid++;
			} else cap[id[tm]]++;
		}
		
		for( i = 2; i <= n+1; i++ ){
			 
			 graph[0].push_back( i );

			 scanf("%d", &neigh );
			 while( neigh-- ){
				scanf("%2d:%2d", &hr, &min );
				tm = hr*100 + min;
				if( id.find( tm ) != id.end() ){
                    cid = id[tm];
				    graph[i].push_back( cid );
					graph[cid].push_back( i );
                }
			 }
		}

		busCap = (int) ceil( (double)n/m );
		if( busCap == 0 ) busCap = 1;
		for( i = 2; i <= n+1; i++ ){
				flow[0][i] = 1;
				flow[i][0] = 0;
				for( v = graph[i].begin(); v != graph[i].end(); v++ )
					flow[i][*v] = 1, flow[*v][i] = 0;
		}

		map< int, int >::iterator it;
		for( it = id.begin(); it != id.end(); it++ ){
				flow[it->second][1] = cap[it->second] * busCap;
				flow[1][it->second] = 0;
				graph[it->second].push_front( 1 );
		}

		maxFlow = 0;
		maxFlow += find_maxFlow();
		
		while( busCap <= n && maxFlow < n ){
				j = (int) ceil( (double)(n-maxFlow)/m );
				if( j == 0 ) j = 1;
				busCap += j;
				for( it = id.begin(); it != id.end(); it++ )
					flow[it->second][1] += ( j * cap[it->second] );

				maxFlow += find_maxFlow();
		}

		printf("%d\n", busCap );
	}

	return 0;
}


