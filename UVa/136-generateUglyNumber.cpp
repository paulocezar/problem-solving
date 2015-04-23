#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int find = 0;
    int i, o, last;
    
    for( i = 1; find != 1500; i++ ){
         o = i;
         while( o % 2 == 0 ) o /= 2;
         while( o % 3 == 0 ) o /= 3;
         while( o % 5 == 0 ) o /= 5;
         if( o == 1 )++find, last = i;     
    }
    
    printf("The 1500'th ugly number is %d.\n", last );
    system("PAUSE");
    return 0;
        
}
