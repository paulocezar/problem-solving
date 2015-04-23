#include <stdio.h>
#include <stdlib.h>

char board[10][10];
int x, y;
char c, q;

char vKnight(){
           if( x-2 >= 0 && ( board[x-2][y+1] == c || board[x-2][y-1] == c ) )
               return 1;
           if( x+2 < 10 && ( board[x+2][y+1] == c || board[x+2][y-1] == c ) )
               return 1;
           if( y+2 < 10 && ( board[x+1][y+2] == c || board[x-1][y+2] == c ) )
               return 1;
           if( y-2 >= 0 && ( board[x+1][y-2] == c || board[x-1][y-2] == c ) )
               return 1;
           
           return 0;
}

char vBishop(){
     int i, j;
     
           for( i = x-1, j = y-1; i > 0 && j > 0; i--, j-- )
               if( board[i][j] == c || board[i][j] == q )
                   return 1;
               else if( board[i][j] != '.' ) break;
          for( i = x+1, j = y+1; i < 9 && j < 9; i++, j++ )
               if( board[i][j] == c || board[i][j] == q )
                   return 1;
               else if( board[i][j] != '.' ) break;
          for( i = x+1, j = y-1; i < 9 && j > 0; i++, j-- )
               if( board[i][j] == c || board[i][j] == q )
                   return 1;
               else if( board[i][j] != '.' ) break;
          for( i = x-1, j = y+1; i > 0 && j < 9; i--, j++ )
               if( board[i][j] == c || board[i][j] == q )
                   return 1;
               else if( board[i][j] != '.' ) break;
          
          return 0;
}

char vRook(){
          int i;
     
           for( i = x+1; i < 9; i++ )
               if( board[i][y] == c || board[i][y] == q )
                   return 1;
               else if( board[i][y] != '.' ) break;
          for( i = x-1; i > 0; i-- )
               if( board[i][y] == c || board[i][y] == q )
                   return 1;
               else if( board[i][y] != '.' ) break;
          for( i = y+1; i < 9; i++ )
               if( board[x][i] == c || board[x][i] == q )
                   return 1;
               else if( board[x][i] != '.' ) break;
          for( i = y-1; i > 0; i-- )
               if( board[x][i] == c || board[x][i] == q )
                   return 1;
               else if( board[x][i] != '.' ) break;
          
          return 0;
}

int main(){
    
    int points;
    int i, j, game = 1;
    int wx, wy, bx, by;
    char wchk, bchk;
    
    for( i = 0; i < 10; i++ )
         board[0][i] = board[9][i] = board[i][0] = board[i][9] = '.';
         
    while( 1 ){
           points = 0;
           
           for( i = 1; i < 9; i++ ){
                for( j = 1; j < 9; j++ ){
                     board[i][j] = getchar();
                     if( board[i][j] == '.' ) points++;
                     else if( board[i][j] == 'k' ){ bx = i;  by = j;}
                     else if( board[i][j] == 'K' ){ wx = i;  wy = j;}
                }
                getchar();
           }
           getchar();
           
           if( points == 64 ) return 0;
           
           wchk = bchk = 0;
           
    /* Verifica se algum dos reis pode ser pego por um peao */
           if( board[wx-1][wy-1] == 'p' || board[wx-1][wy+1] == 'p' ){
               wchk = 1; goto end;}
           if( board[bx+1][by-1] == 'P' || board[bx+1][by+1] == 'P' ){
               bchk = 1; goto end;}           
               
    /* Verifica se algum dos reis pode ser pego por um cavalo */
           x = wx; y = wy; c = 'n';     
           if( vKnight() ){
               wchk = 1; goto end;
           }
           x = bx; y = by; c = 'N'; 
           if( vKnight() ){
               bchk = 1; goto end;
           }
    /* Verifica se algum dos reis pode ser pego por um bispo ou rainha */
           x = wx; y = wy; c = 'b'; q = 'q';
           if( vBishop() ){
               wchk = 1; goto end;
           }
           x = bx; y = by; c = 'B'; q = 'Q';      
           if( vBishop() ){
               bchk = 1; goto end;
           }   
    /* Verifica se algum dos reis pode ser pego por uma torre ou rainha*/
           x = wx; y = wy; c = 'r'; q = 'q';
           if( vRook() ){
               wchk = 1; goto end;
           }
           x = bx; y = by; c = 'R'; q = 'Q';
           if( vRook() ){
               bchk = 1; goto end;
           }
    /* como ja verificou a rainha com a torre e o bispo nao precisa verificar
       denovo, e tambem nao verifica o rei, pois como nao sabemos quem e o proximo
       a jogar, um rei dando check no outro seria como se os dois tivessem em check
       e o enunciado diz que isso nao acontece. */
                   
end:
           if( wchk )
               printf("Game #%d: white king is in check.\n", game++ );
           else if( bchk )
               printf("Game #%d: black king is in check.\n", game++ );
           else
               printf("Game #%d: no king is in check.\n", game++ );
               
    }
    
    return 0;
}
