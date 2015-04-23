#include <stdio.h>
#include <stdlib.h>

int main(){

    char* letter = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char c; char* p;
    
    while( (c = getchar()) != EOF ){
           if( c == ' ' || c == '\n' ){ putchar( c ); continue; }
           
           for( p = letter; *p; p++ )
                if( *p == c ) c = *(--p);
           putchar( c );
    }

    return 0;
    
}
