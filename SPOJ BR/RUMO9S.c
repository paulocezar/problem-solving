#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char num[1002];
    char saveNum[1002];
    
    scanf("%s", num );
    
    while( num[0] != '0' && ( num[1] != '\0' || num[1] != '\n' ) ){
           
           int i, grau = 0, nextNum = 0, tam;
           sprintf( saveNum, "%s", num );
           
           tam = strlen( saveNum );
           
           while( tam != 1 ){
                  
                grau++;    
                nextNum = 0;   
                for( i = 0; i < tam; i++ )
                  nextNum += ( num[i] - 48 ) ;
              
              sprintf( num, "%d", nextNum );
           
              tam = strlen( num );
           
           }
           
           if( strcmp( num, "9" ) == 0 )
            printf( "%s is a multiple of 9 and has 9-degree %d.\n", saveNum, grau == 0?grau+1:grau ); 
           else
             printf( "%s is not a multiple of 9.\n", saveNum ); 
             
        scanf("%s", num);
           
    }
    
    return 0;
    
}
