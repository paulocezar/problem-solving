#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int t, n, a, sum, max, minpref;
    long long mcnt, cnt;
    
    scanf("%d", &t );
    while( t-- ){
           
           scanf("%d", &n );
           
           sum = 0;
           minpref = 0;
           max = -0x3F3F3F3F;
           cnt = 1ll;
           mcnt = 1ll;
           while( n-- ){
                  scanf("%d", &a );
                  sum += a;
                  
                  if( sum-minpref > max ) max = sum-minpref, cnt = mcnt;
                  else if( sum-minpref==max ) cnt += mcnt;
                  
                  if( sum < minpref ) minpref = sum, mcnt = 1ll;
                  else if( sum == minpref ) mcnt++;
           }
           printf("%d %lld\n", max, cnt );
    }

    return 0;    
}
