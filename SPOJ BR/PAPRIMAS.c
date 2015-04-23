#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ePrimo( int n ){
     int raiz;
     int i;
     
     if( n%2 == 0 && n ^ 2 )
         return 0;

      raiz = sqrt( n ) + 1;
      for( i = 3;  i < raiz ; i+=2 )
           if ( n % i == 0 && n ^ i )
              return 0;
              
      return 1;
 
}

int main(){
    
    char line[22];
    int i;

    while( scanf("%s", line ) != EOF ){
    int sum = 0;
    int primo;
    
           for( i = 0; line[i] ^ '\0'; i++ )
                if( line[i] < 91 )
                 sum += ( line[i] - 38 );
                else
                 sum += ( line[i] - 96 );
           
           primo = ePrimo(sum);
           
           if( primo )
               printf("It is a prime word.\n");
           else
               printf("It is not a prime word.\n");
    }

    
    return 0;
}
