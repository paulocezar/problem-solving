#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
	
	int ct, t;
	long long l, p, c, out;
	double x, logc, logx;
	const double log2 = log10(2.0);
	
	scanf("%d", &t );
	for( ct = 1; ct <= t; ct++ ){
		
		
		scanf("%lld %lld %lld", &l, &p, &c );
		
		logc = log10( (double)c );
		logx = log10( (double)p/(double)l );
		x = ceil( logx / logc );
		
		out = (long long) ceil( log10( x ) / log2 );
					 
		printf("Case #%d: %lld\n", ct, out );
		
	}
	
	return 0;
}
