#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b){
    return ( *(int*)b - *(int*)a );
}

int main(){
    
    int nlinhas, ncolunas;
    int somaLinhas[101], somaColunas[101];
    int i, j, x;
    
    scanf("%d %d", &nlinhas, &ncolunas );
    
    for( i = 0; i < nlinhas; i++ )
         somaLinhas[i] = 0;
    
    for( j = 0; j < ncolunas; j++ )
         somaColunas[j] = 0;
         
    for( i = 0; i < nlinhas; i++ )
         for( j = 0; j < ncolunas; j++ ){
              scanf("%d", &x);
              somaLinhas[i] += x;
              somaColunas[j] += x;
         }
         
    qsort( somaLinhas, nlinhas, sizeof(int), compare );
    qsort( somaColunas, ncolunas, sizeof(int), compare );
    
    printf("%d", somaLinhas[0] > somaColunas[0] ? somaLinhas[0] : somaColunas[0] );

    return 0;    
}
