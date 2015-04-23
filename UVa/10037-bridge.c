#include <stdio.h>
#include <stdlib.h>

#define MAXP 1002

int answer[2*MAXP][2];
int times[MAXP];
int n, total;
     
void solve(){

  int i = 0, j;
  
  total = 0;
  j = ( n / 2 ) - 1;
  
  /*
   * a = times[0]  -- fastest
   * b = times[1]  -- second fastest
   * c = times[n-2*i-1]  --  lowest
   * d = times[n-2*i-2]  --  second lowest
   * if(  2*b <= a + d ) 
   *    a, b go
   *    a back
   *    c, d go
   *    b back
   * else
   *    a, d go
   *    a back
   *    a, c go
   *    a back
   */
  
  for( i = 0; i < j; i++ ){
       
       if( (2*times[1]) <= (times[0] + times[n-2*i-2] ) ){
           answer[4*i][0] = times[0];
           answer[4*i][1] = times[1];
           answer[4*i+1][0] = times[0];
           answer[4*i+2][0] = times[n-2*i-2];
           answer[4*i+2][1] = times[n-2*i-1];
           answer[4*i+3][0] = times[1];
           total += ( (2*times[1]) + times[0] + times[n-2*i-1] );
       } else {
           answer[4*i][0] = times[0];
           answer[4*i][1] = times[n-2*i-2];
           answer[4*i+1][0] = times[0];
           answer[4*i+2][0] = times[0];
           answer[4*i+2][1] = times[n-2*i-1];
           answer[4*i+3][0] = times[0];
           total += ( (2*times[0]) + times[n-2*i-2] + times[n-2*i-1] );
       }
  }
  
  if( n % 2 ){
      answer[4*i][0] = times[0];
      answer[4*i][1] = times[1];
      answer[4*i+1][0] = times[0];
      answer[4*i+2][0] = times[0];
      answer[4*i+2][1] = times[2];
      total += ( times[0] + times[1] + times[2] );
  }
  else{
      answer[4*i][0] = times[0];
      answer[4*i][1] = times[1];
      total +=  times[1];
  }

}

int comp( const void* a, const void* b ){
    return *(int*)a - *(int*)b;
}
     
int main(){

  int cases;
  int i, j;

  scanf("%d", &cases );
  
  while( cases-- ){
         
    scanf("%d", &n );    
    
    for( i = 0; i < n; i++ )
         scanf("%d", &times[i] );
         
    if( n < 2 )
      printf("%d\n%d\n", times[0], times[0] );
    else{
         
      qsort( times, n, sizeof( int ), comp );
      solve();
      
      j = ((n-1)*2)-1;
      printf("%d\n", total );
      for( i = 0; i < j; i++ ){
        printf("%d", answer[i][0] );
        if( i % 2 == 0 ) printf(" %d", answer[i][1] );
        printf("\n");
      }
      
    }
    
    if( cases ) printf("\n");
    
  }
  
  return 0;
}
