#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 200010

char s[MAXN];
int p[MAXN];

int main(){
	
	int N, NN, i, j;

	while( gets(s) ){

		N = strlen(s);
		memcpy( s+N+2, s, N+1 );
		s[N] = '*'; s[N+1] = '%';
		i = 0, j = N-1;
		while( i < j ){
			s[i] ^= s[j]; s[j] ^= s[i]; s[i] ^= s[j];
			i++, j--;
		}
		N = 2*N+2;
		
		p[0] = -1, p[1] = 0;
		
		for( i = 2; i <= N; i++ ){
			j = p[i-1];
			while( j >= 0 && (s[i-1] != s[j]) )
				j = p[j];
			p[i] = j+1;	
		}
		s[(N-2)/2] = '\0';
		printf("%s%s\n", s+(N/2)+1, s+p[N] );
	
	}	
	
	return 0;
}




















