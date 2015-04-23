#include <stdio.h>
#include <stdlib.h>

int main (){

    int start, end, s, e, i, c, max;
    
    while( scanf("%d %d", &start, &end ) != EOF ){
           
           if( start < end ) { s = start; e = end; }
           else  { s = end; e = start; }
           
           max = 0;
           while( s <= e ){
                  i = s;
                  c = 0;
                  while( i != 1 ){
                         if( i % 2 )
                             i = 3*i + 1;
                         else
                             i /= 2;
                         c++;
                  }
                  c++;
                  if( c > max ) max = c;
                  s++;       
           }
           printf("%d %d %d\n", start, end, max );
    }
    
    return 0;    
    
}
