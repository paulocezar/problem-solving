/*
 *  Problema: Brackets ( Spoj Classical )
 *  Tecnica Utilizada:  Segment Tree
 *	
 *		 Considerando '(' como +1 e ')' como -1, para que a expressão seja valida
 *		a soma total deve ser zero e nenhum prefixo pode ser negativo.. Para que isso	
 *		seja feito de modo eficiente, podemos usar duas segment trees, uma para armazenar
 *		a soma total e outra para o prefixo minimo..	
 *      
 *  Dificuldade: Medio-Dificil
 *	Complexidade:
 *				O( M log N )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MAXND = 2*2^16 */
#define MAXND 132000
#define MAXN 30010

int P[MAXN];
int treet[MAXND]; /* treet[ a - b ] = sum { P[a] .. P[b] } */
int treep[MAXND];

void init( int node, int beg, int end ){
	if( beg == end ){
		treet[node] = P[beg];
		treep[node] = P[beg];
	} else {
		init( 2*node, beg, (beg+end)/2 );
		init( 2*node+1, (beg+end)/2 + 1, end );
		treet[node] = treet[2*node] + treet[2*node+1];
		if( treep[2*node] <= (treet[2*node]+treep[2*node+1]) ) treep[node] = treep[2*node];
		else treep[node] = treet[2*node]+treep[2*node+1];
	}
}

void update( int node, int beg, int end, int X ){
	if( beg == end ){
		P[beg] *= -1;
		treet[node] = P[beg];
		treep[node] = P[beg];
		return;
	} else if( beg <= X && X <= (beg+end)/2 ){
		update( 2*node, beg, (beg+end)/2, X );
	} else {
		update( 2*node+1, (beg+end)/2 + 1, end, X );
	}
	treet[node] = treet[2*node] + treet[2*node+1];
	if( treep[2*node] <= (treet[2*node]+treep[2*node+1]) ) treep[node] = treep[2*node];
	else treep[node] = treet[2*node]+treep[2*node+1];
}

char valid( int n ){
	if( treet[1] ) return 0;
	if( treep[1] < 0 ) return 0;
	return 1;
}

int main(){

	int n, m, k;
	int i, test = 1;
	char c;
	
	while( scanf("%d", &n ) != EOF ){
		
		printf("Test %d:\n", test++ );
		getchar();
		for( i = 0; i < n; i++ ){
			c = getchar();
			if( c == '(' )  P[i] = 1;
			else P[i] = -1;
		}
		scanf("%d", &m );
		if( n%2 ){
			while( m-- ){
				scanf("%d", &k );
				if( k == 0 ) puts("NO");
			}
		} else {
			init( 1, 0, n-1 );
			while( m-- ){
				scanf("%d", &k);
				if( k == 0 ){
					if( valid( n ) ) puts("YES");
					else puts("NO");
				} else {
					update( 1, 0, n-1, k-1 );					
				}
			}
		}
	}
	
	return 0;
}