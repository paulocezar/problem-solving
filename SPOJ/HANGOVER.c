#include <stdio.h>
#include <stdlib.h>

int main(){
    
    float f, c;
    int n;
    
    while( 1 ){
           
           scanf("%f", &c );
           if( c == 0.0 ) break;
           n = 1;
           f = 0.5;
           while( f < c ){
                  f += 1.0/(float)(n+2);
                  n++;
           }
           printf("%d card(s)\n", n );
    }
    
    
    return 0;    
}
