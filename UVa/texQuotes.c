#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char c;
    char f;
    
    f = 1;
    while( (c = getchar()) != EOF ){
    
           if( c == '"' ){
               if( f )
                   printf("``");
               else
                   printf("''");
               f = 1-f; 
           }
           else
               printf("%c", c );
           
    }
    
    return 0;
}
