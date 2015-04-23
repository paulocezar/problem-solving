#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXCASAS 210

int peca[MAXCASAS][MAXCASAS];
int linhas, colunas, n_casas;
int minha[50][50];

int captura( int i, int j ){
    
    int cap, ret;
    int old = peca[i][j];
	peca[i][j] = 0;
	ret = 0;
	
	if( (i+2) < linhas ){
		if( j+2 < colunas ){
			if( peca[i+1][j+1] == 2 && peca[i+2][j+2] == 0 ){
				peca[i+1][j+1] = 0;
				cap = 1 + captura( i+2, j+2 );
				if( cap > ret ) ret = cap;
				peca[i+1][j+1] = 2;
			}
		}	
			
		if( j - 2 >= 0 ){
			if( peca[i+1][j-1] == 2 && peca[i+2][j-2] == 0 ){
				peca[i+1][j-1] = 0;
				cap = 1 + captura( i+2, j-2 );
				if( cap > ret ) ret = cap;
				peca[i+1][j-1] = 2;
			}
		}
	}
	
	if( (i-2) >= 0 ){
		
		if( j+2 < colunas ){
			if( peca[i-1][j+1] == 2 && peca[i-2][j+2] == 0 ){
				peca[i-1][j+1] = 0;
				cap = 1 + captura( i-2, j+2 );
				if( cap > ret ) ret = cap;
				peca[i-1][j+1] = 2;
			}
		}
		
			
		if( j - 2 >= 0 ){
			if( peca[i-1][j-1] == 2 && peca[i-2][j-2] == 0 ){
				peca[i-1][j-1] = 0;
				cap = 1 + captura( i-2, j-2 );
				if( cap > ret ) ret = cap;
				peca[i-1][j-1] = 2;
			}
		}
	}
	
	
	peca[i][j] = old;
    return ret;
}

int main(){

    int max, cap, pos, i, j, cont;
    
    while( 1 ){
    
		scanf("%d %d", &linhas , &colunas );
		if( linhas+colunas == 0 ) return 0;
           
		n_casas = (linhas*colunas + 1)/2;
		
		i = j = 0;
		cont = 0;
		for(  pos = 1; pos <= n_casas; pos++ ){
			
			scanf("%d", &peca[i][j] );
			if( peca[i][j] == 1 ) { minha[cont][0] = i; minha[cont][1] = j; cont++; }
			j += 2;
			if( j >= colunas ) {
				i++; j = i % 2;
			}
		}
		
		max = 0;
		i = j = 0;
		for( pos = 0; pos < cont; pos++ ){
			 cap = captura( minha[pos][0], minha[pos][1] );
			 if( cap > max ) max = cap;
		}
           
		printf("%d\n", max );
           
    }
    
    return 0;
}


