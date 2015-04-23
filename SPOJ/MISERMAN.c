#include <stdio.h>
#include <stdlib.h>

#define MAXC 200

int dp[MAXC];
int a[MAXC];

inline int min( int a, int b ){ if( a < b ) return a; return b; }

int main(){
    
    int r, c, i, j, ans;

    scanf("%d %d", &r, &c );
    
    for( i = 0; i < c; i++ ) scanf("%d", dp+i );
    
    for( j = 1; j < r; j++ ){
         for( i = 0; i < c; i++ ){
              scanf("%d", a+i );
              a[i] += min( (i>0)?dp[i-1]:1<<30, min( dp[i], (i<(c-1))?dp[i+1]:1<<30 ) );
         }
         for( i = 0; i < c; i++ ) dp[i] = a[i];
    }
    
    ans = 1<<30;
    for( i = 0; i < c; i++ )
         ans = min( ans, dp[i] );
           
    printf("%d\n", ans );
           

    return 0;    
}
