#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int t, n, a, d;
    
    scanf("%d", &t );
    while( t-- ){
           
           scanf("%d %d %d", &n, &a, &d );
           printf("%d\n", ( 2*n*a + n*(n-1)*d ) / 2 );       
    }

    return 0;    
}
