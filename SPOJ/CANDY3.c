#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int t;
    long long n, cn, sum, a;
    
    scanf("%d", &t );
    while( t-- ){
           scanf("%lld", &n );
           cn = n;
           sum = 0ll;
           while( cn-- ){
                  scanf("%lld", &a );
                  sum += a;
                  sum %= n;
           }
           if( sum ) puts("NO");
           else puts("YES");
    }
    
    return 0;
}
