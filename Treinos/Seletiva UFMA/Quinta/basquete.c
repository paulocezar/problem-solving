#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

#define MAXN 210

typedef struct{
        int alt;
        int id;
} jogador;

int comp( const void *a, const void *b  ){
    jogador *ja = (jogador*)a;
    jogador *jb = (jogador*)b;
    int r = jb->alt - ja->alt;
    if( r ) return r;
    else return ja->id - jb->id;
}        

int main(){
    
    jogador jogadores[MAXN];
    int i, n;
    
    while( 1 ){
          scanf("%d", &n );
          if( n == 0 ) return 0;
          
          for( i = 0; i < n; i++ ){
               scanf("%d", &jogadores[i].alt );
               jogadores[i].id = i+1;
          }
          qsort( jogadores, n, sizeof( jogador ), comp );
          
          printf("%d %d %d %d %d\n", jogadores[0].id, jogadores[1].id, jogadores[2].id, jogadores[3].id, jogadores[4].id );
           
    }   
    
    return 0;    
}
