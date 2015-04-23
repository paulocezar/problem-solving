#include <stdio.h>
#include <stdlib.h>

double M[301][301];
double p[301][602];
char raiz[602];
int parent[602];
int r[602][2];
int n;

void prob( int pl, int cr ){
     
	int k;
	double rt = 0.0, a, b;

	for( k = 1; k <= n; k++ ){
         
        if( p[k][cr] == 0.0 ) continue; 
        
        if(  p[pl][r[cr][0]] == -1.0 )
             prob( pl, r[cr][0] );
        if(  p[k][r[cr][1]] == -1.0 )
             prob( k, r[cr][1] );

        if( p[pl][r[cr][0]] == 0.0 || p[k][r[cr][1]] == 0.0 ){
            
            if(  p[pl][r[cr][1]] == -1.0 )
                 prob( pl, r[cr][1] );
            if(  p[k][r[cr][0]] == -1.0 )
                 prob( k, r[cr][0] );
            
            rt += ( p[pl][r[cr][1]] * p[k][r[cr][0]] ) * M[pl][k];
             
        } else{
             
            rt  += ( p[pl][r[cr][0]] * p[k][r[cr][1]] ) * M[pl][k];
        }

	}
	p[pl][cr] = rt;
	return;
}

int main(){
	
	int i, j, a, b, dec;

	while( 1 ){
		scanf("%d", &n );
		if( n == 0 ) break;

        memset( raiz, 1, sizeof( char ) * ( 2*n ) );
        memset( parent, -1, sizeof( int ) * ( 2*n ) );
        
		for( i = 1; i <= n; i++ ){
			for( j = 1; j <= n; j++ ){
				scanf("%lf", &M[i][j] );
				p[i][j] = p[i][j+n] = 0.0;
			}
			p[i][i] = 1.0;
			r[i][0] = r[i][1] = i;
		}

		j = 2*n - 1;
		for( i = n+1; i <= j; i++ ){
			scanf("%d %d", &a, &b );
			raiz[a] = raiz[b] = 0;
			parent[a] = parent[b] = i;
			r[i][0] = a;
			r[i][1] = b;
		}
		
		for( i = 1; i <= n; i++ ){
             a = parent[i];
             while( a != -1 ){
                    p[i][a] = -1.0;
                    a = parent[a];
             }
        }
		
		for( i = n+1; i <= j; i++ )
			if( raiz[i] ) { dec = i; break; }
			
		prob( 1, dec );

		printf("%.6lf\n", p[1][dec] );
	}

	return 0;
}

