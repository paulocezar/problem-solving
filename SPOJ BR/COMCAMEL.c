#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double resolve( char expressao[], char priority ){
 
      double termos[21];
      int termo = 0, ini = 0, fim, i, c = 0;
      double total, acc;
      char valor[2];
      char* ptrOp;
      int z = strlen( expressao );
      
      ptrOp = strchr( expressao, priority == '*' ? '+' : '*' );     
      
      while ( ptrOp != NULL ){

           fim = ptrOp-expressao;
           
           if( priority == '+' )
               acc = 0;
           else
               acc = 1;
           
           for( i = ini; i <= fim; i++ ){
           
                if( expressao[i] == '*' || expressao[i] == '+' ){
                    if( priority == '+' )
                       acc += ( double ) ( c == 2 ? ((valor[0]-48)*10 + valor[1]-48 ) : valor[0]-48 );
                    else
                       acc *= ( double ) ( c == 2 ? ((valor[0]-48)*10 + valor[1]-48 ) : valor[0]-48 );
                    c = 0;
                } else {
                    valor[c++] = expressao[i];
                }
           
           }
           termos[termo++] = acc;

           ptrOp = strchr( ptrOp+1, priority == '*' ? '+' : '*' );
           ini = fim+1;
           
      }
      
      if( priority == '+' )
          acc = 0;
      else
          acc = 1;
          
      c = 0;           
      for( i = ini; i <= z; i++ ){
           
      if( expressao[i] == '*' || expressao[i] == '+' || expressao[i] == '\0' || expressao[i] == '\n' ){
          if( priority == '+' )
              acc += ( double ) ( c == 2 ? (valor[0]-48)*10 + valor[1]-48 : valor[0]-48 );
          else
              acc *= ( double ) ( c == 2 ? (valor[0]-48)*10 + valor[1]-48 : valor[0]-48 );
              c = 0;
      }else
           valor[c++] = expressao[i];
      }
      termos[termo++] = acc;
      
      if( priority == '*' ){
          total = 0;
          for( i = 0; i < termo; i++ )
          total += ( double )termos[i];
      } else {     
          total = 1;
          for( i = 0; i < termo; i++ )
          total *= ( double )termos[i];
      }

      return total;

 }

int main(){

    char expressao[255];
    int i, n;
    long long max, min;
    
    scanf("%d", &n );
    for( i = 0; i < n; i ++ ){
         scanf("%s", expressao );
         printf("The maximum and minimum are %.0lf and %.0lf.\n", resolve( expressao, '+' ),resolve( expressao, '*' ) );
    }

    return 0;
}
