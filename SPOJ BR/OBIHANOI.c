#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n, i = 0;
    
     scanf("%d", &n ); 
     
     while( n ^ 0 ){
  
        i++;   
        printf("Teste %d\n%d\n\n", i, ( 1 << n ) - 1 );
        scanf("%d", &n ); 
        
    }
    
    return 0;    
}
