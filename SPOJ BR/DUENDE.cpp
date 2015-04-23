#include <iostream>
#include <queue>
#include <list>
#define MAX_V  100
#define PRETO  0
#define BRANCO 1
#define INF 0x3f3f3f3f

using namespace std;

int main(){
    
    
    int L, C, v, nro, origem;
    int nrDestinos = 0, destinos[MAX_V];
    list< int > grafo[MAX_V];
    int cor[MAX_V];
    int dist[MAX_V];
    
    scanf("%d %d", &L, &C );
    
    for( int i = 0; i < L; i++ ){
         for( int j = 0; j < C; j++ ){
              scanf("%d", &nro );
              
              v = i*C + j ;
              
              if( nro == 0 )
                  destinos[nrDestinos++] = v;
              else if( nro == 2 )
                   cor[v] = PRETO;
              else if( nro == 3 )
                   origem = v;
          
              if( nro ^ 2 )
               cor[v] = BRANCO;

              dist[v] = INF;
              
              
              if( cor[v] ){

                  if( i )
                      if( cor[v-C] ){
                          grafo[v].push_back( v-C );
                          grafo[v-C].push_back( v );
                      }
                  
                  if( j )
                      if( cor[v-1] ){
                          grafo[v].push_back( v-1 );
                          grafo[v-1].push_back( v );
                      }
              } 
         }
    }
    
     dist[origem] = 0;
     cor[origem] = PRETO;
     queue<int> fila;
     fila.push( origem );
          
     while( !fila.empty() ){
            
        int u = fila.front(); fila.pop();

        for( list<int>::iterator it = grafo[u].begin(); it != grafo[u].end(); it++ ){
              if( cor[*it] ){
                  cor[*it] = PRETO;
                  fila.push( *it );
                  dist[*it] = dist[u] + 1;
              }
       }
    }
    
   int j = INF;
   for( v = 0; v < nrDestinos; v++ )
        if( dist[destinos[v]] < j )
		    j = dist[destinos[v]];
		    
   printf("%d", j );

   return 0;    
}
