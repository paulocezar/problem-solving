#include <stdio.h>
#include <stdlib.h>

int compare( const void *a, const void* b ){

	return (*(int*)a) - (*(int*)b);
}

int main(){

  int n, i, saida=0;
  int groups[102];

  scanf("%d", &n );
  for( i = 0; i < n ; i++ )
    scanf("%d", &groups[i] );

  qsort( groups, n, sizeof(int), compare );

  n /= 2;
  n++;

  for(i=0; i<n; i++ )
    saida += (groups[i]/2) + 1;

  printf("%d", saida );

  return 0;
}

