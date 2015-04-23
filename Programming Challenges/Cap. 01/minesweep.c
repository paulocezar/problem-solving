#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n, m, i, j;
    char c;
    char out[102][102];
    int field = 1;
    
    while( 1 ){
           scanf("%d %d", &n, &m );
           if( (n + m) == 0 ) break;
           getchar();
           
           if( field != 1 ) printf("\n");
           
           for( i = 1; i <= n; i++ )
                for( j = 1; j <= m; j++ )
                     out[i][j] = '0';

           for( i = 1; i <= n; i++ ){
                for( j = 1; j <= m; j++ ){
                     scanf("%c", &c );
                     if( c == '*' ){
                         out[i][j] = '*';
                         if( out[i-1][j-1] != '*' ) out[i-1][j-1]++;
                         if( out[i-1][j] != '*' ) out[i-1][j]++;
                         if( out[i-1][j+1] != '*' ) out[i-1][j+1]++;
                         if( out[i][j-1] != '*' ) out[i][j-1]++;
                         if( out[i][j+1] != '*' ) out[i][j+1]++;
                         if( out[i+1][j-1] != '*' ) out[i+1][j-1]++;
                         if( out[i+1][j] != '*' ) out[i+1][j]++;
                         if( out[i+1][j+1] != '*' ) out[i+1][j+1]++;
                     }     
                }
                getchar();
           }
                
           printf("Field #%d:\n", field++ );     
           for( i = 1; i <= n; i++ ){
                for( j = 1; j <= m; j++ )
                     printf("%c", out[i][j] );
                printf("\n");
           }              
                 
    }
    
    return 0;    
}
