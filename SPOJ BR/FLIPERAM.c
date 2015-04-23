#include <stdio.h>
#include <stdlib.h>

int compare(void *a, void *b){
	return (*(int*)a - *(int*)b);
}

int main(){

	int m, n, i;
	int *scoreList;

	scanf("%d%*c%d", &n, &m);

	scoreList = (int *) calloc(n, sizeof(int));

	for( i = 0; i < n; i++ )
		scanf("%d", &scoreList[i]);

	qsort(scoreList, n, sizeof(int),(void *)compare); 
	
	for( i = n-1; i >= n-m; i-- )
		printf("%d\n", scoreList[i]);
	
	return 0;
}
