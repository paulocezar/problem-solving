#include <stdio.h>
#include <stdlib.h>

 int main(){
    char num[1002];
    char saveNum[1002];
    int f = 0;

    scanf("%s", num );

    while( strcmp( num, "0") != 0 ){

           int i, ultimoDigito, digitosRestantes, nextNum = 0, tam;
           
           sprintf( saveNum, "%s", num );
           
           tam = strlen( num );
           
           if( f == 0 )
               f = 1;
           else
               printf("\n");
               
           while( tam > 2 ){
                  nextNum = 0;
                  
                  for( i = 0; i < tam; i+=2 )
                       nextNum += ( num[i] - 48 );
                       
                  for( i = 1; i < tam; i+=2 )
                       nextNum -= ( num[i] - 48 );
                       
                  if( nextNum < 0 )
                      nextNum = -nextNum;
                  
                  sprintf( num, "%d", nextNum );
                  tam = strlen( num );
                  
           }
           
           sscanf( num, "%d", &nextNum );
           
           if( nextNum % 11 == 0 )
               printf( "%s is a multiple of 11.", saveNum );
           else
               printf( "%s is not a multiple of 11.", saveNum );
               
           scanf("%s", num);
     }
     
     return 0;
     
}
