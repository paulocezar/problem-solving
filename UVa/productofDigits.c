#include <stdio.h>
#include <stdlib.h>

int main(){
    
    
    int cases;
    int n, out, i, pot;
    
    scanf("%d", &cases );
    while( cases-- ){
    
           scanf("%d", &n );
           
           out = 0;
           pot = 1;
           for( i = 9; i > 1 && n != 1; i-- ){
                while( n % i == 0 ){
                       out += ( pot * i );
                       pot *= 10;
                       n /= i;
                }
           }
           
           if( n != 1 )
               printf("-1\n");
           else if( out == 0 )
               printf("1\n"); 
           else printf("%d\n", out );
    
    }
    
    return 0;    
}
