#include <stdio.h>
#include <stdlib.h>

#define MAXN 11
#define INF 0x3F3F3F3F

int s[MAXN][MAXN];

void printAnsr( int i, int j ){
     
     if( i == j )
         printf("A%d", i );
     else{
         printf("("); 
         printAnsr( i, s[i][j] );
         printf(" x ");
         printAnsr( s[i][j]+1, j );
         printf(")");
     }
     
     
}

int main(){
    
    int ncase = 1, n, i, j, k, l, li, q;
    int r[MAXN], c[MAXN];
    int m[MAXN][MAXN];
    
    for( i = 1; i < MAXN; i++ )
         m[i][i] = 0;
         
    while( 1 ){
         
         scanf("%d", &n );
         if( n == 0 ) return 0;
         
         for( i = 1; i <= n; i++ )
              scanf("%d %d", &r[i], &c[i] );
         
         
         for( l = 2; l <= n; l++ ){
              li = n-l+1;
              for( i = 1; i <= li; i++ ){
                   j = i + l - 1;
                   m[i][j] = INF;   
                   
                   for( k = i; k < j; k++ ){
                        
                        q = m[i][k] + m[k+1][j] + r[i]*c[k]*c[j];
                        
                        if( q < m[i][j] ) m[i][j] = q, s[i][j] = k;
                   
                   }
              }
         }
         
         printf("Case %d: ", ncase++ );
         printAnsr( 1, n );
         printf("\n");
           
    }
    
    return 0;    
}
