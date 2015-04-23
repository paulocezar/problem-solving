#include <stdio.h>
#include <stdlib.h>

#define MAXN 51000
#define LG 16

typedef struct {
   int sum;
   int pref;
   int suf;
   int max;
   char nil;
}node;

int a[MAXN];
node M[1<<(LG+2)];
node aux;
int i, j, v;

inline int max( int a, int b ){ if( a > b ) return a; return b; }

void build( int cur, int lo, int hi ){
     
     if( lo == hi ){
         M[cur].sum = a[lo];
         M[cur].pref = a[lo];
         M[cur].suf = a[lo];
         M[cur].max = a[lo];
     } else {
         
         build( 2*cur, lo, (lo+hi)/2 );
         build( 2*cur+1, (lo+hi)/2 + 1, hi );
         
         M[cur].sum = M[2*cur].sum + M[2*cur+1].sum;
         M[cur].pref = max( M[2*cur].pref, M[2*cur].sum + M[2*cur+1].pref );
         M[cur].suf = max( M[2*cur+1].suf, M[2*cur+1].sum + M[2*cur].suf );
         M[cur].max = max( M[2*cur].max, M[2*cur+1].max );
         M[cur].max = max( M[cur].max, M[2*cur].suf + M[2*cur+1].pref );
         
     }
     M[cur].nil = 0;
}

void up( int cur, int lo, int hi ){
     
     if( i > hi || j < lo ) return;
     if( lo >= i && hi <= j ){
         M[cur].sum = a[lo];
         M[cur].pref = a[lo];
         M[cur].suf = a[lo];
         M[cur].max = a[lo];
     } else {
            
         up( 2*cur, lo, (lo+hi)/2 );
         up( 2*cur+1, (lo+hi)/2 + 1, hi );
         
         M[cur].sum = M[2*cur].sum + M[2*cur+1].sum;
         M[cur].pref = max( M[2*cur].pref, M[2*cur].sum + M[2*cur+1].pref );
         M[cur].suf = max( M[2*cur+1].suf, M[2*cur+1].sum + M[2*cur].suf );
         M[cur].max = max( M[2*cur].max, M[2*cur+1].max );
         M[cur].max = max( M[cur].max, M[2*cur].suf + M[2*cur+1].pref );
     
     }
     
}

node get( int cur, int lo, int hi ){
    
    if( i > hi || j < lo ) return aux;
    if( lo >= i && hi <= j ){
        return M[cur];
    } else {
         node q1, q2; 
         q1 = get( 2*cur, lo, (lo+hi)/2 );
         q2 = get( 2*cur+1, (lo+hi)/2 + 1, hi );
         
         if( q1.nil ) return q2;
         else if( q2.nil ) return q1;
         else{
              node ans;
              ans.sum = q1.sum + q2.sum;
              ans.pref = max( q1.pref, q1.sum + q2.pref );
              ans.suf = max( q2.suf, q2.sum + q1.suf );
              ans.max = max( q1.max, q2.max );
              ans.max = max( ans.max, q1.suf + q2.pref );
              ans.nil = 0;
              return ans;
         }
     }
    
}

int main(){
    
    int q, m, n;
    
    scanf("%d", &n );
    for( i = 0; i < n; i++ ) scanf("%d", a+i );
    build( 1, 0, n-1 );
    
    aux.sum = 0;
    aux.pref = 0;
    aux.suf = 0;
    aux.max = 0;
    aux.nil = 1;
    
    scanf("%d", &m );
    while( m-- ){
           scanf("%d %d %d", &q, &i, &j );
           if( q ){
               i--, j--;
               printf("%d\n", get( 1, 0, n-1 ).max );
           } else {
               i--;
               a[i] = j;
               j = i;
               up( 1, 0, n-1 );
           }
    }
    
    return 0;    
}
