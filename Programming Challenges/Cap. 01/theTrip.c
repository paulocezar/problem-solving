#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int n, i;
    int sum, med, round;
    int out, pos, neg;
    int each[1001];
    int a,b;
    
    scanf("%d", &n );
    while( n ){
           sum = pos = neg = 0;
           
           for( i = 0; i < n; i++ ){
              scanf("%d%*c%d", &a, &b );
              each[i] = 100 * a + b;
              sum += each[i];
           }
 
           med = sum/n;
           if( sum % n )               
               med += ( ( ( sum%n * 100 ) / n ) + 50 )/ 100;
 
           for( i = 0; i < n; i++ ){
                if( each[i] > med )
                    pos += each[i] - med;
                else
                    neg += med - each[i];
           }
           
           if( pos < neg )
               out = pos;
           else out = neg;
           

           printf("$%d.%02d\n", out/100, out%100 );
    scanf("%d", &n );                 
    }    
    
    return 0;    
}
