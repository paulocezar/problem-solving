#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	unsigned in;
	double root;

	while( 1 ){
		scanf("%u", &in );
		if( in == 0 ) return 0;
		root = sqrt( in );
		if( root - (int)root ) puts( "no" );
		else puts( "yes" );
	}

	return 0;
}

