#include <stdio.h>
#include <stdlib.h>

#define MAXN 31000

typedef struct{
  int lo, hi, prof;
} ord;

int comp( const void *a, const void *b ){
    return ((ord*)a)->hi - ((ord*)b)->hi;
}

int max( int a, int b ){ if( a > b ) return a; return b; }

ord order[MAXN];
int b[MAXN];
int dp[MAXN];

int main(){

    int t, ct;
    int n, i, j;
    
    scanf("%d", &t );
    for( ct = 1; ct <= t; ct++ ){
         
         scanf("%d", &n );
         for( i = 0; i < n; i++ ){
              scanf("%d %d %d", &order[i].lo, &order[i].hi, &order[i].prof );
              order[i].hi += order[i].lo - 1;
         }    
         qsort( order, n, sizeof( ord ), comp );
         
         for( i = 0; i < n; i++ ){
              
              for( j = i-1; j >= 0; j-- )
                   if( order[j].hi < order[i].lo ) break;
              b[i] = j;
              
         }
         
         dp[0] = order[0].prof;
         for( i = 1; i < n; i++ )
              dp[i] = max( ( (b[i]>-1)?(dp[b[i]]):(0) ) + order[i].prof, dp[i-1]  );
         
         printf("Case %d: %d\n", ct, dp[n-1] );
    }
        
    return 0;
}
