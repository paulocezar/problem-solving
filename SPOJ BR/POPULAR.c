#include <stdio.h>
#include <stdlib.h>

int compare(void *a, void *b){
    return (*(int*)a - *(int*)b);
}

int main(){
    
    int alunos;
    int i, j, x;
    int votos[100];
    
    scanf("%d", &alunos );
    while( alunos ^ 0 ){
        
        for( i = 0; i < alunos; i++ )
             votos[i] = 0;
             
        for( i = 0; i < alunos; i++ ){
             for( j = 0; j < alunos; j++ ){
                  scanf( "%d", &x);
                  votos[j] += x;
             }
        }
        
       qsort(votos, alunos, sizeof(int),(void *)compare); 

       printf("%d\n", votos[alunos-1] );     
        
       scanf("%d", &alunos );    
    }        
    
    return 0;
}
