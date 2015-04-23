#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXR 15
#define MAXC 105

int main(){
    
    int r, c, i, j;
    int table[MAXR][MAXC];
    int dp[MAXR][MAXC];
    int next[MAXR][MAXC];
    int a, b, _c, va, vb, vc, n, best;
    
    while( scanf("%d %d", &r, &c ) != EOF ){
           
           for( i = 0; i < r; i++ )
                for( j = 0; j < c; j++ )
                     scanf("%d", &table[i][j] );
                     
           for( i = 0; i < r; i++ )
                dp[i][c-1] = table[i][c-1];
    
           for( j = c-2; j >= 0; j-- ){
                
                for( i = 0; i < r; i++ ){
                
                     a = i;
                     b = (i+1) % r;
                     _c = (i+r-1) % r;
                     
                     va = table[i][j] + dp[a][j+1];
                     vb = table[i][j] + dp[b][j+1];
                     vc = table[i][j] + dp[_c][j+1];
                    
                     best = va; n = a;
                     if( (vb < best) || (vb == best && b < n ) ) best = vb, n = b; 
                     if( (vc < best) || (vc == best && _c < n ) ) best = vc, n = _c;
                                        
                     dp[i][j] = best;
                     next[i][j] = n;
                }     
           }
           
           best = INT_MAX;
           for( i = 0; i < r; i++ ) if( dp[i][0] < best )
                best = dp[i][0], n = i;
                
           printf("%d", (n+1) );
           for( i = 0; i < c-1; i++  ){
                  printf(" %d", ( next[n][i] + 1 )  );
                  n = next[n][i];
           }
           printf("\n%d\n", best);
    }

    return 0;    
}
