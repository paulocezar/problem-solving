#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char line[1002];
    char rline[1001];
    char *ptr, *ptr2, *rptr;
    line[0] = ' ';
    
    while( gets( line+1 ) ){
    
           ptr = line+1;
           rptr = rline;
           
           while( *ptr ){
           
                  if( *ptr == ' ' ){
                      ptr2 = ptr-1;
                      while( *ptr2 != ' ' ){
                             *rptr = *ptr2;
                             rptr++, ptr2--;
                      }
                      *rptr = ' '; rptr++;
                  }
                  ptr++;      
           }
           ptr2 = ptr-1;
           while( *ptr2 != ' ' ){
                  *rptr = *ptr2;
                  rptr++, ptr2--;
           }
           *rptr = 0;
           
           puts( rline );
           
    }    
    
    return 0;
}

