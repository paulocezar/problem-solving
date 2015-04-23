#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXM 310
#define MAXN 310
#define INF 0x3F3F3F3F

int m, n, f;
int seats[MAXM][MAXN];

int solve(){
    
    int i, j, b, k, sum, ans;
    ans = INF;
    
    for( i = 1; i <= m; i++ ){
         
         for( j = i; j <= m; j++ ){

             b = 0, sum = 0;
			 k = 0;
			 while( k < n ){
              
                   sum += (seats[j][k]-seats[i-1][k]);
                   
				 if( sum >= f ){                   
					 while( b < k && (sum-(seats[j][b]-seats[i-1][b]))>=f ){
                          sum -= (seats[j][b]-seats[i-1][b]);
                          b++;
					 }
              

                       if( (j-i+1)*(k-b+1) < ans ) ans = (j-i+1)*(k-b+1);
                  }
				   k++;
              
              }
              
              
         }

         
    }
    
    return ans;
    
}

int main(){
    
    int i, j, k;
    char line[MAXM][MAXN];
    
    for( j = 0; j < MAXN; j++ ) seats[0][j] = 0;
    
	scanf("%d %d %d", &m, &n, &f );
    
	while( (m+n+f) != 0 ){
           
           getchar();
        
		   for( i = 1; i <= m; i++ ) gets( line[i] );
		
           for( i = 1; i <= m; i++ ){
                for( j = 0; j < n; j++ ){
                     if( line[i][j] == '.' ) seats[i][j] = seats[i-1][j] + 1;
                     else seats[i][j] = seats[i-1][j];
                }
           }
           
           printf("%d\n", solve() );
		   scanf("%d %d %d", &m, &n, &f );
    }
	
	return 0;
    
}
