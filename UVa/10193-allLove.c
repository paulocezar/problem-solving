#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int cases, x, ss1, ss2, i, j;
    char s1[32], s2[32], *ptr;
    int a, b, c;
        
    scanf("%d", &cases ); getchar();
    for( x = 1; x <= cases; x++ ){
         gets( s1 );
         gets( s2 );
         
         ss1 = ss2 = 0;
         ptr = s1;
         while( *ptr ) ss1++, ptr++;
         ptr = s2;
         while( *ptr ) ss2++, ptr++;
    
         a = b = 0;
         ptr = s1;
         while( ss1 ){
                ss1--;
                if( *ptr == '1' )
                    a += 1 << ss1;
                ptr++;
         }
         ptr = s2;
         while( ss2 ){
                ss2--;
                if( *ptr == '1' )
                    b += 1 << ss2;
                ptr++;
         }
         
         if( a < b ) b ^= a ^= b ^= a;
         
         while( b ){
                c = a;
                a = b;
                b = c % b;         
         }
         
         if( a == 1 )
             printf("Pair #%d: Love is not all you need!\n", x );
         else
             printf("Pair #%d: All you need is love!\n", x );
          
    }
    

    return 0;    
}
