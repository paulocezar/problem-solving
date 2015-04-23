#include <stdio.h>
#include <stdlib.h>

#define MAXN 201000

int w[MAXN];
int tree[4*MAXN];

void build( int node, int lo, int hi ){
     
     if( lo == hi ){
         tree[node] = 1;
     } else {
         int mid = (lo+hi)>>1;
         tree[node] = hi-lo+1;
         build( 2*node, lo, mid );
         build( 2*node+1, mid+1, hi );
     }
     
}

int get( int node, int lo, int hi, int k ){
     
     tree[node]--;
     if( lo == hi ) return lo+1;
     
     if( k <= tree[2*node] )
         return get( 2*node, lo, (lo+hi)>>1, k );
     else 
         return get( 2*node+1, ((lo+hi)>>1) + 1, hi, k-tree[2*node] );
     
}

int main(){
    
    int t, i, n;
    
    scanf("%d", &t );
    while( t-- ){
    
           scanf("%d", &n );
           for( i = 0; i < n; i++ ) scanf("%d", &w[i] );
           
           build( 1, 0, n-1 );
           
           for( i = n-1; i >= 0; i-- )
                w[i] = get( 1, 0, n-1, i-w[i]+1 );
           
           printf("%d", w[0] );
           for( i = 1; i < n; i++ )
                printf(" %d", w[i] );
           puts("");
           
    }
    
    return 0;
}
