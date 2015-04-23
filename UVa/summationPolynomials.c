#include <stdio.h>
#include <stdlib.h>

int main(){
    
    long long int n;
    
    while( scanf("%lld", &n ) != EOF ){
           n = ( n * (n+1) ) / 2;
           printf("%lld\n", ( n * n ) );
    }  
    

    return 0;    
}
