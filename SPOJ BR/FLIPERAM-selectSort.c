#include <stdio.h>
#include <stdlib.h>

int main(){

	int m, n, i, j, aux, maior;
	int *scoreList;

	scanf("%d%*c%d", &n, &m);

	scoreList = (int *) calloc(n, sizeof(int));

	for( i = 0; i < n; i++ )
		scanf("%d", &scoreList[i]);


	for( i = 0; i < n-1; i++){
		
		maior = i;
			
		for( j = i+1; j < n; j++){
			if( scoreList[j] > scoreList[maior])
				maior = j;
		}
		
		aux = scoreList[i];
		scoreList[i] = scoreList[maior];
		scoreList[maior] = aux;
		
	}
	
	for( i = 0; i < m; i++ )
		printf("%d\n", scoreList[i]);
	
	return 0;
}
