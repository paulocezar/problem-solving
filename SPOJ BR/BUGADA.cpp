/*
 *  Problema: 
 *  Tecnica Utilizada: 
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

#define MAXD 101
#define MAXN 10001

using namespace std;

int NUMDIG;

struct myInt{

	int digits[MAXD];	
	int len;
	
	myInt(){
		memset( digits, 0, sizeof( digits ) );
		len = 1;
	}
	
	myInt operator * ( const myInt &x ) {
		
		myInt ret;
		ret.len = len + x.len;
		
		for( int i = 0; i < len; i++ ){
			for( int j = 0; j < x.len; j++ ){
				if( i+j > NUMDIG ) break;
				ret.digits[i+j] += ( ( (long long)digits[i]*x.digits[j] ) % 1300031 );
				ret.digits[i+j] %= 1300031;
			}
		}
		
		int j = ret.len-1;
		while( ret.digits[j] == 0 && j ) ret.len--, j--;
		return ret;
	}
	
	void print(){
		for( int i = len; i; i-- )
			printf("%d ", digits[i-1] );
		
		puts("");
	}

};

int main(){

	int T, N, P;
	int i;
	
	map< int, myInt > pot;
	
	pot[1].len = 4;
	pot[1].digits[0] = 1;
	pot[1].digits[1] = 3;
	pot[1].digits[2] = 3;
	pot[1].digits[3] = 1;
	
	NUMDIG = 100;
	for( i = 1; (i<<1) < MAXN; i<<=1 ){
		 pot[i<<1] = pot[i]*pot[i];
	}
	
	scanf("%d", &T );
	while( T-- ){
	
		scanf("%d %d", &N, &P );
		myInt ans;
		ans.digits[0] = 1;
		NUMDIG = P;
		
		i = 0;
		while( N ){	
			if( N & 1 ) ans = ans * pot[1<<i];
			N /= 2;
			i++;
		}
		
		printf("%d\n", ans.digits[P] );
	
	}

	return 0;
}
