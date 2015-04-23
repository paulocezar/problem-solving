#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int i, n, x, y, x1, y1, x2, y2, teste = 1;
    int inside;

    
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2 );
    while( ( x1 + x2 + y1 + y2 ) ^ 0 ){
           
           scanf("%d", &n );
           
           inside = 0;
           
           for( i = 0; i < n; i ++ ){
                scanf("%d %d", &x, &y );
                if( x1 <= x && x <= x2 )
                    if( y2 <= y && y <= y1 )
                        inside++;
           }     
           
           printf("Teste %d\n%d\n\n", teste++, inside );           
           
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2 );     
    }
    
    return 0;
}

    
