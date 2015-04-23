/*
 *  Problema: Roleta Turca
 *  Tecnica Utilizada:  Programacao Dinamica
 *
 *		Fixando a posicao da ultima bola, reduzimos o problema a encontrar
 *      o posicionamento das b-1 bolas restantes mantendo a posicao relativa
 *		que minimiza a soma dos v( i, j ) onde v( i, j ) define o valor da bola
 *		i quando colocada no j-esimo slot livre e eh calculada como
 *		  v( i, j ) = balls[i]*( fslots[j]+fslots[j+1] );
 *		Para resolver precisamos entao fixar a ultima bola em todas as posicoes
 *		possiveis e ver qual gera o menor valor.
 *      
 *  Dificuldade: Medio-Dificil
 *	Complexidade:
 *					O( (S^2)*B )
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXS 260
#define MAXB ((MAXS+1)/2)

int slots[MAXS];
int balls[MAXB];
int fslots[MAXS];
int pd[MAXB][MAXS];

inline int v( int i, int j ){ return balls[i]*(fslots[j]+fslots[j+1]);  }
inline int min( int x, int y ){ if( x < y ) return x; return y; }

int main(){
	
	int s, b;
	int i, j, k;
	int lval, best;

	while( 1 ){
		
		scanf("%d %d", &s, &b );
		if( (s+b) == 0 ) return 0;

		for( i = 0; i < s; i++ ) scanf("%d", slots+i );
		for( i = 0; i < b; i++ ) scanf("%d", balls+i );

		best = 0x3F3F3F3F;
		for( k = 0; k < s; k++ ){

			/* Ultima bola no k-esimo slot */
			if( k == s-1 ) lval = balls[b-1]*( slots[k]+slots[0] );
			else lval = balls[b-1]*( slots[k]+slots[k+1] );
			
			/* Gera o vetor com os valores dos slots restantes de modo a manter
			   a posicao relativa */
			for( i = 0; i < s-2; i++ )
				fslots[i] = slots[(k+2+i)%s];
			
			/* Calcula os valores para posicionar a primeira bola */
			pd[0][0] = v( 0, 0 );
			for( j = 1; j < (s-3); j++ )
				pd[0][j] = min ( pd[0][j-1], v( 0, j) ); 
			
			/* Posiciona as bolas restantes.. */
			for( i = 1; i < b-1; i++ ){
				/* na ultima posicao, calcula o valor que a bola arrecada e soma com o melhor
				   das bolas seguintes */
				pd[i][2*i] = v( i, 2*i ) + pd[i-1][2*i-2];
				for( j = 2*i+1; j < (s-3); j++ ){
					/* RECORRENCIA:
					 *    melhor valor pra i-esima bola na j-esima casa..
					 *    minimo de: colocar a bola na casa anterior ( pd[i][j-1] ), 
					 *	            e colocar bola na casa atual ( v(i,j) + pd[i-1][j-2] )
					 *							  /pegando o melhor das bolas anteriores..
					 */
					pd[i][j] = min( pd[i][j-1], v(i,j)+pd[i-1][j-2] );
				} 
			}
			
			/* Adiciona o somatorio de todas as bolas posicionadas com o valor
			   da ultima bola */
			lval += pd[b-2][s-4];
			if( lval < best ) best = lval;
		}
		printf("%d\n", -best );
	
	}

	return 0;
}

