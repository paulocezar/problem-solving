#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 101

#define INF 0x3F3F3F3F

int grafo[MAXV][MAXV];
// v[i] representa o vertice original do grafo correspondente
// ao i-esimo vertice do grafo da fase atual do minCut e w[i]
// tem o peso do vertice v[i]..
int v[MAXV], w[MAXV];
// partição dos vertices de A
char A[MAXV];

int minCut( int n ){
    
    if( n == 1 ) return 0;
    
    int i, u, x, s, t;
    int minimo;
    
    for( u = 1; u <= n; u++ ){ v[u] = u; }
    
    w[0] = -1;
        
    minimo = INF;

    while( n > 1 ){
        
        // inicializa..  
        for( u = 1; u <= n; u++ ){
            A[v[u]] = 0;
            w[u] = grafo[v[1]][v[u]];
//printf("v[%d] = %d / w[%d] = %d\n", u, v[u], u, w[u] );
        }
        A[v[1]] = 1;
        s = v[1];
        for( u = 2; u <= n; u++ ){

            // Encontra o mais fortemente conetado a A 
            t = 0;
            for( x = 2; x <= n; x++ )
                if( !A[v[x]] && ( w[x] > w[t] ) )
                    t = x;

            // adiciona ele a A
            A[v[t]] = 1;

            if( u == n ){            
                if( w[t] < minimo )
                    minimo = w[t];

                // Une s e t
//printf("    une %d e %d\n\n", s, v[t] );
                for( x = 1; x <= n; x++ ){
                    grafo[s][v[x]] += grafo[v[t]][v[x]];
                    grafo[v[x]][s] = grafo[s][v[x]];
                }

                v[t] = v[n--];
                break;
            }
            s = v[t];

//printf("  mais proximo = %d \nAtualiza pesos..\n", v[t] );
            // Atualiza os pesos
            for( x = 1; x <= n; x++ )
                 w[x] += grafo[v[t]][v[x]];
//printf("w[%d] = %d \n", x, w[x] );}
        }
//printf("\n");
        
        
        
    }
    return minimo;
}

int main(){

    int i, n, m, testes, u, v, w;
    
    scanf("%d", &testes );
    while( testes-- ){
                  
           scanf("%d %d", &n, &m );
           for( i = 1; i <= n; i++ )
                memset( grafo[i]+1, 0, sizeof( int ) * n );
                
           for( i = 0; i < m; i++ ){
                scanf("%d %d %d", &u, &v, &w );
                grafo[u][v] = w;
                grafo[v][u] = w;
           }
           
           printf("%d\n", minCut( n ) );       
    }
    return 0;
}
