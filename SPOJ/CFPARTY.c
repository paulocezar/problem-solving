/*
 *  Problema: Party ( Spoj Classical )
 *  Tecnica Utilizada:  ad-hoc ( grafo )
 *	
 *		 Como iremos remover todos os que tem nro. de amigos 0, 1, ..., n-1
 *		fica claro que nao podemos ter as N pessoas ao final.
 *		 Tambem nao podemos ter N-1 pessoas, pois para isso apenas uma pessoa tem
 *		que sair, ou seja, a com o menor nro. de amigos, supondo que essa pessoa tem X amigos,
 *		todas as outras pessoas tem mais de X amigos, e depois que a de menor nro. de amigos sair
 *		terao no maximo X amigos, o que quer dizer que ele influencia todos os que sobraram, ou
 *		seja, que X = N-1, mas se ele tinha menos amigos que todos isso leva a uma contradicao.
 *		 Ou seja, nao podemos ter N nem N-1 pessoas ao final, mas podemos mostrar que e possivel ter
 *		N-2 pessoas. Supondo que N-2 pessoas sao todas amigas entre si, podemos imagina-las representadas
 *		como um grafo completo de N-2 vertices onde todos os vertices tem grau N-3. Se colocarmos as outras
 *		duas pessoas como amigas de todas as N-2 outras pessoas, mas elas nao forem amigas os N-2 vertices
 *		terao todos grau N-2, e os dois vertices que nao tem ligacao terao grau N-3. Assim, na passada referente
 *		aos vertices de grau N-3 os dois serao removidos, deixando os N-2 vertices restantes com grau N-3,
 *		e assim, como a passada seguinte as pessoas com N-2 amigos sairam, as com N-3 que sobraram podem ficar. 
 *
 *  Dificuldade: Medio-Facil
 *	Complexidade:
 *				O( 1 )
 */

#include <stdio.h>
#include <stdlib.h>

inline int max( int a, int b ){ if( a > b ) return a; return b; }

int main(){
	
	int t, n;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		printf("%d\n", max( 0, n-2 ) );
	}
	return 0;
}
