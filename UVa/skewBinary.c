#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char input[32];
    int output;
    
    scanf( "%s", input );
    while( strcmp( input, "0") ^ 0 ){
           int x = strlen( input );
           int i;
           output = 0;

           for( i = 0 ; x != 0; x--, i++ ){

                if( input[i] == '1' )
                    output += ( ( 1 << x ) - 1 );
                    
                if( input[i] == '2' ){
                    output += ( 2 * ( ( 1 << x ) - 1 ) );
                    break;
                }
                
           }
           
           printf("%d\n", output );
           
    scanf( "%s", input );           
    }
    
    return 0;
}
