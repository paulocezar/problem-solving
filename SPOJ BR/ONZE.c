#include <stdio.h>
#include <stdlib.h>

int main(){
    
    
    char num[1002];
    char saveNum[1002];
               
    scanf("%s", num );
    
    while( strcmp( num, "0") != 0 ){
           
           int i, ultimoDigito, digitosRestantes, nextNum = 0, tam;
           
           sprintf( saveNum, "%s", num );
           tam = strlen( num );

           while( tam > 2 ){
                char ultimos[tam];

                ultimoDigito = num[tam-1] - 48;

                for( i = 0; i < tam-1; i++ )
                  ultimos[i] = num[i];
                  
                ultimos[i] = '\0';

                sscanf( ultimos, "%d", &digitosRestantes );
                
                nextNum = digitosRestantes - ultimoDigito;
                
                sprintf( num, "%d", nextNum );
                      
                tam = strlen( num );
           
           }
           
           sscanf( num, "%d", &nextNum );
           
           if( nextNum % 11 == 0 )
             printf( "%s is a multiple of 11.\n", saveNum ); 
           else
             printf( "%s is not a multiple of 11.\n", saveNum ); 
             
        scanf("%s", num);
           
    }
    
    return 0;
}
