#include <stdio.h>
#include <stdlib.h>

int main(){

    char rightSolution[100][110];
    char userSolution[100][110];
    char rightNumeric[11000];
    char userNumeric[11000];
    int n, m, i, j, run = 1, num;
    char c, pe, wa;
    
    while( 1 ){
           scanf("%d", &n );
           if( n == 0 ) break;
           getchar();
           
           rightNumeric[0] = userNumeric[0] = 0;
           pe = wa = 0;
           
           num = 0; 
           for( i = 0; i < n; i++ ){
                j = 0;
                c = getchar();
                while( c && c != '\n' ){
                       if( c >= '0' && c <= '9' )rightNumeric[num++] = c;
                       rightSolution[i][j++] = c;
                       c = getchar();
                }
                rightSolution[i][j] = 0;
           }
           rightNumeric[num] = 0;
           
           scanf("%d", &m ); getchar();
           num = 0; 
           for( i = 0; i < m; i++ ){
                j = 0;
                c = getchar();
                while( c && c != '\n' ){
                       if( c >= '0' && c <= '9' )userNumeric[num++] = c;
                       userSolution[i][j++] = c;
                       c = getchar();
                }
                userSolution[i][j] = 0;
           }
           userNumeric[num] = 0;
           
           if( n != m ){
               if( strcmp( rightNumeric, userNumeric ) ) wa = 1;
               else pe = 1;
           } else {
               for( i = 0; i < n; i++ )
                    if( strcmp( rightSolution[i], userSolution[i] ) ){
                        if( strcmp( rightNumeric, userNumeric )  ) wa = 1;
                        else pe = 1;
                        break;
                    }
           }
           
           if( pe )
               printf("Run #%d: Presentation Error\n", run++ );
           else if( wa )
               printf("Run #%d: Wrong Answer\n", run++ );
           else
               printf("Run #%d: Accepted\n", run++ );
    }
    
    return 0;    
}
