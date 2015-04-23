#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int sudoku[9][9];
    int jogos, instancia = 1, i, j;
    
    scanf("%d", &jogos );
    while( jogos-- ){
           
           int confereLinha[10];
           int forma = 1;
           
           for( i = 0; i < 9; i++ ){
                memset( confereLinha, 0, sizeof(confereLinha));
                for( j = 0; j < 9; j++ ){
                     scanf("%d", &sudoku[i][j] );
                     if( sudoku[i][j] > 9 || sudoku[i][j] < 1 )
                         forma = 0;
                     else if( confereLinha[sudoku[i][j]] )
                         forma = 0;
                     else
                         confereLinha[sudoku[i][j]] = 1;
                }
           }

           if( forma ){
               
               int confereColuna[10];
               
               for( i = 0; i < 9; i++ ){
                    memset( confereColuna , 0, sizeof(confereColuna) );
                    for( j = 0; j < 9; j++ ){
                         if( confereColuna[sudoku[j][i]] ){
                             forma = 0;
                             break;
                         }
                         else
                             confereColuna[sudoku[j][i]] = 1;
                    }
                    if( forma == 0 )
                        break;
               }

               if( forma ){
                   int confereSub[3][10];

                   for( i = 0; i < 9; i++ ){
                        if( i == 0 || i == 3 || i == 6 )
                            memset( confereSub, 0, sizeof( confereSub ) );
                        for( j = 0; j < 9; j++ ){
                             
                             if( j < 3 ){
                                 if( confereSub[0][sudoku[i][j]] ){
                                     forma = 0;
                                     break;
                                 }
                                 else
                                     confereSub[0][sudoku[i][j]] = 1;
                             }
                             else if( j > 2 && j < 6 ){
                                 if( confereSub[1][sudoku[i][j]] ){
                                     forma = 0;
                                     break;
                                 }
                                 else
                                     confereSub[1][sudoku[i][j]] = 1;
                             }
                             else{
                                 if( confereSub[2][sudoku[i][j]] ){
                                     forma = 0;
                                     break;
                                 }
                                 else
                                     confereSub[2][sudoku[i][j]] = 1;                                  
                             }
                             
                        } 
                        if( forma == 0 ) break;    
                   }

                   if( forma )
                       printf("Instancia %d\nSIM\n\n", instancia++ );
                   else
                       printf("Instancia %d\nNAO\n\n", instancia++ );       
                   
               }
               else
                   printf("Instancia %d\nNAO\n\n", instancia++ );           
               
           } else 
              printf("Instancia %d\nNAO\n\n", instancia++ );
              
    }
    
    return 0;
}
