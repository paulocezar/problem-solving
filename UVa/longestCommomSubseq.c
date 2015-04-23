#include <stdio.h>
#include <stdlib.h>

#define MAXL 1003

int t[MAXL][MAXL];

int main(){
    
    int i, j;
    char x[MAXL], y[MAXL];
      
    while( scanf("%[^\n]", x+1 ) != EOF ){
           
           getchar();
           scanf("%[^\n]", y+1 );
           getchar();
           
           for( i = 1; x[i]; i++ ){
                for( j = 1; y[j]; j++ ){
                      
                      if( x[i] == y[j] )
                          t[i][j] = t[i-1][j-1] + 1;
                      else if( t[i-1][j] > t[i][j-1] )
                          t[i][j] = t[i-1][j];
                      else
                          t[i][j] = t[i][j-1];               
                }
           }
           
           printf("%d\n", t[i-1][j-1] );
           
    }    
    
    return 0;    
}
