#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    double n, p;
    
    while( scanf("%lf", &n ) != EOF ){
           scanf("%lf", &p );
           
           printf("%.0lf\n", pow( p, ( 1 / n ) ) );
           
    }
    
    return 0;    
}
