#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char in[300], out[300];
	int i, j;

	gets( in );
	i = j = 0;
	while( in[i] ){
		if( in[i] == '.' ) out[j++] = '0';
		else if( in[i] == '-' && in[i+1] == '.' ) out[j++] = '1', i++; 
		else out[j++] = '2', i++;
	i++;
	}
	out[j] = 0;
	puts( out );
	return 0;
}

