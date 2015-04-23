#include <stdio.h>
#include <stdlib.h>

#define MAXN 1111

int a[MAXN];
int dp[MAXN][MAXN][2];

inline int max( int a, int b ){ if( a > b ) return a; return b; }

int solve( int lo, int hi, char playa ){
    
    if( lo > hi ) return 0;
    if( dp[lo][hi][playa] != -1 ) return dp[lo][hi][playa];
    
    if( playa == 0 ) {
       return dp[lo][hi][playa] = max( solve(lo, hi-1, 1)+a[hi], solve( lo+1, hi, 1 )+a[lo]  );
    } else {
      if( a[lo] >= a[hi] ) return dp[lo][hi][playa] = solve( lo+1, hi, 0 );
      else return dp[lo][hi][playa] = solve( lo, hi-1, 0 );
    }
    
}

int main(){
    
    int n;
    int i, j, b, g;
    int sum, gm = 1;
    
    while( scanf("%d", &n ) &&n ){
           
           sum = 0;
           for( i = 0; i < n; i++ ){
                scanf("%d", a+i );
                sum += a[i];
           }
           
           for( i = 0; i < n; i++ )
                for( j = 0; j < n; j++ )
                     dp[i][j][0] = dp[i][j][1] = -1;
                                
           
           printf("In game %d, the greedy strategy might lose by as many as %d points.\n", gm++, 2*solve( 0, n-1, 0 )-sum );
    }

    return 0;    
}
