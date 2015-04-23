#include <stdio.h>
#include <stdlib.h>

#define MAXN 101000
#define LG 16

typedef struct {
int max1, max2;
} ans;

int a[MAXN];
int M1[1<<(LG+2)];
int M2[1<<(LG+2)];
int i, j, v;

void build( int node, int lo, int hi ){
     
     if( lo == hi ){
         M1[node] = a[lo];
         M2[node] = -1;   
     } else {
         int lft, rgt;
         lft = 2*node, rgt = 2*node+1;
         build( lft, lo, (lo+hi)/2 );
         build( rgt, (lo+hi)/2+1, hi );
         if( M1[lft] > M1[rgt] ){
             M1[node] = M1[lft];
             if( M2[lft] > M1[rgt] ) M2[node] = M2[lft];
             else M2[node] = M1[rgt]; 
         } else {
             M1[node] = M1[rgt];
             if( M2[rgt] > M1[lft] ) M2[node] = M2[rgt];
             else M2[node] = M1[lft];
         }
     }

}

void update( int node, int lo, int hi ){
     
     if( lo > j || hi < i ) return;
     
     if( lo == hi ){
         M1[node] = v;
         a[lo] = v; 
     } else {
         
         int lft, rgt;
         lft = 2*node, rgt = 2*node+1;
         update( lft, lo, (lo+hi)/2 );
         update( rgt, (lo+hi)/2+1, hi );
         
         if( M1[lft] > M1[rgt] ){
             M1[node] = M1[lft];
             if( M2[lft] > M1[rgt] ) M2[node] = M2[lft];
             else M2[node] = M1[rgt]; 
         } else {
             M1[node] = M1[rgt];
             if( M2[rgt] > M1[lft] ) M2[node] = M2[rgt];
             else M2[node] = M1[lft];
         }
     }
}

ans get( int node, int lo, int hi ){
    
    ans r, r1, r2;
    r.max1 = -1;
    if( lo > j || hi < i ) return r;
    if( lo >= i && hi <= j  ){
        r.max1 = M1[node];
        r.max2 = M2[node];
        return r;
    }

    r1 = get( 2*node, lo, (lo+hi)/2 );
    r2 = get( 2*node+1, (lo+hi)/2 +1, hi );

    if( r1.max1 == -1 ) return r2;
    else if( r2.max1 == -1 ) return r1;
    else{
         
         if( r1.max1 > r2.max1 ){
             r.max1 = r1.max1;
             if( r1.max2 > r2.max1 ) r.max2 = r1.max2;
             else r.max2 = r2.max1; 
         } else {
             r.max1 = r2.max1;
             if( r2.max2 > r1.max1 ) r.max2 = r2.max2;
             else r.max2 = r1.max1;
         }
         return r;
    }

}

int main(){

    int n, q;
    char qtype;
    ans resp;
    
    scanf("%d", &n );
    for( i = 0; i < n; i++ ) scanf("%d", a+i );
    
    build( 1, 0, n-1 );
    scanf("%d", &q ); getchar();
    
    while( q-- ){
           
           scanf("%c %d %d", &qtype, &i, &j ); getchar();
           if( qtype == 'U' ){
               i--;
               v = j;
               j = i;
               update( 1, 0, n-1 );
           } else {
               i--, j--;
               resp = get( 1, 0, n-1 );
               printf("%d\n", resp.max1+resp.max2 );
           }
    }
    

    return 0;    
}
