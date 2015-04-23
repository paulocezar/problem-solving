#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n;
    
    while( 1 ){
           scanf("%d", &n );
           if( n == 42 ) return 0;
           printf("%d\n", n );
    }
    
    return 0;
    
}
