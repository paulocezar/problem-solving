#include <stdio.h>
#include <stdlib.h>

#define MAX 15

int main(){

    char num[MAX];
    int out, i;
    
    while( gets( num ) ){
           if( num[0] == '0' && num[1] == 0 ) return 0;
           
           while( num[1] ){
                  i = out = 0;
                  while( num[i] ) out += (num[i++]-'0');   
                  sprintf( num, "%d", out );
           }
           
           puts( num );
                         
    }

    return 0;    
}
