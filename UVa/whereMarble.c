#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10001

char f[MAX];
int tree[MAX];

void update( int idx ){
     while( idx <= MAX ){
            tree[idx]++;
            idx += ( idx & -idx );
     }     
}

int read( int idx ){
    int sum = 0;
    while( idx > 0 ){
           sum += tree[idx];
           idx -= ( idx & -idx );
    }
    return sum;   
}

int main(){
    
    int n, q, i, x, c = 1;
    
    while( 1 ){
           scanf("%d %d", &n, &q );
           if( (n+q) == 0 ) return 0;
           
           memset( tree, 0, sizeof( tree ) );
           memset( f, 0, sizeof( f ) );
           for( i = 0; i < n; i++ ){
                scanf("%d", &x );
                update( x );
                f[x] = 1;
           }
           
           printf("CASE# %d:\n", c++ );
           for( i = 0; i < q; i++ ){
                scanf("%d", &x );
                if( f[x] ) printf("%d found at %d\n", x, read( x-1 )+1 );
                else printf("%d not found\n", x );
           }
    
    }  

    return 0;    
}
