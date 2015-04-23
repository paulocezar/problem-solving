#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char line[32];
    int out;
    

    while( 1 ){
           
           scanf("%[^\n]", line ); getchar();
                       
           if( line[0] == '-' ) return 0;
           
           if( line[1] == 'x' ) {
               sscanf( line, "%X", &out );
               printf("%d\n", out );
           }
           else{
               sscanf(line, "%d", &out );
               printf("0x%X\n", out );
           }
                     
    }

    return 0;    
}
