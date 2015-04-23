#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 long double ultimoDigito[1000001];
 
 void calculaUltimosDigitos(){
     
     long double fives = 0;
     long double twos = 0;
     int i;
     long double pt, pf, k, x = 1.0;
     
     ultimoDigito[0] = 1;
     
     for( i = 1; i < 1000001; i++ ){
          k = i;
          
          while( fmod( k, 2.0 ) == 0 ){
                 k /= 2; 
                 twos++;
          }
          
          while( fmod( k, 5.0 ) == 0 ){
                 k /= 5;
                 fives++;
          }
          
          if( twos > fives ){
              twos -= fives;
              fives = 0;
          } else {
               fives -= twos;
               twos = 0;
          }           
          
          x = fmod( x*k, 10.0 );
          //printf( " x = %.0llf ",x);
          
          pt = fmod ( pow( 2.0, twos ), 10.0 );
          pf = fmod ( pow( 5.0, fives ), 10.0 );
         //printf( " pt = %.0llf, pf = %.0llf \n",pt, pf);
          ultimoDigito[i] = fmod( x * pt * pf, 10.0 );
          
     }
     
 }

int main(){
 
 int instance = 0;
 int num;
 
 calculaUltimosDigitos();
 
 while( scanf( "%d", &num ) != EOF ){
        instance++;
        printf("Instancia %d\n%.0f\n", instance, ultimoDigito[num] );
 }
 
 return 0;   
}
