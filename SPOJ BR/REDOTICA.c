#include <stdio.h>
#include <stdlib.h>
#define MAX_V 101
#define INF   0x3f3f3f3f
#define NIL    0

int grafo[MAX_V][MAX_V];
int key[MAX_V];
int pai[MAX_V];
int queue[MAX_V];

int getMin(){
 
    int i;
    int min = INF;
    int u;
    
    for( i = 1; i <= grafo[0][0]; i++ )
         if( queue[i] )
             if( key[i] < min ){
                 u = i;
                 min = key[i];
             }
             
    return u;
    
}

void mstPrim( int r ){
         
         int u, v;
         
         for( u = 1; u <= grafo[0][0]; u++ ){
              key[u] = INF;
              pai[u] = NIL;              
         }
         
         key[r] = 0;
             
         for( u = 1; u <= grafo[0][0]; u++ )
              queue[u] = 1;
         
         queue[0] = grafo[0][0];
         
         while( queue[0] ){
             
             u = getMin();
             queue[u] = 0;
             queue[0]--;
             
             for( v = 1; v <= grafo[0][0]; v++ )   
                if( grafo[u][v] )
                    if( queue[v] && grafo[u][v] < key[v] ){
                        pai[v] = u;
                        key[v] = grafo[u][v];
                    }
                
         }

}


int main(){
    
    int m, x, y, z, i, teste = 1;
    
    scanf("%d %d", &grafo[0][0], &m );
    while( grafo[0][0] ){

           for( i = 1; i <= grafo[0][0]; i++ )
                for( x = 1; x <= grafo[0][0]; x++ )
                     grafo[i][x] = 0;
                     
           for( i = 0; i < m; i++ ){
                scanf("%d %d %d", &x, &y, &z );
                grafo[x][y] = grafo[y][x] = z;
           }
           
           mstPrim( 1 );
           
           printf("Teste %d\n", teste++);
           for( i = 1; i <= grafo[0][0]; i++ ){
                for( x = 1; x <= grafo[0][0]; x++ ){
                     if( grafo[i][x] && ( pai[x] == i || pai[i] == x ) )
                         printf("%d %d\n", i > x ? x, i : i, x );
                         grafo[i][x] = grafo[x][i] = 0;
                }           
           }
           printf("\n");
                


    scanf("%d %d", &grafo[0][0], &m );                      
    }
    
    
    
    return 0;    
}
