#include <stdio.h>
#include <stdlib.h>

#define MAXC 200

int dp[MAXC];
int a[MAXC];

inline int max( int a, int b ){ if( a  > b ) return a; return b; }

int main(){
    
    int t, r, c, i, j, ans;

    scanf("%d", &t );
    while( t-- ){
    
           scanf("%d %d", &r, &c );
           
           for( i = 0; i < c; i++ ) scanf("%d", dp+i );
           
           for( j = 1; j < r; j++ ){
                for( i = 0; i < c; i++ ){
                     scanf("%d", a+i );
                     a[i] += max( (i>0)?dp[i-1]:0, max( (i<(c-1))?dp[i+1]:0, dp[i] ) );
                }
                for( i = 0; i < c; i++ ) dp[i] = a[i];
           }
     
           ans = 0;
           for( i = 0; i < c; i++ )
                ans = max( ans, dp[i] );
           
           printf("%d\n", ans );
           
    }

    return 0;    
}
