#include <stdio.h>
#include <stdlib.h>

#define MAXN 150

int grid[MAXN][MAXN];
int ans[2];
int r, c, m, n;

void mark( int i, int j ){
     
     if( i < 0 || j < 0 || i >=r || j >= c ) return;
     if( grid[i][j] ) return;
    
     grid[i][j]++;
     
     mark( i+m, j+n );
     mark( i+m, j-n );
     mark( i-m, j+n );
     mark( i-m, j-n );
     mark( i+n, j+m );
     mark( i+n, j-m );
     mark( i-n, j+m );
     mark( i-n, j-m );

}

char check( int i, int j ){
 
     if( i < 0 || j < 0 || i >=r || j >= c ) return 0;
     if( grid[i][j] >= 0) return 1;
     return 0;
}
    
int main(){
    
    int t, ct;
    int w, i, j;
    
    scanf("%d", &t );
    for( ct = 1; ct <= t; ct++ ){
    
         scanf("%d %d %d %d", &r, &c, &m, &n );
         
         for( i = 0; i < r; i++ )
              for( j = 0; j < r; j++ )
                   grid[i][j] = 0;
                        
         scanf("%d", &w );
         while( w-- ){
                scanf("%d %d", &i, &j );
                grid[i][j] = -1;
         }
         
         ans[0] = ans[1] = 0;
         mark( 0, 0 );
         
         for( i = 0; i < r; i++ ){
              for( j = 0; j < c; j++ ){
                   if( grid[i][j] > 0 ){
                   int x = 0;
                   if( check( i+m, j+n ) ) x++;
                   if( check( i+m, j-n ) ) x++;
                   if( check( i-m, j+n ) ) x++;
                   if( check( i-m, j-n ) ) x++;
                   if( check( i+n, j+m ) ) x++;
                   if( check( i+n, j-m ) ) x++;
                   if( check( i-n, j+m ) ) x++;
                   if( check( i-n, j-m ) ) x++;
                   if( m == n ) x /= 2;
                   ans[ x%2 ]++;
                   }
              }

     }
              
         printf("Case %d: %d %d\n", ct, ans[0], ans[1] );
         
    }

    return 0;    
}
