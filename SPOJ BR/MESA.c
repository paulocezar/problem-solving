#include <stdio.h>
#include <stdlib.h>
#define  MAX_V   101

int color[MAX_V];

int graphTwoColor( int G[][MAX_V] ){ 
   int v;
   int c = 0;
   for( v = 1; v <= G[0][0]; v++) 
      color[v] = -1;
   for (v = 1; v <= G[0][0]; v++)
      if (color[v] == -1) 
         if (dfsRclr(G, v, 0) == 0) return 0;
   return 1;
}

int dfsRclr (int G[][MAX_V], int v, int c) { 
   int i;
   
   color[v] = 1-c;
   
   for( i = 1; i <= G[0][0]; i++) {
      if( G[v][i] == 1 ){  
      int w = i; 
      if (color[w] == -1) {
         if (dfsRclr(G, w, 1-c) == 0) return 0; 
      }
      else if (color[w] == 1-c) return 0;
      }
   }
   return 1;
}



int main(){
    
    int grafo[MAX_V][MAX_V];
    int instancia = 1;
    int x, y, i, j;
    
    // Grafo[0][0] = numero de convidados e Grafo[0][1] = numero de arestas
    while( scanf("%d %d", &grafo[0][0], &grafo[0][1] ) != EOF ){
           
     for( i = 1; i <= grafo[0][0]; i++ )
          for( j = 1; j <= grafo[0][0]; j++ )
               grafo[i][j] = 0;
           
     for( i = 0; i < grafo[0][1]; i++ ){
          scanf("%d %d", &x, &y );
          grafo[x][y] = 1;
          grafo[y][x] = 1;
     }
          
          if( graphTwoColor( grafo ) )
              printf("Instancia %d\nsim\n\n", instancia++ );
          else
              printf("Instancia %d\nnao\n\n", instancia++ );
           
    }
    
    return 0;
}
