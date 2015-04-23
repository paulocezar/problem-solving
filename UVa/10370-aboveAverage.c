#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int cases, i;
    double grades[1001];
    double total, out, x, n;
    
    scanf("%d", &cases );
    while( cases-- ){
           scanf("%lf", &n );
           
           total = 0;
           for( i = 0; i < n; i++ ){
                scanf("%lf", &grades[i] );
                total += grades[i];
           }
           
           total /= n;
           x = 0;
           for( i = 0; i < n; i++ ) if( grades[i] > total ) x++;
                
           out = (100*x)/n;
           printf("%.3lf%%\n", out );
           
    }
    
 
    return 0;   
}
