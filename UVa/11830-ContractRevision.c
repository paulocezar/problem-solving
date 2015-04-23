#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int d;
    char flag, pflag;
    char c;
    
    while( 1 ){
    
           d = getchar(); 
           if( d == '0' ) return 0;
           
           flag = 0;
           
           getchar();
           c = getchar();
           
           
           while( c != '\n' ){
                  
                  if( c != d ){
                      if( c != '0' || flag ) { putchar( c ); flag = 1; }
                  }
                  
                  c = getchar();
           }
           if( !flag ) putchar('0');
           putchar('\n');
    
    }
    
    return 0;    
}
