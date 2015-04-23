#include <stdio.h>
#include <stdlib.h>

#define MAXN 310

int a[MAXN];
int b[MAXN];
int swp[MAXN*MAXN][2];

int main(){
    
    int n;
    int i, j, k;
    
    scanf("%d", &n );
    for( i = 0; i < n; i++ ) scanf("%d", a+i );
    for( i = 0; i < n; i++ ) scanf("%d", b+i );
    
    k = 0;
    
    for( i = 0; i < n; i++ ){
    
         if( b[i] != a[i] ){

             for( j = i+1; b[j] != a[i]; j++ );
             while( j > i )
             {
              swp[k][0] = j;
              swp[k][1] = j+1;
              k++;
              b[j] ^= b[j-1]; b[j-1] ^= b[j]; b[j] ^= b[j-1];    
              j--;
             }
         }
    
    }
    
    printf("%d\n", k );
    for( i = 0; i < k; i++ )
         printf("%d %d\n", swp[i][0], swp[i][1] );

    return 0;    
}
