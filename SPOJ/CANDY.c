#include <stdio.h>
#include <stdlib.h>

#define MAXN 11000

int a[MAXN];

int main(){
    
    int n, i, sum, moves;
    
    while( 1 ){
    
           scanf("%d", &n );
           if( n == -1 ) return 0;
           sum = 0;
           for( i = 0; i < n; i++ ) { scanf("%d", a+i ); sum += a[i]; }
    
           if( sum % n ){
               moves = -1;
           } else {
               moves = 0;
               sum /= n;
               for( i = 0; i < n; i++ ) moves += a[i]<sum?sum-a[i]:0;
           }
           
           printf("%d\n", moves );
    }

    
    return 0;
}
