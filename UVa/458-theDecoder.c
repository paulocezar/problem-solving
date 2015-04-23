#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS 1001

int main(){
    
    char line[MAXS];
    char* ptr;
    
    while( gets( line ) ){
    
           if( !line[0] ) continue;
           
           ptr = line;
           while( *ptr ){
                  *ptr -=7;
                  ptr++;
           }
           
           puts( line );       
    
    }

    return 0;    
}
