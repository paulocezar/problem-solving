#include <stdio.h>

int main(){

	int i;
	long n;
	double mediaGastos, saida1, saida2, diff;

	while( scanf("%ld", &n) != EOF ){

		double gastos[n];

		if( n == 0 )
			return 0;

		mediaGastos = 0;
		saida1 = 0;
		saida2 = 0;

		for( i = 0; i<n; i++){
			scanf("%lf\n", &gastos[i]);
			mediaGastos += gastos[i];
		}

		mediaGastos /= n;

		for( i = 0; i<n; i++){
			diff = (double) (long) ((gastos[i] - mediaGastos)*100.0)/100.0;
			if( diff < 0 ) {
				saida2 += diff;
			} else {
				saida1 += diff;
			}
		}

		if( -saida2 > saida1 )
			printf("$%.2lf\n", -saida2);
		else
			printf("$%.2lf\n", saida1);
	}

	return 0;

}
