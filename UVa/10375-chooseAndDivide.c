/*
 *  Problema: Choose and Divide ( UVa 10375 )
 *  Tecnica Utilizada:  Coeficiente Binomial + log
 *	
 *		  O enunciado do problema e claro, calcular C( p, q ) / C( r, s )
 *		  Como p, q, r e s podem ser ate 10000, calcular os fatoriais de modo 
 *		  convencional e inviavel, mas podemos atentar ao fato que:
 *			 10^( log(a) + log(b) - log(c) ) = a*b/c
 * 		  e assim usando long double pra ter uma boa precisao podemos calcular 
 * 		  a resposta facilmente. 
 *      
 *  Dificuldade: Medio
 *	Complexidade:
 *		O( P ) 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double calc( int n, int k ){
	long double r = (long double)0;
	int i;
	if( k < n-k ) k = n-k;
	for( i = k; i; i-- ){
		r = r + (long double) log10( (long double)(n-k+i) );
		r = r - (long double) log10( (long double)i );
	}
	return r;
}

int main(){

	int p, q, r, s;
	long double t1, t2;
	
	while( scanf("%d %d %d %d", &p, &q, &r, &s) != EOF ){
		
		t1 = calc( p, q );
		t2 = calc( r, s );
		printf("%.5Lf\n", (long double) pow( (long double)10, t1-t2 ) );

	}

	return 0;
}
