/*
 *  Problema: Divisors ( UVa 294 )
 *  Tecnica Utilizada:  Matematica ( Crivo de Erastotenes / Fatoracao em primos )
 *	
 *		 Verifica a quantidade de divisores dos numeros no intervalo [ L, U ]..
 *		 A quantidade e calculada baseado no numero de fatores primos, ou seja,
 *          x = p1^i1 * p2^i2 * ... * pn^in ( 15 = 3^1 * 5^1 )
 *	    portanto | n / n divide x | = (i1+1)*(i2+2)*...*(in+1) ( | divisores de 15 | = (1+1)*(1+1) = 4 )
 *      
 *  Dificuldade: Facil-Medio
 *	Complexidade:
 *				O( ? )
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXP 31624 /* sqrt( MAXN ) -- maior fator primo que pode existir.. */
#define MAXX 178   /* sqrt( MAXP ) -- maior fator primo pra contar os primos */
#define NUMP 3450 

char prime[MAXP];
int primes[NUMP];

void crivo(){
	int num_primes = 0;
	int i, j;
	
	for( i = 0; i < MAXP; i++ )
		prime[i] = i & 1;
		
	prime[1] = 0; 
	prime[2] = 1;
	primes[num_primes++] = 2;
	
	for( i = 3; i < MAXX; i+=2 ){
		if( prime[i] ){
			primes[num_primes++] = i;
			for( j = i+i; j < MAXP; j+=i )
				prime[j] = 0;
		}
	}
	for( i = MAXX; i < MAXP; i++ )
		if( prime[i] ) primes[num_primes++] = i;
	primes[num_primes] = 0;
}

int divisors( int x ){
	
	int ndiv = 1;
	int i, cur;
	int sq = sqrt( x ) + 1;
	int n = x;
	
	for( i = 0; n != 1 && primes[i] <= sq && primes[i]; i++ ){
		if( n % primes[i] == 0 ){
			cur = 0;
			while( n % primes[i] == 0 ) cur++, n /= primes[i];
			ndiv *= ( cur+1 );
		}
	}
	if( n != 1 ) ndiv *= 2;
	return ndiv;
	
}

int main(){
	
	int n, l, u;
	int pdivs, maxdiv, num;
	int i;
	crivo();
	
	scanf("%d", &n );
	while( n-- ){
		scanf("%d %d", &l, &u );
		maxdiv = 0;
		for( i = l; i <= u; i++ ){
			pdivs = divisors( i );
			if( pdivs > maxdiv ) maxdiv = pdivs, num = i;
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, num, maxdiv );
	}
	
	return 0;
}
