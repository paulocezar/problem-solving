#include <stdio.h>
#include <stdlib.h>

int grafo[51][51];
int visitado[51];
int visitou[51];
int podeVisitar[51];

void visitaVizinhos( int s ){
     int v;
     
     for( v = 1; v <= grafo[0][0]; v++ )
          if( grafo[s][v] && !visitado[v] )
              visitado[v] = 1;
              
     visitou[s] = 1;
          
}

int main(){
    
    int E, L, P, X, Y;
    int p, i, j, teste = 1;
    
    scanf("%d %d %d %d", &grafo[0][0], &E, &L, &P);
    while( grafo[0][0] ){
	          
           for( i = 1; i <= grafo[0][0]; i++ )
                for( j = 1; j <= grafo[0][0]; j++ )
                     grafo[i][j] = 0;
                      
           for( i = 0; i < E; i++ ){
             scanf("%d %d", &X, &Y );
             grafo[X][Y] = grafo[Y][X] = 1;
           }
           
           memset(visitado, 0, sizeof(visitado));
           memset(visitou, 0, sizeof(visitou));
           
		   visitaVizinhos( L );
		   visitado[L] = 1;
		   
		   for( i = 2; i <= P; i++ ){
                
		        memcpy (podeVisitar,visitado, sizeof(visitado));
		        
                for( j = 1; j <= grafo[0][0]; j++ )
                     if( podeVisitar[j] && !visitou[j] )
                         visitaVizinhos( j );

          }
          
          visitado[L] = 0;
          
           printf("Teste %d\n", teste++ );
           p = 0;
		   for( i = 1; i <= grafo[0][0]; i++ )
			if( visitado[i] ){
			    if( p )
				    printf(" ");
				printf("%d", i );
				p = 1;
           }
		   printf("\n\n");
		   
         scanf("%d %d %d %d", &grafo[0][0], &E, &L, &P);
    } 

    return 0;    
}
