#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	long long n, m1, m2, n1, n2, c1, c2;
	long long g, a, b, q, lower, upper, x, y, last_x, last_y;

	while( 1 ){

		scanf("%lld", &n );
		if( n == 0 ) return 0;

		scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2 );

		g = n1;
		b = n2;

		x = 0, y = 1, last_x = 1, last_y = 0;

		while( b ){
		
			q = g / b;
			g %= b;
			g ^= b ^= g ^= b;

			last_x = last_x - q * x;
			last_y = last_y - q * y;
			x ^= last_x ^= x ^= last_x;
			y ^= last_y ^= y ^= last_y;
		
		}

		/* se n nao for divisivel por ( n1, n2 ) nao ha solucao */
		if( n % g ){ puts( "failed" ); continue; }

		/* calcula solucoes iniciais x e y a partir de n1*last_x + n2*last_y = ( n1, n2 ) */
		x = last_x*n/g;
		y = last_y*n/g;
		
		a = n1 / g;
		b = n2 / g;
		/* c1*m1 + c2*m2 e linear em funcao de m1 e m2, que sao do tipo 
		 	     m1 = x + r*b   e    m2 = y - r*a
		   logo o valor minimo so pode acontecer nos valores limite para r que garantem
		   m1 e m2 maiores ou iguais a zero. portanto so e preciso verificar qual dos dois valores e melhor. */

		lower = (long long)ceil( (double)-x / b );
		upper = (long long)floor( (double)y / a );

		if( lower > upper ){ puts("failed"); continue; }

		if( (c1*( x + lower*b ) + c2*( y - lower*a )) <= (c1*( x + upper*b ) + c2*( y - upper*a ) ) )
			m1 = x + lower*b, m2 = y - lower*a;
		else
			m1 = x + upper*b, m2 = y - upper*a;
		
		printf("%lld %lld\n", m1, m2 );
	}

	return 0;
}

