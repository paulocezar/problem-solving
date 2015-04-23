#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_F 1001

typedef struct{
        int x;
        int y;
} ponto;

int comp( const void* a, const void* b ){
 
    return *(int*)a - *(int*)b;
    
}

int main(){
    
    int n, teste = 1, i, j;
    ponto pontos[MAX_F];
    int maiorDist[MAX_F];

    while( 1 ){
           scanf("%d", &n );
           if( n == 0 ) break;
           
           for( i = 0; i < n; i++ ){
                scanf("%d %d", &pontos[i].x, &pontos[i].y );
                maiorDist[i] = 0;
           }

           for( i = 0; i < n; i++ ){
                for( j = i+1; j < n; j++ ){
                     
                     int a = ( pontos[i].x - pontos[j].x );
                     int b = ( pontos[i].y - pontos[j].y );
                     int dist = (a*a) + (b*b);
                      
                     if( dist > maiorDist[i] )
                         maiorDist[i] = dist;
                     if( dist > maiorDist[j] )
                         maiorDist[j] = dist;  
                }
           }
           
           qsort( maiorDist, n, sizeof( int ), comp );
           
           printf("Teste %d\n%.0f\n\n", teste++, ( 2 * sqrt( maiorDist[0] ) ) + 5 );
           
    }
    
    return 0;
    
}
