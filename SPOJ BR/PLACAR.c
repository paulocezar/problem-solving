#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char name[22];
    char reprovado[22] ;
    int alunos;
    int min;
    int i;
    int num;
    int instancia = 0;
    
    while( scanf("%d", &alunos ) != EOF ){
    min = 11;
    reprovado[0] = 'Z';
    reprovado[1] = '\0';
    instancia++;
    
        for( i = 0; i < alunos; i++){
            scanf( "%s %d", name, &num );
            
            if( num < min ){
                min = num;
                strcpy( reprovado, name );
            } else if ( num == min ){
                if( strcmp( reprovado, name ) < 0 )
                    strcpy( reprovado, name );
            }
            
        }
        
        printf( "Instancia %d\n%s\n", instancia, reprovado );
    
           
    }
    
    return 0;
}
