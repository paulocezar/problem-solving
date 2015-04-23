/*
 *  Problema: Division Game ( UVa 11859 )
 *  Tecnica Utilizada:  Nim-Sum / Sprague-Grundy ( Game Theory )
 *	
 *		 Podemos ver cada linha da matriz como sendo uma pilha do Nim-game, onde o 
 *		numero de pedras na pilha e o somatorio da quantidade de fatores primos de cada
 *		elemento da linha. Dado isso, basta aplicar a solucao fazendo o XOR dos valores,
 *		como o jogo e jogado no estilo normal, onde ganha quem tirar a ultima pedra
 *		se o valor do xor for zero o segundo jogador ganha, caso contrario a vitoria
 *		e do primeiro.
 *
 *  Dificuldade: Dificil
 *	Complexidade:
 *				O( N^2 ) [  leitura ]
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 10001
#define MAXP 101 
#define MAXX 10
#define NUMP 100 

char prime[MAXP];
int primes[NUMP];
int fatores[MAXN];

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

/* Calcula a quantidade de fatores primos dos numeros usando PD. */
void cfatores(){
	
	int x, i;
	
	crivo();
	fatores[1] = 0;
	for( x = 2; x < MAXN; x++ ){
		
		for( i = 0; x >= primes[i] && primes[i]; i++ ){
			if( x % primes[i] == 0 ){
				fatores[x] = 1 + fatores[x/primes[i]];
				break;
			}
		}
		if( !primes[i] ) fatores[x] = 1;
		
	}
	
}

int main(){
	
	int tc = 1, t, n, m, i, j, x, tot, ans;
	cfatores();
	
	scanf("%d", &t );
	while( tc <= t ){
		
		scanf("%d %d", &n, &m );
		
		ans = 0;
		for( i = 0; i < n; i++ ){
			tot = 0;
			for( j = 0; j < m; j++ ){
				scanf("%d", &x );
				tot += fatores[x];
			}
			ans = ans ^ tot;
		}
		
		if( ans == 0 ) printf("Case #%d: NO\n", tc++ );
		else printf("Case #%d: YES\n", tc++ );
		
	}
	
	return 0;
}
