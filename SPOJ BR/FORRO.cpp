#include<iostream>
#include<map>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<list>
#include<queue>
#include<stack>
#include<utility>
#include<cstring>
#include<climits>

#define INF INT_MAX
#define MAXC 510

using namespace std;

typedef pair< int, int > edge;
typedef pair< int, pair< int, pair< int, int > > > data;

string cidades[MAXC];
list< edge > grafo[MAXC];

char used[MAXC];
int parent[MAXC];
int origem, destino;

void printpath( int u ){
           
           if( parent[u] == -1 ) printf("%s", cidades[u].c_str() );
           else { printpath( parent[u] ); printf(" %s", cidades[u].c_str() ); }
}


int main(){

	int n, i, c, peso;
	int u, p, vel, d;
	char _a[50], _b[50];
	string a, b;
	bool flag = false;
	
	while( scanf("%d\n", &n) != EOF ){

		map< string, int > hash;
		c = 1;
		
		if( flag ) printf("\n\n");
		else flag = true;
		
		for( i = 0; i < n; i++ ){
			
            scanf("%s %s %d\n", &_a, &_b, &peso );
            a = string( _a );
            b = string( _b );
			
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

        scanf("%s %s\n", &_a, &_b );
        a = string( _a );
        b = string( _b );
            
		if( hash.find( a ) == hash.end() || hash.find( b ) == hash.end() ){
		    printf("No valid route.");
		    continue;
		}
		
		origem = hash[a];
		destino = hash[b];
		

        for( i = 1; i < c; i++ ) parent[i] = INF;
		

		priority_queue< data, vector< data >, greater< data >  > q;
		q.push( make_pair( 0, make_pair( -1, make_pair( origem, 0 ) ) ) );
		
		memset( used, 0, sizeof( used ) );
		
        list< edge >::iterator v;
		
        while( !q.empty() ){
               d = q.top().first;
               p = q.top().second.first;
               u = q.top().second.second.first;
               vel = q.top().second.second.second; q.pop();
               
               parent[u] = p;
               if( u == destino ) break;
               used[u] = 1;
       
               for( v = grafo[u].begin(); v != grafo[u].end(); v++ ){
                    if( !used[v->first] && v->second >= vel ){
                        if( v->first == destino ) d = -1;
                        q.push( make_pair( d+1, make_pair( u, make_pair( v->first,  v->second ) ) ) );
                        if( v->first == destino ) break;
                    }
               }
        }
		
		if( parent[destino] == INF ) printf("No valid route.");
        else printpath( destino  );             

	}
	return 0;
}




