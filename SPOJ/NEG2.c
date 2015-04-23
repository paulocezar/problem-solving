#include <stdio.h>
#include <stdlib.h>

char ans[100];

int main(){

    int n, m, i;
    
    scanf("%d", &n );
    
    i = 0;
    while( n ){
           m = n % -2;
           n /= -2;
           if( m < 0 ){
                           ans[i++] = m + 2 + '0';
                           n++;
           } else {
                           ans[i++] = m + '0';
           }
    }    
    
    if( i == 0 ) putchar('0');
    else while( i-- ) putchar( ans[i] );
    putchar('\n');


    return 0;    
}
