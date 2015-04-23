#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXP 46342

int* getPrimos( ){
     
      int *primes;
      int numPrimes = 0, i, j;
      int* candPrimes; 
      candPrimes = ( int * ) calloc( MAXP, sizeof(int) );
      
      for( i = 2; i < MAXP; i++ )
           if( candPrimes[i] ^ 1 ){
               numPrimes++;
               for( j = 2*i; j < MAXP; j+=i )
                    candPrimes[j] = 1;
           }
      
      primes = ( int * ) calloc( numPrimes+1, sizeof(int) );
 
      primes[0] = numPrimes;
      primes[1] = 2;
      j = 2;
      for( i = 3; i < MAXP; i+=2 )
           if( candPrimes[i] != 1 ){
               primes[j] = i;
               j++;
           }
           
      return primes;
}

int main(){
    
    int *primos = getPrimos();
    int i;
    int num, n;
    int raiz;
    char f;
    
    scanf("%d", &num ); 
    while( num ){
               
           f = 0;
           
           if( num < 0 ){
               n = -num;
               printf("%d = -1", num );
               f = 1;
           }
           else{
                n = num;
                printf("%d = ", num );
           }
           raiz = sqrt( n ) + 1;

           for( i = 1; n != 1 && primos[i] <= raiz && i <= primos[0]; i++ )
                if( n % primos[i] == 0 )
                    while( n % primos[i] == 0 ){
                           if( f ) printf(" x ");
                           else f++;
                           printf("%d", primos[i] );
                           n /= primos[i];
                    }

           if( n != 1 ){
            if( f ) printf(" x ");
            printf("%d", n );
           }
           
           puts("");
           scanf("%d", &num );             
    }
    
    return 0;
}

