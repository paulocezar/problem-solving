#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS 25

int r, c;
char board[MAXS][MAXS];
char used[27];
int max;

void solve( int x, int y, int visited ){
     
     if( board[x][y+1] && !used[board[x][y+1]-'A'] ){
         used[board[x][y+1]-'A'] = 1;
         
         if( visited + 1 > max ) max = visited + 1;

         solve( x, y+1, visited + 1 );
         used[board[x][y+1]-'A'] = 0;
     }
     
     if( board[x][y-1] && !used[board[x][y-1]-'A'] ){
         used[board[x][y-1]-'A'] = 1;
         if( visited + 1 > max ) max = visited + 1;

         solve( x, y-1, visited + 1 );
         used[board[x][y-1]-'A'] = 0;
     }
     
     if( board[x+1][y] && !used[board[x+1][y]-'A'] ){
         used[board[x+1][y]-'A'] = 1;
         if( visited + 1 > max ) max = visited + 1;

         solve( x+1, y, visited + 1 );
         used[board[x+1][y]-'A'] = 0;
     }
     
     if( board[x-1][y] && !used[board[x-1][y]-'A'] ){
         used[board[x-1][y]-'A'] = 1;
         if( visited + 1 > max ) max = visited + 1;

         solve( x-1, y, visited + 1 );
         used[board[x-1][y]-'A'] = 0;
     }
 
}

int main(){
    
    int i;
    scanf("%d %d", &r, &c ); getchar();
    
    for( i = r+1; i >= 0; i-- )
         board[i][0] = 0;
    for( i = 1; i <= c+1; i++ )
         board[0][i] = board[r+1][i] = 0;
    
    for( i = 1; i <= r; i++ )
         gets( board[i]+1 ); 

    
    memset( used, 0, sizeof( used ) );
    used[board[1][1]-'A'] = 1;
    max = 1;
    solve( 1, 1, 1 );
    printf("%d\n", max );

    return 0;   
}
