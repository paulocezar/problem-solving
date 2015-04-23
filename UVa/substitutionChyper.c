#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
 
    int i, cases;
    char c;
    char alfabet[100];
    char line[100];
    char subst[127];

    
    scanf("%d", &cases ); getchar(); getchar();
    
    while( cases-- ){
     
           for( c = 0; c < 127; c++ )
                subst[c] = c;
                
           gets( alfabet );
              
           i = 0;
           while( alfabet[i] ) {
                  subst[ alfabet[i] ] = getchar();
                  putchar( subst[ alfabet[i++] ] );
           }
           
           getchar(); 
           puts("");          
           puts( alfabet );
           
           while( gets( line ) && line[0] ){
                  i = 0;
                  while( line[i] ) putchar( subst[line[i++]] );
                  puts("");
           }
           
           if( cases ) puts("");
           
    }   
 
    
    return 0;
}
