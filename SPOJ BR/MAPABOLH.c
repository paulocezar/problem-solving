/*
 *  Problema: Mapas Bolha
 *  Tecnica Utilizada:  Ad-Hoc ( PD? )
 *	
 *		Observando o comportamento da divisao da pra perceber que
 *		para saber o vizinho basta olhar o ultimo caracter da palavra.
 *			Ex.: vizinho de cima: se a ultima letra for 'r' troca por 'q'
 *				  e se for 's' troca por 'p', se for 'p' ou 'q' como nao tem ninguem
 *				  acima, troca pos 's' e 'r', respectivamente, e vai trocando o verifica 
 *				  a palavra desconsiderando o ultimo caractere. Se em algum momento chega
 *				  no 'm' e porque nao tem vizinho nessa direcao.
 *		Para os outros vizinhos e so seguir o mesmo raciocinio.
 *      
 *  Dificuldade: Facil
 *	Complexidade:
 *				O( n )
 *		Onde n eh o nivel de ampliacao da regiao.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXC 5010

char reg[MAXC], up[MAXC], down[MAXC], left[MAXC], right[MAXC];

int main(){

	int n, i, sz;
	char cont;

	scanf("%d", &n ); getchar();
	while( n-- ){

		scanf("%[^\n]", reg ); getchar();
		sz = strlen( reg );
		for( i = 0; i <= sz; i++ )
			up[i] = down[i] = left[i] = right[i] = reg[i];

		cont = 1;
		for( i = sz-1; cont; i-- ){
			switch( reg[i] ){
				case 'm': up[i] = 0;   cont = 0; break;
				case 'p': up[i] = 's'; break;
				case 'q': up[i] = 'r'; break;
				case 'r': up[i] = 'q'; cont = 0; break;
				case 's': up[i] = 'p'; cont = 0; break;
			}
		}
		cont = 1;
		for( i = sz-1; cont; i-- ){
			switch( reg[i] ){
				case 'm': down[i] = 0;   cont = 0; break;
				case 'p': down[i] = 's'; cont = 0; break;
				case 'q': down[i] = 'r'; cont = 0; break;
				case 'r': down[i] = 'q'; break;
				case 's': down[i] = 'p'; break;
			}
		}
		cont = 1;
		for( i = sz-1; cont; i-- ){
			switch( reg[i] ){
				case 'm': left[i] = 0;   cont = 0; break;
				case 'p': left[i] = 'q'; break;
				case 'q': left[i] = 'p'; cont = 0; break;
				case 'r': left[i] = 's'; cont = 0; break;
				case 's': left[i] = 'r'; break;
			}
		}		
		cont = 1;
		for( i = sz-1; cont; i-- ){
			switch( reg[i] ){
				case 'm': right[i] = 0;   cont = 0; break;
				case 'p': right[i] = 'q'; cont = 0; break;
				case 'q': right[i] = 'p'; break;
				case 'r': right[i] = 's'; break;
				case 's': right[i] = 'r'; cont = 0; break;
			}
		}
		
		if( up[0] ) printf("%s", up );
		else printf("<none>");
		
		if( down[0] ) printf(" %s", down );
		else printf(" <none>");
		
		if( left[0] ) printf(" %s", left );
		else printf(" <none>");
		
		if( right[0] ) printf(" %s", right );
		else printf(" <none>");
		puts("");	
	}

	return 0;
}

