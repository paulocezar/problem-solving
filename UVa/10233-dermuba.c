#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	long n, m;
	double dx, dy, xa, ya, xb, yb, dist;
	double sen60 = sqrt( 3.0 ) / 2.0;

	while( scanf("%ld %ld", &n, &m ) != EOF ){
			
			dy = floor( sqrt( n ) );
			ya = dy * sen60;
			if( n & 1 ){
				if( (int)dy & 1 ) ya += ( 2.0 * sen60 ) / 3.0;
				else ya += sen60 / 3.0;
			}
			else{
				if( (int)dy & 1 ) ya += sen60 / 3.0;
				else ya += (2.0 * sen60 ) / 3.0;
			}
	
			dx = ( dy*dy + (dy+1.0)*(dy+1.0) - 1.0 ) / 2.0;
			xa = ( n - dx )* 0.5;

			dy = floor( sqrt( m ) );
			yb = dy * sen60;
			if( m & 1 ){
				if( (int)dy & 1 ) yb += ( 2.0 * sen60 ) / 3.0;
				else yb += sen60 / 3.0;
			}
			else{
				if( (int)dy & 1 ) yb += sen60 / 3.0;
				else yb += (2.0 * sen60 ) / 3.0;
			}
			
			dx = ( dy*dy + (dy+1.0)*(dy+1.0) - 1.0 ) / 2.0;
			xb = (m - dx )* 0.5;
			
			dx = (xa - xb)*(xa - xb);
			dy = (ya - yb)*(ya - yb);

			dist = sqrt( dx + dy );
			printf("%.3lf\n", dist );
	
	}

	return 0;
}

