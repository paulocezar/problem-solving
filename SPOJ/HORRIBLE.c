#include <stdio.h>
#include <stdlib.h>

#define MAXN 101000
#define LG 17

long long sum[1<<(LG+1)];
long long add[1<<(LG+1)];
long long v;
int i, j;

void build( int node, int lo, int hi ){
     if( lo == hi ){
         add[node] = 0ll;
         sum[node] = 0ll;
     } else {
         build( 2*node, lo, (lo+hi)>>1 );
         build( 2*node+1, ((lo+hi)>>1)+1, hi );   
         add[node] = 0ll;
         sum[node] = 0ll;
     }
}

void update( int node, int lo, int hi ){
    
    if( i <= lo && hi <= j ){
        add[node] += v;
        sum[node] += (hi-lo+1)*v;
    } else {
      int mid = (lo+hi)>>1;
      if( i <= mid ) update( 2*node, lo, mid );
      if( j >= mid+1 ) update( 2*node+1, mid+1, hi );
    
      sum[node] = sum[2*node] + sum[2*node+1] + (hi-lo+1)*add[node];

   }
}

long long get( int node, int lo, int hi, long long added ){
    
    if( i <= lo && hi <= j ){
        return sum[node] + (hi-lo+1)*added;
    } else {
      
      int mid = (lo+hi)>>1;
      long long s1, s2;
      s1 = s2 = 0ll;
      
      if( i <= mid ) s1 = get( 2*node, lo, mid, added+add[node] );
      if( j >= mid+1 ) s2 = get( 2*node+1, mid+1, hi, added+add[node] );
    
      return s1 + s2;
   }
    
}

int main(){
    
    int t, n, c, tp;
    
    scanf("%d", &t );
    while( t-- ){
           scanf("%d %d", &n, &c );
           build( 1, 0, n-1 );
           while( c-- ){
                  scanf("%d", &tp );
                  if( tp ){
                      scanf("%d %d", &i, &j );
                      i--, j--;
                      printf("%lld\n", get( 1, 0, n-1, 0ll ) );
                  } else {
                      scanf("%d %d %lld", &i, &j, &v );
                      i--, j--;
                      update( 1, 0, n-1 );
                  }
           }       
    }
    
    return 0;    
}
