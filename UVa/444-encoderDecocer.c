#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse( char* message ){
	int i, j;
	i = 0; j = strlen( message )-1;
	while( i < j ) { 
		message[i] ^= message[j]; 
		message[j] ^= message[i]; 
		message[i] ^= message[j]; 
		i++; j--;
	}
}

int main(){

	int i, j, d;
	char message[500];
	char out[500];
	char *p;

	while( gets( message ) ){
		
		if( '0' <= message[0] && message[0] <= '9' ){
			reverse( message  );
			j = strlen( message );
			for( i = 0; i < j; i+=2 ){
				d = (message[i]-'0')*10 + (message[i+1]-'0');
				if( d < 65 && d != 32 && d != 33 && d != 44 && d != 46 && d != 58 && d != 59 && d != 63 ){
					d = 10*d + (message[i+2]-'0');
					i++;
				}
				printf("%c", d );
			}
			puts("");
		} else if( message[0] ){
			i = 0;
			p = out;
			j = strlen( message );
			while( i < j ) { p += sprintf( p, "%d", message[i] ); i++; }	
			reverse( out );
			puts(out);
		} else puts("");
	}

	return 0;
}

