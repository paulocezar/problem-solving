#include <stdio.h>
#include <stdlib.h>

int main(){

    int t, ct;
    int n, p, q, sum, ans;
    int i, g;
    
    scanf("%d", &t );
    for( ct = 1; ct <= t; ct++ ){
    
         scanf("%d %d %d", &n, &p, &q );
         ans = sum = 0;
         for( i = 0; i < n; i++ ){
              scanf("%d", &g );
              if( sum+g <= q && ans<p ){ sum += g; ans++; }
         }
         printf("Case %d: %d\n", ct, ans );
    }
        
    return 0;
}
