#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 300

char line[MAXL];

int main(){
    
    int len, c, col, inc, i, inc1, inc2;
    
    while( 1 ){
    
           scanf("%d", &col ); getchar();
          
           if( col == 0 ) return 0;
           
           gets( line );
           len = strlen( line );
           
           c = 0;
           inc1 = 2*col+1;
           inc2 = -1;
           while( c < col ){
                  
                  inc1 -= 2;
                  inc2 += 2;
                  inc = inc1;
                  i = c;
                  
                  while( i < len ){
                         putchar( line[i] );
                         i += inc;
                         inc = inc==inc1?inc2:inc1;
                  }
                  
                  c++;
           }
           putchar('\n');
    }
    
    return 0;    
}
