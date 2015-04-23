#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int cases, out, n, a, b, c;
    
    scanf("%d", &cases );
    while( cases-- ){
           
           out = 0;
           scanf("%d", &n );
           while( n-- ){
                  scanf("%d %d %d", &a, &c, &b );
                  out += a*b;
           }
           
           printf("%d\n", out );
    
    }

    return 0;    
}
