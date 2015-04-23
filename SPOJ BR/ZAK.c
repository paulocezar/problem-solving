#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x3F3F3F3F
#define MAXMANA 1001
#define MAXV 1001
#define MAXM 1001

int ini, fim;
int queue[MAXV+2];
int D[MAXV];    

void findMin(){
     int i, min, imin;
     min = D[ini];
     imin = ini;
     for( i = ini+1; i < fim; i++ )
          if( D[queue[i]] < min ){
              min = D[queue[i]];
              imin = i;
          }

     queue[imin] = queue[ini];
     queue[ini] = queue[imin];     
}

int main(){


	int m, n, g, k;
	int i, j, mana, dmg, u, d, v, x;
	int hpMax, visited;
	
	int dano[MAXMANA];
	int custo[MAXV];
	int moraEm[MAXM];
	int life[MAXM];
	int peso[MAXM];
	char grafo[MAXV][MAXV];
	
	char used[MAXV];
    	
    while( 1 ){
		scanf("%d %d %d %d", &m, &n, &g, &k );
		if( m == 0 ) break;
		
        memset( dano, 0, sizeof( dano ) );
        memset( custo, 0, sizeof( int )  * ( n+1 ) );
        memset( used, 0, sizeof( char )  * ( n+1 ) );
        for( i = 1; i <= n; i++ )
             memset( grafo[i], 0, sizeof( char ) * ( n+1 ) );
        hpMax = 0;
              
		for( i = 0; i < m; i++ ){
			scanf("%d %d", &mana, &dmg );
			if( dano[mana] < dmg ) dano[mana] = dmg;
		}

		for( i = 0; i < g; i++ ){
			scanf("%d %d", &u, &v );
			grafo[u][v] = grafo[v][u] = 1;
		}

		for( i = 0; i < k; i++ ){
			scanf("%d %d", &moraEm[i], &life[i] );
			if( life[i] > hpMax ) hpMax = life[i];
		}
		
        ini = fim = 0;
        queue[fim++] = 1;
        used[1] = 1;
        while( ini != fim ){
               u = queue[ini++];
               for( v = 1; v <= n; v++ ){
                    if( grafo[u][v] && !used[v] ){
                        used[v] = 1;
                        queue[fim++] = v;
                    }
               }
        }
		       
		if( !used[n] ){
            printf("-1\n");
            continue;
        }
		
		peso[0] = 0;
		for( i = 1; i <= hpMax; i++ )
		     peso[i] = INF;
		
		for( i = 1; i < MAXMANA; i++ ){
             if( dano[i] ){
                 
                 for( j = 1; j <= hpMax; j++ ){
                      
                      d = 0;
                      if( j - dano[i] > 0 )
						d = peso[j - dano[i]];
                        
                      d += i;
                      if( d < peso[j] )
						peso[j] = d;
                 
                 }
                              
             }     
        }
        
        for( i = 0; i < k; i++ )
             custo[moraEm[i]] += peso[life[i]];
		
        for( i = 1; i <= n; i++ )
             D[i] = INF;		

		D[1] = custo[1];
		ini = fim = 0;
		queue[fim++] = 1;
        memset( used, 0, sizeof( char )  * ( n+1 ) );
        
		while( ini != fim ){
            findMin();   
			u = queue[ini++]; ini %= 1001;
			if( u == n ) break;

			for( v = 1; v <= n; v++ ){
                 if( !used[v] && grafo[u][v] ){
                     if( D[v] > D[u] + custo[v] ){
                         D[v] = D[u] + custo[v];
                         if( !used[v] ){ queue[fim++] = v; fim %= 1001; }
                     }
                 }
            }

            used[u] = 1;
		}

        printf("%d\n", D[n] );

	}


	return 0;
}

