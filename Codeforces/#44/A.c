#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int dots, n, x;

	scanf("%d", &n );
	
	dots = 1; x = 2;
	while( dots < n ) { dots += x; x++; }
	
	if( n == dots ) puts("YES");
	else puts("NO");
	
	return 0;
}

