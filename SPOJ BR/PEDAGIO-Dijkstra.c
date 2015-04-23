#include <stdio.h>
#include <stdlib.h>
#define INF 0x3f3f3f3f

int grafo[51][51];
int distancia[51];
int queue[51];

void initialize( int s ){
	int v;
	for( v = 1; v <= grafo[0][0]; v++ ){
		distancia[v] = INF;
		queue[v] = 1;
	}
	
	distancia[s] = 0;

}

void relax( int u, int v ){
	
	if( distancia[v] > distancia[u] + 1 )
		distancia[v] = distancia[u] + 1;
		
}

int getMin(){
	int i, r, min = INF;
	
	for( i = 1; i <= grafo[0][0]; i++ )
		if( queue[i] ^ 0 )
			if( distancia[i] < min ){
				r = i;
				min = distancia[i];
			}
			
	return r;
	
}

void dijkstra( int s ){

	int u, v, i;
	int flag = 1;

	initialize( s );
	queue[0] = grafo[0][0];
	
	while( queue[0] ^ 0 ){
           
		u = getMin();
	
		queue[u] = 0;
	    queue[0]--;
	  
		for( v = 1; v <= grafo[0][0]; v++ )
			if( grafo[u][v] )
				relax( u, v );
                	
	}

}

int main(){

    int E, L, P, X, Y;
    int p, i, j, teste = 1;
    
    scanf("%d %d %d %d", &grafo[0][0], &E, &L, &P);
    while( grafo[0][0] ^ 0 ){
	          
           for( i = 1; i <= grafo[0][0]; i++ )
                for( j = 1; j <= grafo[0][0]; j++ )
                     grafo[i][j] = 0;

                      
           for( i = 0; i < E; i++ ){
             scanf("%d %d", &X, &Y );
             grafo[X][Y] = grafo[Y][X] = 1;
           }
		   
		   dijkstra( L );
		   
           printf("Teste %d\n", teste++ );
           p = 0;
		   for( i = 1; i <= grafo[0][0]; i++ )
			if( distancia[i] <= P && distancia[i] > 0 ){
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
