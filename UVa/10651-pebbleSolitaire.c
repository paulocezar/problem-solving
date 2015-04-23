/*
 *  Problema: Pebble Solitaire ( UVa 10651 )
 *  Tecnica Utilizada:  DP ( memoization / bitmask )
 *	
 *		 Representa os estados usando mascara de bits, e vai simulando recursivamente o 
 *		jogo, usando memoization para nao repetir calculos nos estados ja visitados. 
 *		 A mascara de bits para um tabuleiro vazio e 10000000000001, os 1 nas extremidades
 *		sao para nao permitirem movimentos para fora do tabuleiro. Num estado como
 *		11100000000001 so e possivel mover a peca pra direita.
 *
 *  Dificuldade: Facil-Medio
 *	Complexidade:
 *				O( ? )
 */

#include <stdio.h>
#include <stdlib.h>

#define INF 0x3F3F3F3F
#define EMPT 0x2001        /* 10000000000001 */
#define FULL 0x3FFF 	   /* 11111111111111 */
#define MOV1 0x1000 	   /* 01000000000000 */
#define MOV2 0x0800 	   /* 00100000000000 */
#define RIGH 0x0400		   /* 00010000000000 */
#define LEFT 0x2000		   /* 10000000000000 */
#define LAST 0x0001		   /* 00000000000001 */

int memo[1<<14];

int min( int a, int b ){ if( a < b ) return a; return b; }

int play( int x ){
	
	if( memo[x] != -1 ) return memo[x];
	int mov1 = MOV1, mov2 = MOV2, lft = LEFT, rgt = RIGH;
	int i, r = INF;
	char moved = 0;
	
	while( mov2 > LAST ){
		
		if( (mov1 & x) && (mov2 & x) ){
			if( ( lft & x ) == 0 ) moved = 1, r = min( r, play( ((x^mov1)^mov2) | lft ) );
			if( ( rgt & x ) == 0 ) moved = 1, r = min( r, play( ((x^mov1)^mov2) | rgt ) );
		}
		
		mov1 >>= 1;
		mov2 >>= 1;
		lft >>= 1;
		rgt >>= 1;
	}
	
	if( !moved ){
		r = 0;
		for( i = 12; i; i-- )
			if( x & (1<<i) ) r++;
	}
	
	return memo[x] = r;
}

int main(){

	int game;
	int tab, i;
	char c;
	
	for( i = 0; i < 1<<14; i++ ) memo[i] = -1;
	memo[EMPT] = 0;
	memo[FULL] = 12;
	
	for( i = 1; i <= 12; i++ )
		memo[EMPT+(1<<i)] = 1;
	
	scanf("%d", &game );
	while( game-- ){
		
		tab = EMPT;
		getchar();
		for( i = 12; i; i-- ){
			c = getchar();
			if( c == 'o' ) tab += (1<<i);
		}
			
		printf("%d\n", play( tab ) );
		
	}

	return 0;
}
