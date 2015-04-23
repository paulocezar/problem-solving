#include <stdio.h>
#include <stdlib.h>
 
int main(){
   
   int testes, k;
   char sk[1000005];
   int fib[1501];
   char* c;
      
   fib[0] = fib[1] = 1;   
   for( k = 2; k < 1501; k++ )
		fib[k] = ( fib[k-1] + fib[k-2] ) % 1000;
   
   scanf( "%d", &testes ); getchar();
   while( testes-- ){
      k = 0;
      gets( sk ); c = sk;
      while( *c ){
             k = ( k * 10 + *c - '0') % 1500;
             c++;
      }
      printf( "%03d\n", fib[k-1] );
   }
 
   return 0;
}
