#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Ponto {

	double x;
	double y;

}Ponto;


int main() {

int i, j, n=0;
double dist=0, menorDist=0;
Ponto *entradas;

	scanf("%d", &n);

	entradas = ( Ponto *) calloc(n, sizeof(Ponto));

	for( i = 0; i<n; i++)
		scanf("%lf%*c%lf", &entradas[i].x, &entradas[i].y);

	for (i=0; i<n-1; i++){
		for (j=i+1; j<n; j++){
		dist = (pow (entradas[i].x - entradas[j].x,2))
				+(pow (entradas[i].y - entradas[j].y,2));
		
		if ( i == 0 )
			menorDist = dist;
		if ( dist < menorDist )
			menorDist = dist;
		}
	}

	printf("%.3lf", sqrt(menorDist));

return 0;
}
