#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int i, t = 0;
             
    scanf("%d", &i );
    while( i ^ -1 ){
         t++;
         printf("Teste %d\n%d\n\n", t, ((1 << 2*i) + ( 1 << i+1 ) + 1 ) );
         scanf("%d", &i );
    }

    return 0;
}
