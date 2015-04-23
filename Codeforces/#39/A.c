#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int sig( int x ){ if( x < 0 ) return -1; return 1; }

int main(){

	int dist, x, y;
	int fdist;

	scanf("%d %d", &x, &y );
	
	dist = sqrt( x*x + y*y );
	fdist = ceil( sqrt( x*x + y*y ) );

	if( dist == fdist ){
		puts("black");
		return 0;
	}

	if( sig(x) == sig(y) ){
			
			if( fdist & 1 ) puts("black");
			else puts("white");

	} else{
		
			if( fdist & 1 ) puts("white");
			else puts("black");

	}
	

	return 0;
}

