#include <stdio.h>
#include <stdlib.h>

#define MAXN 102
#define INF 0x3F3F3F3F

int main(){
    
    int collumn[MAXN][MAXN];
    int n, a, b, c, x, cur, max;
       
    while( scanf("%d", &n ) != EOF ){
    
           for( a = 1; a <= n; a++ )
                for( b = 1; b <= n; b++ ){
                     scanf("%d", &x );
                     collumn[a][b] = collumn[a-1][b] + x;
                }
  
           max = -INF;     
           for( a = 1; a <= n; a++ )
                for( b = a; b <= n; b++ ){
                     cur = 0;
                     for( c = 1; c <= n; c++ ){
                          cur += collumn[b][c] - collumn[a-1][c];
                          
                          if( cur > max ) max = cur;
                          if( cur < 0 ) cur = 0;
                     }
                }
                
           printf("%d\n", max );
  
    }

    return 0;    
}
