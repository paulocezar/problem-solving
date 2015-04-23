#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){


	double A, G, Ra, Rg;

	scanf("%lf %lf %lf %lf", &A, &G, &Ra, &Rg );

	if( Ra*G > Rg*A )
		puts( "A" );
	else
		puts( "G");


	return 0;
}

