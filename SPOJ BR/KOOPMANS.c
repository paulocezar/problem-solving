#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 50

long long values[MAXN];

long long gcd( long long a, long long b ){
		while( b ){
			a = a % b;
			a ^= b;
			b ^= a;
			a ^= b;
		}
		return a;
}

int main(){
	
	int N, t;
	int a, k, j, x;
	long long I, F, size, inf, sup, soma, g, saida, mmc;
	char flag;
	
	scanf("%d", &t );
	while( t-- ){

		scanf( "%lld %lld %d", &I, &F, &N );
		/* Le os valores */
		a = 0;
		while( a < N ) scanf("%lld", &values[a++] );

		/* Quantidade de combinacoes */
		a = 1 << N;
		/* Inicializa o resultado */
		saida = 0LL;
		for( k = 1; k < a; k++ ){

			/* flag para prosseguir */
			flag = 1;
			mmc = 1LL;
			x = 0;
			/* Calcula a combinacao atual */
			for( j = 0; j < N; j++ )
				if( k & 1<<j ) {
					x++; /* Aproveita para contar nro. de bits ativos */
					g = gcd( mmc, values[j] );
					mmc = ( mmc / g ) * ( values[j] );
					/* se o mmc era maior que o final do intervalo nao precisa 
					   continuar calculando. Diminui operacoes.. menos risco de overflow */
					if( mmc > F ){ 
						flag = 0;
						break;
					}
				}

			/* Se a flag esta desativada nao precisa fazer os calculos */
			if( flag == 0 ) continue;

			/* inf é o primeiro e sup o ultimo termo da PA de razao 'mmc' dentro do intervalo */
			if( (I % mmc) == 0LL ) inf = I;
			else inf = I + ( mmc - ( I % mmc ) );
			sup = ( F / mmc ) * mmc;
			/* Nro. de elementos da PA */
			size = ( sup - inf ) / mmc + 1LL;
			
			/* Soma dos elementos ja em mod 1300031 */
			/* multiplicacao pro 650016 entra no lugar da divisao por 2 ja que 650016 e o inverso modular de 2 em Z1300031 */
			soma = ( ( ( ( size % 1300031LL ) * ( inf % 1300031LL + sup % 1300031LL ) ) % 1300031LL ) * 650016LL ) % 1300031LL; 

			/* Se era um nro impar de elementos adiciona o valor ao
			   resultado, caso contrario subtrai.. */
			if( x % 2 ){
				saida = saida + soma;
			} else saida = saida - soma;
			/* se o valor ficou negativo adiciona 1300031LL ?? */
			if( saida < 0LL ) saida = saida + 1300031LL;
			/* calcula o mod */
			saida = saida % 1300031LL;

		}
		printf("%lld\n", saida );
	}
									
	return 0;
}

