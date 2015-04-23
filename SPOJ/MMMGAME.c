/*
 *  Problema: M&M Game ( Spoj Classical )
 *  Tecnica Utilizada:  Nim-Sum ( Game Theory )
 *	
 *		 O jogo pode ser modelado como um nim-sum, versao misere..
 *		onde quem faz o ultimo movimento e o perdedor.
 *		 Logo, se nenhuma pilha tiver mais de 1 elemento, caso exista um numero
 *		par de pilhas John consegue ganhar, caso contrario o irmao ganha.
 *		Quando alguma pilha tem mais de 1 elemento, a resposta pode ser calculada
 *		com o nim-sum que caso seja zero indica que o irmao ganha caso contrario
 *		indica uma vitoria do John.
 *
 *  Dificuldade: Medio
 *	Complexidade:
 *				O( N )
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int t, n, r, ans, x, tot;
	
	scanf("%d", &t );
	
	while( t-- ){
		
		scanf("%d %d", &n, &ans );
		
		tot = ans;
		r = n-1;
		while( r-- ){
			scanf("%d", &x );
			ans = ans ^ x;
			tot += x;
		}
		
		if( tot == n ){
			if(  n & 1 ) puts("Brother");
			else puts("John");
		}
		else if( ans == 0 ) puts("Brother");
		else puts("John");
		
	}
	
	return 0;
}
