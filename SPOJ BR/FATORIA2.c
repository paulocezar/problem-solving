#include <stdio.h>

int main(){

int n, fatorial=1;

scanf("%d", &n);

	for( ; n>1; fatorial *= n, n--);
	
	printf("%d", fatorial);

	return 0;
}
