#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int i, j, k, l, n, t = 0;
    
    scanf("%d", &n);
    
    while( n ^ 0 ){
        t++;
                   i = n / 50;
                   n = n % 50;
                   j = n / 10;
                   n = n % 10;
                   k = n / 5;
                   n = n % 5;
                   l = n / 1;

        printf("Teste %d\n%d %d %d %d\n\n", t, i, j, k, l );
           
        scanf("%d", &n);
    }      
    
    
    return 0;
}
