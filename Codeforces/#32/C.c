#include <stdio.h>
#include <stdlib.h>

unsigned __int64 n, m, s, ans;

int main(){

	scanf("%I64u %I64u %I64u", &n, &m, &s ); n--, m--;
	ans = ( (n/s) + 1 ) * ( (m/s)+1 );
	ans *= ( (n%s) + 1 )*( (m%s) + 1 );
	printf("%I64u\n", ans  );

	return 0;
}

