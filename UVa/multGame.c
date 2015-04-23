#include <stdio.h>
#include <stdlib.h>

int main(){
    
    long n, p;
    char stan, olie;
    
    while( scanf("%ld", &n ) != EOF ){
           
           stan = 0, olie = 1;
           p = 1l;
           
           while( p < n ){
                  
                  stan = 1 - stan;
                  olie = 1 - olie;
                  
                  if( stan )
                      p *= 9l;
                  else
                      p *= 2l;
           
           }
           
           if( stan )
               printf("Stan wins.\n");
           else
               printf("Ollie wins.\n");
    
    }
    
    return 0;    
}
