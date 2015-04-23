#include <stdio.h>
#define MAX_ALUNOS 1000

int main(){
    
  int i, nota_melhor, n;
  int turma=1;

  struct
  {
    int codigo, media;
  } alunos[MAX_ALUNOS];
  
  /* le numero de alunos da primeira turma */
  scanf("%d", &n);
  while (n > 0){
  int x = 0;
        
      /* le dados dos alunos */
      for (i = 0; i < n; i++)
         scanf("%d %d", &alunos[i].codigo, &alunos[i].media);
         
      /* procura a maior media */
      nota_melhor = 0;
      for (i = 0; i < n; i++)
         if (alunos[i].media > nota_melhor )
             nota_melhor = alunos[i].media;
             
      /* escreve resposta */
      printf("Turma %d\n", turma++ );
      
      for( i = 0; i < n; i++)
           if( alunos[i].media == nota_melhor ){
           if( x ^ 0 )
           printf(" ");
           printf("%d", alunos[i].codigo );
           x = 1;
           }
      
      printf("\n\n");
           
      /* le numero de alunos da proxima turma */
      scanf("%d", &n);
  }
  return 0;
}
