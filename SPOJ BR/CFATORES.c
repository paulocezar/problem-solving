#include <stdio.h>
#include <stdlib.h>
#define MAX         1000001

int* getPrimos( ){
      int *primes;
      int numPrimes = 0, i, j;
      int *candPrimes;
      
      candPrimes = ( int * ) calloc( MAX, sizeof(int) );
      
      for( i = 2; i < MAX; i++ )
           if( candPrimes[i] ^ 1 ){
               numPrimes++;
               for( j = 2*i; j < MAX; j+=i )
                    candPrimes[j] = 1;
           }
      
      primes = ( int * ) calloc( numPrimes+1, sizeof(int) );
      
      primes[0] = numPrimes;
      primes[1] = 2;
      j = 2;
      for( i = 3; i < MAX; i+=2 )
           if( candPrimes[i] ^ 1 ){
               primes[j] = i;
               j++;
           }
           
      return primes;
}

int main(){
    
    int *primos = getPrimos();
    int i;
    int num;
    
    scanf("%d", &num );
    
    while( num ^ 0 ){     
    int fatores = 0;
    
    for( i = 1; i < primos[0] && primos[i] <= num ; i++ )
         if( num % primos[i] == 0 )
             fatores++;

    printf("%d : %d\n", num, fatores );

    scanf("%d", &num );           
    }
    
    return 0;
}
