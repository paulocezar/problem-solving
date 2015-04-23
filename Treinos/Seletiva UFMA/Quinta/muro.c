#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>

int main(){
    
    int H, S, out;
    
    while( 1 ){
    
           scanf("%d %d", &H, &S );
           if( H+S == 0 ) return 0;
           
           out = 0;
           while( H > 0 ){
                   H -= S;
                   if( H > 0 ) out += H;      
           }       
           printf("%d\n", out );
           
    }
    
    return 0;    
}
