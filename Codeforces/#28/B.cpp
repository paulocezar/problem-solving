#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN 110

using namespace std;

int val[MAXN];
int d[MAXN];
char reach[MAXN][MAXN];

int main(){

	int n;

	scanf("%d", &n );
	for( int i = 1; i <= n; i++ ) scanf("%d", val+i );
	for( int i = 1; i <= n; i++ ){
		scanf("%d", d+i ); 
		reach[i][i] = 1;
		if( i+d[i] <= n ) reach[i][i+d[i]] = reach[i+d[i]][i] = 1;
		if( i-d[i] > 0 ) reach[i][i-d[i]] = reach[i-d[i]][i] = 1;
	}

	for( int k = 1;	k <= n; k++ ){
		for( int i = 1; i <= n; i++ ){
			for( int j = 1; j <= n; j++ ){
				reach[i][j] = reach[i][j] || ( reach[i][k] && reach[k][j] );
			}
		}
	}

	for ( int i = 1; i <= n; i++ ) if( !reach[val[i]][i] )
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}
