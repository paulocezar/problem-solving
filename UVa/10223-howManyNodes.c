/*
 *  Problema: How Many Nodes ? ( UVa 10223 )
 *  Tecnica Utilizada:  DP / Recorrencia
 *
 *		  Primeiro: Dado N nos, qual o numero maximo de arvores ?
 *		   Como, dos N nos um tem que ser a raiz, sobram N-1 nos.. que podem estar tanto na subarvore
 *		   da direita quanto da esquerda.. Sendo assim.. seja A[n] o numero de arvores com n nos..
 *			 A[n] = SUM( A[i]*A[n-i-1] ) i = 0 .. n-1
 *		  Com isso calculamos o nro. maximo de arvores de acordo com a qtde de nos,
 *		  como esse numero cresce muito rapido, com 20 nos ja ultrapassamos o limite da entrada
 *		  portanto, para resolver a questao, basta gerar os 20 primeiros termos, depois um busca
 * 		  sequencial na quantidade de arvores e eficiente o suficiente pra responder o problema. : )
 *      
 *  Dificuldade: Medio-Facil
 *	Complexidade:
 *				O( 1 )
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	unsigned long long A[21];
	unsigned long long n;
	int i, j;
	A[0] = 1llu;
		
	for( i = 1; i < 21; i++ ){
		A[i] = 0llu;
		for( j = 0; j < i; j++ ){
			A[i] += ( A[j]*A[i-j-1] ); 
		}
	}
	
	while( scanf("%llu", &n ) != EOF ){
		for( i = 1; i < 21; i++ )
			if( n == A[i] ){ printf("%d\n", i ); break; }
	}

	return 0;
}