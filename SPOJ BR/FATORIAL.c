#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ultimoDigito[1000001];

void calculaDigitos(){
  int i;
  ultimoDigito[0] = 1;
 
  for( i = 1; i < 1000001; i++ ){
     ultimoDigito[i] = ( double ) fmod( (( double ) i * ultimoDigito[i-1] ),
                                         pow( (double)10, (double)15 ) );
                                         
     while( fmod( ultimoDigito[i], 10 ) == 0 ){
            ultimoDigito[i] /= 10;
     }
}   
}

int main(){
 int num, instance = 0;
 calculaDigitos();
 
  while( scanf( "%d", &num ) != EOF ){
         char buffer[10];
         int len, i;
        instance++;
        printf("Instancia %d\n", instance );
        sprintf( buffer, "%.0lf", ultimoDigito[num] );

        len = strlen( buffer );
        for( i = len-1; i > -1; i-- )
             if( buffer[i] != '0' ){
                 printf( "%c\n\n", buffer[i] );
                 break;
             }
        
 }
    
 return 0;    
}
