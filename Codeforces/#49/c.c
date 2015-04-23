#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    int i, j;
    scanf("%d", &n );
    i = 1; j = n;
    while( i < j ){
           if( i != 1 ) printf(" ");
           printf("%d %d", i, j );
           i++, j--;
    }    
    if( n & 1 ) {
        if( n != 1 ) printf(" %d\n", i );
        else printf("1\n");
    }
    
    return 0;
}
