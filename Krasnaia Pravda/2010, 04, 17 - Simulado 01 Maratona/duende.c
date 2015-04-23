#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V  101
#define PRETO  0
#define BRANCO 1
#define INF 0x3f3f3f3f

int main(){
    
    
    int L, C, nro, origem, u, v, w, i, j, ini, fim;
	int nrDestinos = 0, destinos[MAX_V];
	int grafo[MAX_V][6];
	int grau[MAX_V];
    int dist[MAX_V];
	int fila[MAX_V];
    char cor[MAX_V];
    
    scanf("%d %d", &L, &C );
    
	for( i = L*C; i >= 0; i-- )
		grau[i] = 0;
	
    for( i = 0; i < L; i++ ){
		for( j = 0; j < C; j++ ){
			scanf("%d", &nro );
			
			v = i*C + j ;
			
			if( nro == 0 )
				destinos[nrDestinos++] = v;
			else if( nro == 2 )
				cor[v] = PRETO;
			else if( nro == 3 )
				origem = v;
			
			if( nro != 2 )
				cor[v] = BRANCO;
			
			dist[v] = INF;
			
			
			if( cor[v] ){
				
				if( i )
					if( cor[v-C] ){
						grafo[v][grau[v]++] = v-C;
						grafo[v-C][grau[v-C]++] = v;
					}
				
				if( j )
					if( cor[v-1] ){
						grafo[v][grau[v]++] = v-1;
						grafo[v-1][grau[v-1]++] = v;
					}
			} 
		}
    }
    
	dist[origem] = 0;
	cor[origem] = PRETO;
	ini = fim = 0;
	fila[fim++] = origem;
	
	while( ini != fim ){
		
        u = fila[ini++];
		
        for( w = 0; w < grau[u]; w++ ){
			v = grafo[u][w]; 
			if( cor[v] ){
				cor[v] = PRETO;
				fila[fim++] = v;;
				dist[v] = dist[u] + 1;
			}
		}
    }
    
	j = INF;
	for( v = 0; v < nrDestinos; v++ )
        if( dist[destinos[v]] < j )
		    j = dist[destinos[v]];
	
	printf("%d", j );
	
	return 0;    
}


