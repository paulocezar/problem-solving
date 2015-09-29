#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 1001

typedef struct{
	int a, b;
} wire;

const int MaxVal = 10001;
int tree[10001];
wire dWires[MAXN];

int main(){

	int ct, t;
	int n, i, j, a, b, out, reada, readb;
	int diagonals;
	
	scanf("%d", &t );
	for( ct = 1; ct <= t; ct++ ){
		
		memset( tree, 0, sizeof( tree ) );
		scanf("%d", &n );
		out = diagonals = 0;
		
		for (i = 0; i < n; i++) {
			scanf( "%d %d", &a, &b );
			if( a == b ) {
				while ( a <= MaxVal ){
					tree[a] += 1;
					a += (a & -a );
				}
			}
			else {
				dWires[diagonals].a = a;
				dWires[diagonals].b = b;
				diagonals++;
			}
		}
		
		for ( i = 0; i < diagonals; i++ ) {
			
			a = dWires[i].a;
			b = dWires[i].b;
			
			if( b < a ){
				reada = a;
				a = b;
				b = reada;
			}
			b--;
			
			reada = 0;
			while ( a > 0){
				reada += tree[a];
				a -= (a & -a);
			}
			
			readb = 0;
			while ( b > 0){
				readb += tree[b];
				b -= (b & -b);
			}
			 
			out += ( readb - reada );
		}
		
		for ( i = 0; i < diagonals; i++) {
			for ( j = i+1; j < diagonals; j++ ) {
				a = (dWires[i].a - dWires[i].b);
				b = (dWires[j].a - dWires[j].b);
				
				if( a != b ){
					if( (a > 0 && b < 0) || (a < 0 && b > 0) ){
						if( !(( dWires[i].a > dWires[j].a && dWires[i].b > dWires[j].b ) ||
						    ( dWires[i].a < dWires[j].a && dWires[i].b < dWires[j].b )) )
						out++;
					}
					else{
						if( ( dWires[i].a > dWires[j].a && dWires[i].b < dWires[j].b ) ||
						    ( dWires[i].a < dWires[j].a && dWires[i].b > dWires[j].b ) )
						out++;
					}
				}
			}
		}
		

		printf("Case #%d: %d\n", ct, out );
		
		
	}

	return 0;
}
