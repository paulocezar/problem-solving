#include <stdio.h>
#include <stdlib.h>

#define MAXF 32780  
#define NPRIMOS 3520

int primos[NPRIMOS];

void geraPrimos(){
	
	int i, j, nprimos = 0;
	char primo[MAXF];
	
	for( i = 0; i < MAXF; i++ )
		primo[i] = 1;

	primo[1] = 0;
	for( i = 4; i < MAXF; i+=2 )
		primo[i] = 0;
	
	primos[nprimos++] = 2;

	for( i = 3; i < MAXF; i+=2 ){
		 if( primo[i] ){
			primos[nprimos++] = i;
			for( j = i+i; j < MAXF; j+=i )
				primo[j] = 0;
		 }
	}
	primos[nprimos++] = 0;
}

int main(){

	int n, m, m2, n2, ocur, nx, x;
	char divide;

	geraPrimos();
	
	while( scanf( "%d %d", &n, &m ) != EOF ){

		m2 = m;
		n2 = n;
		divide = 1;
		x = 0;

		if( m == 0 ) divide = 0;

		while( divide && ( m != 1 ) && ( 2 * primos[x] <= m2 ) && primos[x] ){
			
			nx = 0;
			
			while( m % primos[x] == 0 ) nx++, m /= primos[x];   
			
			if( nx == 0 ){ x++; continue; }

			ocur = 0;
			n = n2;
			
			while( n / primos[x] ){
				ocur += ( n / primos[x] );
				n /= primos[x];
			}

			nx -= ocur;	
			
			if( nx > 0 ) divide = 0;
			x++;
		}
		
		if( divide && m != 1 ){
			ocur = 0;
			n = n2;
			while( n / m ){
				ocur += ( n / m );
				n /= m;
			}
			if( ocur == 0 ) divide = 0;
		}

		if( divide )
			printf("%d divides %d!\n", m2, n2 );
		else
			printf("%d does not divide %d!\n", m2, n2 );

	}

	return 0;
}

