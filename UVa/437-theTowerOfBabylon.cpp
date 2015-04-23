#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 35

using namespace std;

struct cube_t{
	int x, y, z;
	cube_t(){}
	cube_t( int a, int b, int c ) : x(a), y(b), z(c) {}
	bool operator < ( const cube_t &a ) const {
		if( x > a.x ) return true;
		if( x < a.x ) return false;
		return y > a.y;
	}
};

int maxH[6*MAXN];
cube_t cube[6*MAXN];

int main(){
	
	int i, j, tst = 1;
	int n, N, ans, a, b, c;
	
	while( true ){
	
		scanf("%d", &n );
		if( n == 0 ) return 0;

		for( i = 0; i < n; i++ ){
			scanf("%d %d %d", &a, &b, &c );
			cube[6*i] = cube_t( a, b, c );
			cube[6*i+1] = cube_t( a, c, b );
			cube[6*i+2] = cube_t( b, a, c );
			cube[6*i+3] = cube_t( b, c, a );
			cube[6*i+4] = cube_t( c, a, b );
			cube[6*i+5] = cube_t( c, b, a );
		}
		N = 6*n;
		sort( cube, cube+N );
		memset( maxH, 0, sizeof( int ) * N );
		
		ans = 0;
		for( i = 0; i < N; i++ ){
			if( maxH[i]+cube[i].z > ans ) ans = maxH[i]+cube[i].z;
			for( j = i+1; j < N; j++ ){
				if( cube[i].x > cube[j].x && cube[i].y > cube[j].y && maxH[i]+cube[i].z > maxH[j] )
					maxH[j] = maxH[i]+cube[i].z;
			}
		}
		printf("Case %d: maximum height = %d\n", tst++, ans );
	}

	return 0;
	
}
