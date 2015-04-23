#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n, c, v, difLados;
    
    scanf("%d", &n );
    while( n ){
        
        difLados = 0;
           
        while( n ){
           scanf("%d %d", &c, &v );
           difLados += ( v >> 1 );
           n--;
        }
        
        printf("%d\n", difLados >> 1 );
           
           
    scanf("%d", &n );       
    }
    
    return 0;
    
}
