#include <stdio.h>
#include <stdlib.h>

#define MAX_S 1001

int compare(const void *a, const void *b){
  return *((int*)a) - *((int*)b);
}

int main(){

  int s, teste = 1;
  int x[MAX_S], y[MAX_S];

  while ( 1 ){
     scanf("%d", &s);
     if( s == 0 ) break;

     int i;

     for (i = 0; i < s; i++)
	scanf("%d %d", &x[i], &y[i]);

     qsort(x, s, sizeof(int), compare);
     qsort(y, s, sizeof(int), compare);

     printf("Teste %d\n", teste++ );

     i = s / 2;
     if( s % 2 )
	   printf("%d %d\n\n", x[i], y[i] );
     else
	   printf("%d %d\n\n", ( x[i-1] + x[i] )/2, ( y[i-1] + y[i] )/2 );

  }
  return 0;

}

