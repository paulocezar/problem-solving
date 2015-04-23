#include <stdio.h>
#include <stdlib.h>

#define MAXN 310
#define MAXP 15

typedef struct {
	int v, np;
} carta;

carta cartas[MAXN];

int ncar[MAXP];
int mao[MAXP][MAXN];

int main(){

	int p, m, n;
	int psq, pds, ds, _ds;
	char np;
	char cw, descartou;
	int i, j;
	int winner;
	
	while( 1 ){

		scanf("%d %d %d", &p, &m, &n );
		if( (p+m+n) == 0 ) return 0;

		for( i = 0; i < n; i++ ){
			scanf("%d %c", &cartas[i].v, &np );
			switch( np ){
				case 'C': cartas[i].np = 1; break;
				case 'D': cartas[i].np = 2; break;
				case 'H': cartas[i].np = 3; break;
				case 'S': cartas[i].np = 4; break;
			}
			//printf("leu %d %c ( %d )\n", cartas[i].v, np, cartas[i].np );
		}
	
		psq = 0;
		for( j = 1; j <= p; j++ ){
			i = 0;
			ncar[j] = 0;
			while( i < m ){
				mao[j][ncar[j]++] = psq++;
				i++;
			}
		}

		pds = psq++;
		
		j = 1;
		
		if( cartas[pds].v == 12 ) descartou = 0, cw = 0;
		else descartou = 1, cw = 1;
		
		while( 1 ) {
				//printf("jogador %d\n", j); getchar();
			if( descartou ){
				
				if( cartas[pds].v == 7 ){
					
					mao[j][ncar[j]++] = psq++;
					mao[j][ncar[j]++] = psq++;
					descartou = 0;
					
				} else if( cartas[pds].v == 1 ){
				
					mao[j][ncar[j]++] = psq++;
					descartou = 0;
				
				} else if( cartas[pds].v == 11 ){
					descartou = 0;	
				} else { descartou = 0; continue; }
			
			} else {
				
				ds = -1;
				for( i = 0; i < ncar[j]; i++ ){
					if( cartas[mao[j][i]].v == cartas[pds].v || cartas[mao[j][i]].np == cartas[pds].np ){
						if( ds == -1 
							|| cartas[mao[j][i]].v > cartas[ds].v
							|| (cartas[mao[j][i]].v == cartas[ds].v && cartas[mao[j][i]].np > cartas[ds].np) )
						{
							ds = mao[j][i];
							_ds = i;
						}
					}
				}
				
				if( ds != -1 ){
					mao[j][_ds] = mao[j][ncar[j]-1];
					ncar[j]--;
				 	pds = ds;
					descartou = 1;
					
						//printf("desc %d %d", cartas[pds].v, cartas[pds].np );
				} else {
					 if( cartas[psq].v == cartas[pds].v || cartas[psq].np == cartas[pds].np ) {
						 pds = psq++;
						 descartou = 1;
							 //printf("desc %d %d", cartas[pds].v, cartas[pds].np );
					 }else mao[j][ncar[j]++] = psq++;
				 }
			
				if( ncar[j] == 0 ){
					winner = j; break;
				}
			
				if( descartou && cartas[pds].v == 12 ) { cw = 1-cw; descartou = 0; }
			
			}
			
			if( cw ) { j++; if( j > p ) j = 1; }
			else { j--; if( j == 0 ) j = p; }

		}
		
		printf("%d\n", winner );

	}

	return 0;
}

