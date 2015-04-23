#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>

#define MAXB 33
#define MAXS 10

using namespace std;

int main(){

	int n, t, i, j, nb, l;
	int torneira[MAXB];
	int lfsr[MAXB];	
	int aux[MAXB][MAXB];	
	int lfsr_r[MAXB][MAXB];
	int ini[MAXS*4], fim[MAXS*4];
	long long int sini, sfim;
	long long int potencia, k, state, final;

	while( true ){
	
		scanf("%d %d", &n, &t );
		if( n+t == 0 ) return 0;
		
		map< long long , long long > passos;

		for( i = 0; i < n; i++ ){
			lfsr[i] = 0;
			for( j = i; j < n; j++ )
				lfsr_r[i][j] = lfsr_r[j][i] = 0;
		}

		for( i = 0; i < t; i++ ) { 
			 scanf("%d", &torneira[i] );
			 lfsr[n-torneira[i]-1] = 1;
			 if( torneira[i] )
			 	lfsr_r[n-1][n-torneira[i]] = 1;
		}
		lfsr_r[n-1][0] = 1;

		for( i = 0; i+1 < n; i++ ) lfsr_r[i][i+1] = 1;

		scanf("%x %x", &sini, &sfim );

		for( i = 0; i < n; i++ ) {
			if( sini & 1ll<<i ) ini[n-i-1] = 1;
			else ini[n-i-1] = 0;
			if( sfim & 1ll<<i ) fim[n-i-1] = 1;
			else fim[n-i-1] = 0;
		}

		potencia = 1ll << ( n/2 );
		k = 1ll;
		
		state = 0ll; final = 0ll;
		for( i = 0; i < n; i++ ) {
			if( ini[n-i-1] ) state += (1ll<<i);
			if( fim[n-i-1] ) final += (1ll<<i);
		}
		passos[state] = 0ll;

		if( state == final ) { puts("0"); continue; }
		if( state == 0 ) { puts("*"); continue; }
		
		k = 1ll;
		while( k <= potencia ){
			
			if( state & 1ll ) nb = 1; else nb = 0;
			i = n-1;
			while( i-- ) if( lfsr[i] ) if( ( state & ( 1ll<<(n-1-i) ) ) ) nb += 1;

			state >>= 1;
			if( nb & 1 ) state |= (1ll<<(n-1));
			if( state == final ){ printf("%lld\n", k ); break; } 	
			if( state == 0ll ) break;
			passos[state] = k;
			k++;
		}
		if( state == final ) continue;

		k = 1ll;
		while( k < potencia ){
		
			for( l = 0; l < n; l++ ){
			
				for( j = 0; j < n; j++ ){
					aux[l][j] = 0;
					for( i = 0; i < n; i++ ){
						aux[l][j] += ( lfsr_r[l][i] * lfsr_r[i][j] );
					}
					aux[l][j] %= 2;
				}

			}
		
			for( i = 0; i < n; i++ )
				for( j = 0; j < n; j++ )
					lfsr_r[i][j] = aux[i][j];
		
			k *= 2ll;

		}

		k = 0ll;
		while( (k*potencia) <= (1ll<<n) ){

			for( i = 0; i < n; i++ ){
				ini[i] = 0;
				for( j = 0; j < n; j++ )
					ini[i] += (lfsr_r[i][j] * fim[j]);
				ini[i] %= 2;
			}
			state = 0ll;
			for( i = 0; i < n; i++ ){
				fim[i] = ini[i];
				if( ini[n-i-1] ) state += (1ll<<i);
			}
			k++;
			if( passos.find( state ) != passos.end() ) break; 
		}
		
		if( k*potencia <= (1ll<<n) ) printf("%lld\n", k*potencia + passos[state] );
		else puts("*");

	}

	return 0;
}

