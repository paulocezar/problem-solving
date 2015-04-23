#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int consultas;
    int divisa[2];
    int coord[2];
    
    scanf("%d", &consultas );
    while( consultas ^ 0 ){

           scanf("%d %d", &divisa[0], &divisa[1] );     
           for( ; consultas ^ 0; consultas-- ){
                scanf("%d %d", &coord[0], &coord[1] );
                
                if( coord[0] == divisa[0] || coord[1] == divisa[1] )
                    printf("divisa\n");
                else if( coord[1] > divisa[1] )
                     if( coord[0] > divisa[0] )
                         printf("NE\n");
                     else
                         printf("NO\n");   
                else
                    if( coord[0] > divisa[0] )
                        printf("SE\n");
                    else
                        printf("SO\n");
           }
           
    scanf("%d", &consultas );           
    }
    
    return 0;
}
