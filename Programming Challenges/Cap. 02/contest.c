#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int err;
	char stat;
}problem;

typedef struct {
	
	problem problemas[10];
	int id;
	int time;
	int solved;
	int part;
} contestant;


int comp( const void *a, const void *b ){
	
	int r;
	contestant* p1 = (contestant*)b;
	contestant* p2 = (contestant*)a;

	r = p1->solved - p2->solved;
	if( r == 0 ){
		r = p1->time - p2->time;
		if( r == 0 ){
			if( p1->part && p2->part )
				r = p2->id - p1->id;
			else if( p1->part )
				r = 1;
			else if( p2->part )
				r = -1;
			else
				r = p2->id - p1->id;
		}
	}

	return r;

}

int main(){


	contestant participantes[1001];
	int i, j, c, p, t, cases;
	char l, continua;
	char linha[500];

	for( i = 0; i < 101; i++ ){
		participantes[i].id = i;
		participantes[i].time = 0;
		participantes[i].solved = 0;
		participantes[i].part = 0;
		for( j = 1; j < 10; j++ ){
			participantes[i].problemas[j].err = 0;
			participantes[i].problemas[j].stat = 0;
		}
	}

    scanf("%d", &cases ); getchar(); getchar();
	while( cases-- ){

		continua = 1;
		gets( linha );
		do{
	
			sscanf( linha, "%d %d %d %c", &c, &p, &t, &l );
			switch( l ){
				case 'C':
					if( participantes[c].problemas[p].stat == 0 ){
						participantes[c].solved++;
						participantes[c].time +=( ( participantes[c].problemas[p].err * 20 ) + t);
						participantes[c].problemas[p].stat = 1;
					}
					break;
				case 'I':
					if( participantes[c].problemas[p].stat == 0 )
						participantes[c].problemas[p].err++;
					break;
				default:
					break;
			}
			participantes[c].part++;
			if( gets( linha ) == NULL ) continua = 0;
			if( strlen( linha ) < 1 ) continua = 0;

		} while( continua );

		qsort( participantes, 101, sizeof( contestant ), comp );

		i = 0;
		while( participantes[i].part ){
			printf("%d %d %d\n", participantes[i].id, participantes[i].solved, participantes[i].time );
			i++;
		}
		
		if( cases ){
		    printf("\n");

		    for( i = 0; i < 101; i++ ){
			     participantes[i].id = i;
			     participantes[i].time = 0;
			     participantes[i].solved = 0;
			     participantes[i].part = 0;
			     for( j = 1; j < 10; j++ ){
				      participantes[i].problemas[j].err = 0;
				      participantes[i].problemas[j].stat = 0;
	             }
	        }
        }

	}

	return 0;
}

