#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *needle;
int *f;

int main(){
    
    int len;
    int i, k, ind;
    char c, mt, first = 1;

    while( scanf("%d", &len ) != EOF ){
           getchar();
           
           if( first ){
               needle = (char*) malloc( (len+2)*sizeof(char) );
               f = (int*) malloc( (len+2)*sizeof( int ) );
           } else if( (len+2)*sizeof(char) > sizeof( needle )  ){
               free( needle );
               free( f );
               needle = (char*) malloc( (len+2)*sizeof(char) );
               f = (int*) malloc( (len+2)*sizeof( int ) );
           }
           
           gets( needle );
           
           for( f[0] = -1, i = 1; i <= len; i++ ){
                k = f[i-1];
                while( k >= 0 ){
                       if( needle[k] == needle[i-1] ) break;
                       else k = f[k];
                }
                f[i] = k+1;
           }
           
           
           i = 0;
           k = 0;
           mt = 0;
           while( (c=getchar()) != EOF && c != '\n' ){
                  
                 while( k >= 0 && needle[k] != c )
                        k = f[k]; 
                 
                 k++;
                 if( k == len ){
                     if( !first ) puts("");
                     printf("%d", i-len+1 );
                     k = f[k];
                     mt = 1;
                     first = 0;
                 }
                 i++;
           
           }
           first = 0;
           if( !mt ) puts("");
    }
    
    return 0;
}
