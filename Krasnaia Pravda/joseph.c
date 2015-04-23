#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int i, sz;
	char line[65600];

	while( gets( line ) ){
		if( !line[0] ) continue;
		i = 1;
		sz = strlen( line );
		while( line[i] == '0' ) i++;
		line[sz] = '1';
		line[sz+1] = 0;
		puts( line+i );
	}

	return 0;
}

