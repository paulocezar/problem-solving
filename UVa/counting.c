#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDIGITS 500

typedef struct {
	char digits[MAXDIGITS];
	int last;
}  bignum;

bignum f[1001];

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

void printBignum( bignum* a ){

	int i = (a->last);
	while( i-- ) putchar( a->digits[i] );
	puts("");

}

void calcula( int n ){

	bignum a, b;

	if( f[n-1].digits[0] == '0' ) calcula( n-1 );
	if( f[n-2].digits[0] == '0' ) calcula( n-2 );
	if( f[n-3].digits[0] == '0' ) calcula( n-3 );

	add( &f[n-1], &f[n-1], &a );
	add( &f[n-2], &f[n-3], &b );
	add( &a, &b, &f[n] );

}

int main(){

	int n;
	char *z = "0", *um = "2", *dois = "5", *tres = "13";

	stringtobignum( um, &f[1] );
	stringtobignum( dois, &f[2] );
	stringtobignum( tres, &f[3] );

	for( n = 4; n < 1001; n++ )
		f[n].digits[0] = '0';


	while( scanf("%d", &n ) != EOF ){

		if( f[n].digits[0] == '0' ) calcula( n );	

		printBignum( &f[n] );
	}


	return 0;
}

