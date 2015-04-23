#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    char n1[12], n2[12];
    char* ptr;
    int carry, cops;
    int t1, t2, x;
    
    while( 1 ){
           scanf("%s %s", n1, n2 );
           if( n1[0] == n2[0] && n1[0] == '0' ) break;
           
           carry = cops = 0;
           t1 = t2 = 0;     
           ptr = n1;
           while( *ptr ) ptr++, t1++;
           ptr = n2;
           while( *ptr ) ptr++, t2++;
           
           t1--, t2--;
           
           while( t1 >=0 && t2 >=0 ){
                carry = ( carry + (n1[t1]-'0') + (n2[t2]-'0') ) / 10;
                if( carry ) cops++;
                t1--, t2--; 
           }
           
           if( t1 >= 0 ){
               while( t1 >= 0 && carry ){
                      carry = ( carry + (n1[t1]-'0') ) / 10;
                      if( carry ) cops++;
                      t1--;
               }
           }
           else if( t2 >= 0 ){
               while( t2 >= 0 && carry ){
                      carry = ( carry + (n2[t2]-'0') ) / 10;
                      if( carry ) cops++;
                      t2--;
               }
           }
    
           if( cops ){
               if( cops == 1 ) printf("%d carry operation.\n", cops );
               else            printf("%d carry operations.\n", cops );
           }
           else
               printf("No carry operation.\n", cops );
           
    }
    
    return 0;
}
