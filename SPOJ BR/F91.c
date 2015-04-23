#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int num;
    
    scanf("%d", &num );
    
    while( num != 0 ){
           
     if( num < 102 ) 
      printf("f91(%d) = 91\n", num );
     else
      printf("f91(%d) = %d\n", num, ( num - 10 ) );
    
     scanf("%d", &num );
     
    }
    
    
    return 0;
}
