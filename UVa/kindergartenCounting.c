#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    
    int count;
    char *ptr, line[1000];
    char f;
    
    while( gets( line ) ){
    
           if( !line[0] ) continue;
           
           count = 0;
           ptr = line;
           f = 1;
                  
           while( *ptr ){
                  
                  if( (*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= 'a' && *ptr <= 'z' ) ){
                            if( f ){ count++; f = 0; }
                  }else
                            f = 1;
                            
                 ptr++;
           } 
        
           printf("%d\n", count );           
    }
    
    return 0;
}

