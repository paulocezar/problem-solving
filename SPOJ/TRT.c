#include <stdio.h>
#include <stdlib.h>

#define MAXN 2100

int v[MAXN];
int memo[MAXN][MAXN];
int n;

inline int max( int a, int b ){ if( a > b ) return a; return b; }

int solve( int lo, int hi ){

    if( lo > hi ) return 0;
    if( lo == hi ) return n*v[lo];
    if( memo[lo][hi] != -1 ) return memo[lo][hi];
    
    return memo[lo][hi] = max( (n-hi+lo)*v[lo]+solve( lo+1,hi ), (n-hi+lo)*v[hi]+solve( lo, hi-1 ) );
    
}

int main(){

    int i, j;
    
    scanf("%d", &n );
    
    for( i = 0; i < n; i++ ) scanf("%d", v+i );
    
    for( i = 0; i < n; i++ )
    for( j = i+1; j < n; j++ )
    memo[i][j] = -1;
    
    printf("%d\n", solve( 0, n-1 ) );
    
    return 0;    
}
