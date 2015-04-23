#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int x1, x2, y1, y2, dif1, dif2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2 );               
    while( x1 ){
               
           if( x1 == x2 || y1 == y2 ){
               
               if( x1 ^ x2 || y1 ^  y2 )
                   printf("1\n");
               else
                   printf("0\n");
               
           } else {
                 
                 dif1 = x1 - x2;
                 dif2 = y1 - y2;
                 
                 if( dif1 < 0 ) dif1 = -dif1;
                 if( dif2 < 0 ) dif2 = -dif2;
                 
                 if( dif1 == dif2 )
                   printf("1\n");
                 else
                   printf("2\n");
           }

           
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2 );      
    }
    
    
  return 0;    
}
