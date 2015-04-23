#include <stdio.h>
#include <stdlib.h>

#define MAXN 500001

int vet[MAXN];
int bit[MAXN];
int indx[MAXN];
int MAX;

void up( int idx ){
	while( idx <= MAX ){
		bit[idx]++;
		idx += ( idx & -idx );
	}
}

long long get( int idx ){
	long long sum = 0;
	while( idx > 0 ){
		sum += bit[idx];
		idx -= ( idx & -idx );
	}	
	return sum;
}

int comp( const void *a, const void *b ){
	return vet[(*(int*)a)-1] - vet[(*(int*)b)-1];
}

int main(){

	int i, n;
	long long out;

	while( 1 ){
		scanf("%d", &n );
		if( n == 0 ) return 0;

		bit[0] = 0;
		for( i = 1; i <= n; i++ ){
			scanf("%d", vet+i-1 );
			indx[i-1] = i;
			bit[i] = 0;
		}
	
		MAX = n;
		qsort( indx, n, sizeof( int ), comp );

		out = 0;
		for( i = 0; i < n; i++ ){
			out += ( i - get( indx[i] ) );
			up( indx[i] );
		}
		printf("%lld\n", out );
	}
	
	return 0;
}
