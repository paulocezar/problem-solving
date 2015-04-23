#include <stdio.h>
#include <stdlib.h>

#define MAXN 101000
#define LG 16

typedef struct{
   int fst, lst, max;
} tnode;

inline int max( int a, int b ){ if( a > b ) return a; return b; }

int a[MAXN];
tnode M[1<<(LG+2)];
int i, j;

void build( int node, int lo, int hi ){
     if( lo == hi ){
         M[node].fst = M[node].lst = M[node].max = 1;
     } else {
         int mid = (lo+hi)/2;
         build( 2*node, lo, mid );
         build( 2*node+1, mid+1, hi );
         
         M[node].fst = M[2*node].fst;
         if( a[lo] == a[mid+1] )
             M[node].fst += M[2*node+1].fst;
          
         M[node].lst = M[2*node+1].lst;    
         if( a[hi] == a[mid] )
             M[node].lst += M[2*node].lst;
         
         if( M[2*node].max > M[2*node+1].max )
             M[node].max = M[2*node].max;
         else
             M[node].max = M[2*node+1].max;

         if( a[mid] == a[mid+1] && M[node].max <  M[2*node].lst+M[2*node+1].fst )
             M[node].max = M[2*node].lst+M[2*node+1].fst;
     }
}

tnode get( int node, int lo, int hi ){
    
    tnode r1, r2, ans;
    ans.max = 0;
    
    if( i > hi || j < lo ) return ans;
    if( lo >= i && hi <= j ) return M[node];
    
    r1 = get( 2*node, lo, (lo+hi)/2 );
    r2 = get( 2*node+1, (lo+hi)/2 + 1, hi );
    
    if( r1.max == 0 ) return r2;
    else if( r2.max == 0 ) return r1;
    else {
         int mid = (lo+hi)/2;
         
         ans.fst = r1.fst;
         if( a[lo] == a[mid+1] )
             ans.fst += r2.fst;
          
         ans.lst = r2.lst;    
         if( a[hi] == a[mid] )
             ans.lst += r1.lst;
         
         if( r1.max > r2.max )
             ans.max = r1.max;
         else
             ans.max = r2.max;

         if( a[mid] == a[mid+1] && ans.max <  r1.lst+r2.fst )
             ans.max = r1.lst+r2.fst;
             
         return ans;    
    }
    
}

int main(){

    int n, q;
    
    while( 1 ){
           scanf("%d", &n );
           if( n == 0 ) return 0;
           scanf("%d", &q );
           
           for( i = 0; i < n; i++ ) scanf("%d", a+i );
           
           build( 1, 0, n-1 );
           while( q-- ){
                  scanf("%d %d", &i, &j );
                  i--, j--;
                  printf("%d\n", get( 1, 0, n-1 ).max );
           }
    }
    return 0;
}
