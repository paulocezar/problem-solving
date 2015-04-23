#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXC 310
#define MAXF 610

int grafo[MAXC][MAXC];
int lcs[MAXC*2][MAXF];
int caminho[2*MAXC];
int festas[MAXF];
int peso[MAXF];
int grau[MAXC];
char usou[MAXC];
int C, F, comp, resp;

void calcula(){

	int i, j, k;
	
	for( i = 0; i <= comp; i++ ) lcs[i][0] = 0;
	for( j = 0; j <= F; j++ ) lcs[0][j] = 0;

	for( i = 1; i <= comp; i++ )
		for( j = 1; j <= F; j++ ){
		
			if( caminho[i-1] == festas[j-1] ){
				lcs[i][j] = lcs[i-1][j-1] + peso[j-1];
				k = j-2;
				while( k >= 0 ){
					if( festas[k] == caminho[i-1] ) break;
					k--;
				}
				if( k >= 0 && lcs[i][k+1] + peso[j-1] > lcs[i][j] )
					lcs[i][j] = lcs[i][k+1] + peso[j-1];
			}
			else if( lcs[i-1][j] > lcs[i][j-1] )
				lcs[i][j] = lcs[i-1][j];
			else lcs[i][j] = lcs[i][j-1];
		
		}
	if( lcs[comp][F] > resp ) resp = lcs[comp][F];

}

void busca( int u, int p ){

	int v, w;
	char folha = 1;
	caminho[p] = u;
	usou[u] = 1;

	for( w = 0; w < grau[u]; w++ ){
		v = grafo[u][w];
		if( !usou[v] ){ busca( v, p+1 ); folha = 0; }
	}

	if( folha ){
		for( w = 0; w < p; w++ ) caminho[p+w+1] = caminho[p-w-1];
		comp = 2*p+1;
		calcula();
	}
	usou[u] = 0;
}

int main(){

	int i, u, v, n_festas;
	int teste = 1;

	memset( usou, 0, sizeof( usou ) );
	while( 1 ){
	
		scanf("%d %d", &C, &n_festas );
		if( C+n_festas == 0 ) return 0;

		for( i = 1; i <= C; i++ ) grau[i] = 0;

		for( i = 1; i < C; i++ ){
			scanf("%d %d", &u, &v );
			grafo[u][grau[u]++] = v;
			grafo[v][grau[v]++] = u;
		}

		scanf("%d", &festas[0] ); peso[0] = 1;
		F = 0;
		for( i = 1; i < n_festas; i++ ){
			scanf("%d", &u );
			if( u != festas[F] ){ F++; festas[F] = u; peso[F] = 1; }
			else peso[F]++;
		}
		F++;

		resp = 0;
		busca( 1, 0 );
		printf("Teste %d\n%d\n\n", teste++, resp );
	
	}

	return 0;
}

