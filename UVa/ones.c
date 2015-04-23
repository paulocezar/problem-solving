#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n;
    int out, a, b;
    
    while( scanf("%d", &n ) != EOF ){

           out = 0;
           a = 0;
           b = 1;
           
           while( b ){
                  
                  a = 10*a + 1;
                  out++;
                  
                  b = a % n;
                  a = b;
           }
           
           printf("%d\n", out );           
    
    }
    return 0;
}
