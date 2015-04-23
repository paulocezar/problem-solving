#include <stdio.h>
#include <stdlib.h>

#define MAXID 999999
#define MAXT 1000

#define INI 0
#define FIM 1

int team[MAXID+1];
int queue[MAXT+1];
char inq[MAXT+1];

int tqueue[MAXT][MAXT];
int tp[MAXT][2];

int ini, fim;

int main(){

	int t;
	int i, n, id;
	char command[10];
	int mteam;
	int sc = 1;

	while( 1 ){

		scanf("%d", &t );
		if( t == 0 ) return 0;

		printf("Scenario #%d\n", sc++ );

		for( i = 0; i < t; i++ ){
			scanf("%d", &n );
			while( n-- ){
				scanf("%d", &id );
				team[id] = i;
			}
			inq[i] = 0;
			tp[i][INI] = tp[i][FIM] = 0;
		}
		ini = fim = 0;

		while( 1 ){
			scanf("%s", command );
			if( command[0] == 'S' ) break;

			if( command[0] == 'E' )
			{
				scanf("%d", &id );
				mteam = team[id];
				if( !inq[mteam] )
				{
					inq[mteam] = 1;
					queue[fim] = mteam;
					fim = (fim+1);
					
				}

				tqueue[mteam][ tp[mteam][FIM] ] = id;
				tp[mteam][FIM] = ( tp[mteam][FIM] + 1 ) ;

			}
			else
			{
				mteam = queue[ini];

				printf("%d\n", tqueue[ mteam ][ tp[mteam][INI] ] );
				
				tp[ mteam ][INI] = (tp[mteam][INI] + 1);
				if( tp[ mteam ][INI] == tp[ mteam ][FIM] ){
					inq[mteam] = 0;
					ini = ( ini+1 );
				}
			
			}
		}

		printf("\n");

	}

	return 0;
}
