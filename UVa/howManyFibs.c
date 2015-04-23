#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDIGITS 120

typedef struct {
	char digits[MAXDIGITS];
	int last;
}  bignum;

bignum fibs[800];
bignum ab, bb, limit;

void stringtobignum( char* string, bignum* num ){
	
	int i = 0, j=0;
	while( string[i] ) i++;

	num->last = i;
	while( i ) num->digits[j++] = string[--i];
}

void add( bignum* a, bignum* b, bignum* c ){

	int carry = 0, newdigit;
	int i = 0;

	while( i < a->last && i < b->last ){
		
		newdigit = carry + (a->digits[i]-'0') + (b->digits[i]-'0');
		carry = newdigit / 10;
		newdigit = (newdigit%10) + '0';
		c->digits[i] = newdigit;

		i++;
	}

	if( a->last < b->last ){
		c->last = b->last;
		while( i < b->last ){
			newdigit = carry + (b->digits[i]-'0');
			carry = newdigit / 10;
			newdigit = (newdigit%10) + '0';
			c->digits[i] = newdigit;
			i++;
		}
		if( carry ){
			c->last++;
			c->digits[i] = carry + '0';
		}
	}
	else{
		c->last = a->last;
		while( i < a->last ){
			newdigit = carry + (a->digits[i]-'0');
			carry = newdigit / 10;
			newdigit = (newdigit%10) + '0';
			c->digits[i] = newdigit;
			i++;
		}
		if( carry ){
			c->last++;
			c->digits[i] = carry + '0';
		}
	}
	
}

int bignumcompare( bignum* a, bignum* b ){

	int i, r;

	if( a->last > b->last )
		return 1;
	if( a->last < b->last )
		return -1;

	i = a->last -1;

	while( i >= 0 && a->digits[i] == b->digits[i] ) i--;

	if( i < 0 ) return 0;

	return a->digits[i] - b->digits[i];

}

void printBignum( bignum* a ){

	int i = (a->last);
	while( i-- ) putchar( a->digits[i] );
	puts("");

}

int main(){

	char a[120], b[120];
	char *f1 = "1", *f2 = "2", c[120];
	int i, j, r1, r2, lastfib, out;

	c[0] = '1';
	for( i = 1; i < 101; i++ )
		c[i] = '0';
	c[i] = 0;

	stringtobignum( c, &limit );
	stringtobignum( f1, &fibs[1] );
	stringtobignum( f2, &fibs[2] );

	for( i = 3; i <= 480; i++ )
		add( &fibs[i-1], &fibs[i-2], &fibs[i] );

	lastfib = 480;

	while( 1 ){
		scanf("%s %s", &a, &b );
		if( a[0] == b[0] && a[0] == '0' ) return 0;

		stringtobignum( a, &ab );
		stringtobignum( b, &bb );

		i = 1;
		r1 = bignumcompare( &fibs[i], &ab );
		while( r1 < 0 ) r1 = bignumcompare( &fibs[++i], &ab );
		j = lastfib;
		r2 = bignumcompare( &fibs[j], &bb );
		while( r2 > 0 ) r2 = bignumcompare( &fibs[--j], &bb );

		out = j - i + 1;
		if( i == 0 ) out++;
		if( j == 0 && i ) out++;

		printf("%d\n", out );

	}


	return 0;
}

