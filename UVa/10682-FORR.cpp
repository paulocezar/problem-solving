#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <queue>
#include <stack>
#include <utility>
#include <cstring>
#include <climits>
#include <algorithm>

#define INF INT_MAX
#define MAXC 510
#define MAXV 1001

using namespace std;

typedef pair< int, int > edge;

string cidades[MAXC];
vector< edge > grafo[MAXC];

int used[MAXC*MAXV], usednow;
int parent[MAXC*MAXV];
int origem, destino;

void printpath( int stt ){
	
	int u = (stt+1) /  1000;
	if( u == origem ){
		printf("%s", cidades[origem].c_str() ); return;
	} else {
		printpath( parent[stt] );
		printf(" %s", cidades[u].c_str() );
	}
}

int main(){

	int n, i, c, peso;
	int u, vel, cur, nxt;
	char a[100], b[100];
	bool flag = false;
	
	memset( used, 0, sizeof(used) );
	usednow = 0;
	
	while( scanf("%d", &n) == 1 && n > 0 ){

		map< string, int > hash;
		c = 1;
		
		if( flag ) printf("\n");
		else flag = true;
		
		for( i = 0; i < n; i++ ){
			
            scanf(" %s %s %d", a, b, &peso );
            
			if( hash.find( a ) == hash.end() ){
				hash[a] = c;
				grafo[c].clear();
				cidades[c] = a;
				c++;
			}
			
			if( hash.find( b ) == hash.end() ){
				hash[b] = c;
				grafo[c].clear();
				cidades[c] = b;
				c++;
			}

			grafo[ hash[a] ].push_back( make_pair( hash[b], peso ) );
			grafo[ hash[b] ].push_back( make_pair( hash[a], peso ) );
		}
		scanf(" %s %s", a, b );
		
		if( hash.find( a ) == hash.end() || hash.find( b ) == hash.end() ){
		    printf("No valid route.\n");
		    continue;
		}
		for( i = 1; i < c; i++ ) sort( grafo[i].begin(), grafo[i].end() );
		origem = hash[a];
		destino = hash[b];
		
		usednow++; 
		queue< int > q;
		q.push( (1000*origem) - 1 );  
		used[(1000*origem)-1] = usednow;
		while( !q.empty() ){
			cur = q.front() + 1; q.pop();
			u = cur / 1000;
			vel = cur%1000; 
			
			if( u == destino ){
				
				printpath( cur-1 );
				goto hell;
			}
			
			for( int s = 0; s < (int)grafo[u].size(); s++ ) if( vel <= grafo[u][s].second ){
				nxt = 1000*grafo[u][s].first + max(vel, grafo[u][s].second) - 1;
				
				if( used[nxt] != usednow ){
					q.push( nxt );
					used[nxt] = usednow;
					parent[nxt] = cur-1;
				}
			}
			
		}
		printf("No valid route.\n");
		continue;
		
	hell:
		printf("\n");
		
	}
	return 0;
}




