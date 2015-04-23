#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 50001

int main(){


    int cases, n, total, med, out, max, i, j, c;
    char find[MAXVAL];
    
    scanf("%d", &cases );
    while( cases-- ){

           scanf("%d", &n );
           
           memset( find, 0, ( sizeof(char) * n * 500 ) );
           
           max = 0;
           total = 0;
           find[0] = 1;
           
           for( i = 0; i < n; i++ ){
                scanf("%d", &c );
                total += c;
                for( j = max; j >= 0; j-- )
                     if( find[j] ){
                         find[j+c] = 1;
                         if( (j+c) > max ) max = j+c;
                     }
           }
           
           med = total/2;
               
           if( find[med] )
               out = total % 2;
           else{
            
                for( i = med-1; i >= 0; i-- )
                     if( find[i] ){
                         out = total - 2*i;
                         break;
                     }
           }
    
           printf("%d\n", out );
           
    }

    return 0;    
}
