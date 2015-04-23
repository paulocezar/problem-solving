#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int n, p, i , j;
    char line[55];
    char syllabe[4][55];
    int ab, ac, ad, bc, bd, cd;
    line[0] = ' ';
    
    scanf("%d", &n ); getchar();

    while( n-- ){
           
           for( i = 0; i < 4; i++ ){
                gets( line + 1 );
                p = 0;
                for( j = strlen(line) - 1; line[j] != ' '; j-- ){
                     if( line[j] < 'a' ) line[j] += 32;
                     if( line[j] == 'a' || line[j] == 'e' || line[j] == 'i' || line[j] == 'o' || line[j] == 'u' ){
                         syllabe[i][p++] = line[j];
                         break;
                     }
                     syllabe[i][p++] = line[j];
                }
                syllabe[i][p] = 0;
           }
           
           ab = strcmp( syllabe[0], syllabe[1] );
           ac = strcmp( syllabe[0], syllabe[2] );
           ad = strcmp( syllabe[0], syllabe[3] );
           if( ab == ac && ac == ad && ad == 0 ){ puts("perfect"); continue; }
           bc = strcmp( syllabe[1], syllabe[2] );
           if( ad == bc && bc == 0 ){ puts("shell"); continue; }
           bd = strcmp( syllabe[1], syllabe[3] );
           if( ac == bd && bd == 0 ){ puts("cross"); continue; }
           cd = strcmp( syllabe[2], syllabe[3] );
           if( ab == cd && cd == 0 ){ puts("even"); continue; }
           
           puts("free"); 
    
    }

    return 0;    
}
