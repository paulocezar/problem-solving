#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int ini;
	int fim;
} sorveteiro;

int compare( const void* a, const void* b ){

	return  ((sorveteiro*)a)->ini - ((sorveteiro*)b)->ini ;

}

int main(){

 sorveteiro sorveteiros[5000];
 int P, S, i, final, teste = 1;

 while( 1 ){
	scanf("%d %d", &P, &S );
	if( !P || !S  ) break;

	for( i = 0; i < S; i++ )
		scanf("%d %d", &sorveteiros[i].ini, &sorveteiros[i].fim );

	qsort( sorveteiros, S, sizeof(sorveteiro), compare );

	printf("Teste %d\n%d ", teste++, sorveteiros[0].ini );

	final = sorveteiros[0].fim;
	for( i = 1; i < S; i++ ){

	    if( final < sorveteiros[i].ini )
		printf("%d\n%d ", final, sorveteiros[i].ini );

	    if( final < sorveteiros[i].fim )
	    final = sorveteiros[i].fim;	   

	}


	printf("%d\n\n", final > sorveteiros[S-1].fim ? final : sorveteiros[S-1].fim );

 }

 return 0;
}

