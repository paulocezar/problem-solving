#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        char nome[17];
        int pontuacao;
} Aluno;

int compare (const void * a, const void * b){
  
  int dif = ((Aluno*)b)->pontuacao - ((Aluno*)a)->pontuacao;
      if( dif ^ 0 )
          return dif;
          
      return strcmp( ((Aluno*)a)->nome, ((Aluno*)b)->nome );
      
}


int main(){
    
    int n, i, j, in, soma, max, min, teste = 1;
    int posicao;
    int ultimaPont;
    Aluno alunos[1001];
    
    scanf("%d", &n );
    while( n ){
           
           for( i = 0; i < n; i++ ){
                max = -1;
                min = 1001;
                soma = 0;
                scanf("%s", alunos[i].nome );
                for( j = 0; j < 12; j++ ){
                     scanf("%d", &in );
                     soma += in;
                     if( in > max )
                         max = in;
                     if( in < min )
                         min = in;
                }
                alunos[i].pontuacao = soma - max - min;
           }
           
           qsort( alunos, n, sizeof(Aluno), compare );

           printf("Teste %d\n", teste++ );
           
           posicao = 1;
           ultimaPont = alunos[0].pontuacao;
           for( i = 0; i < n; i++ ){
                
                if( alunos[i].pontuacao != ultimaPont ){
                    posicao = i + 1;
                    ultimaPont = alunos[i].pontuacao;
                }
                printf("%d %d %s\n", posicao, alunos[i].pontuacao, alunos[i].nome );
                
           }
           printf("\n");
           
    scanf("%d", &n );
    }
    
    return 0;
}
