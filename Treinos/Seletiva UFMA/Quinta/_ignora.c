#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

int main(){
    
    int xn, yn, rn;
    int xm, ym, d;
    double dist;
    
    while( 1 ){
     
           scanf("%d %d %d", &xn, &yn, &rn );
           if( xn+yn+rn == 0 ) return 0;
           
           scanf("%d %d %d", &xm, &ym, &d );
           dist = sqrt( (double)( (xm-xn)*(xm-xn) + (ym-yn)*(ym-yn) ) );
           if( ( dist-(double)rn ) - (double)d > DBL_EPSILON ) puts( "nao" );
           else{
           
                puts("sim");
                
           }
           
    }
    
    return 0;    
}
