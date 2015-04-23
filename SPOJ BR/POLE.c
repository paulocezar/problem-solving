#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define MAXN 100001

#define EPS 1e-12

#define signal(a) ((a>EPS)?1:((a<-EPS)?-1:0))
#define compare(a,b) (signal(a-b))

typedef struct {
	int x, y, h;
	double norma, ang;
} poste;

poste postes[MAXN];
int resp[MAXN];

int comp( const void *a, const void *b ){

	if( ((poste*)a)->ang - ((poste*)b)->ang > 0.0 ) return 1;
	else if( ((poste*)a)->ang - ((poste*)b)->ang  < 0.0 ) return -1;
	else if( ((poste*)a)->norma - ((poste*)b)->norma > 0.0 ) return 1;
	return -1;
}

int comp2( const void *a , const void *b ){
	int r = postes[*(int*)a].x - postes[*(int*)b].x;
	if( r ) return r;
	else return postes[*(int*)a].y - postes[*(int*)b].y;
}

int main(){

	int n, i, j, h, o, ds = 1;

	while( 1 ){

		scanf("%d", &n );
		if( n == 0 ) return 0;

		for( i = 0; i < n; i++ ){
             
			scanf("%d %d %d", &postes[i].x, &postes[i].y, &postes[i].h );

			postes[i].norma = fabs( postes[i].x ) + fabs( postes[i].y );
			postes[i].ang = atan2( postes[i].y, postes[i].x ); 
			
		}

		qsort( postes, n, sizeof( poste ), comp );
		
		o = 0;
		for( i = 0; i < n; i++ ){
             
			h = postes[i].h;
			j = i+1;
			while( j < n && ( postes[i].ang - postes[j].ang ) == 0.0 ){
				if( postes[j].h <= h ){
					resp[o++] = j;
				} else {
					h = postes[j].h;
				}
				i++;
				j++;
			}
			
		}
		if( o ){
            qsort( resp, o, sizeof( int ), comp2 );
			printf("Data set %d:\nSome lights are not visible:\nx = %d, y = %d", ds++, postes[resp[0]].x, postes[resp[0]].y );
			for( i = 1; i < o; i++ ){
				printf(";\nx = %d, y = %d", postes[resp[i]].x, postes[resp[i]].y );
			}
			printf(".\n");
		} else {
			printf("Data set %d:\nAll the lights are visible.\n", ds++ );
		}
	}

	return 0;
}
