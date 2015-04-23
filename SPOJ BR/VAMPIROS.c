#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int ev1, ev2, e1, e2, at, d;
    float p, q, out;

    while( 1 ){
    
           scanf("%d %d %d %d", &ev1, &ev2, &at, &d );
           if( (ev1+ev2+at+d) == 0 ) break;
           
           e1 = ev1/d;
           e2 = ev2/d;
           if( ev1 % d ) e1++;
           if( ev2 % d ) e2++;
           
           if( at == 3 )
               out = (float)e1/(e1+e2);
           else{
                p = (float)at / 6.0;
                q = 1 - p;
                
                out = ( 1 - pow( q / p, e1) ) / ( 1 - pow( q / p, e1 + e2) );		
           }
           
           out *= 100.0;
           
           printf("%.1f\n", out );
               
    }
    
    return 0;
}
