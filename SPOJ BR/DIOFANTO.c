#include <stdio.h>
#include <stdlib.h>

unsigned long long x = 1llu;
unsigned long long f[1000001];
int last = 0;

void fat( int n ){
     
     int i;
     
     for( i = last+1; i <= n; i++, x++ )
          f[i] = ( x * f[i-1] ) % 1300031llu;
     
     last = n;  
}


int extended_gcd( int* a, int b) {
    
    int x = 0, lastx = 1;
    int y = 1, lasty = 0;
    int temp;
    div_t q;
 
    while( b ){
        q = div( *a, b );
        *a = b;
        b = q.rem;
 
        temp = x;
        x = lastx - q.quot * x;
        lastx = temp;
 
        temp = y;
        y = lasty - q.quot * y;
        lasty = temp;
    }
 
    return lastx;
}
 
unsigned long long inverse( int a, int m ){
         
    int x = extended_gcd( &a, m );
    return ( unsigned long long ) ( (x + m) % m );

}

int main(){
    

    int t, n, i;
    unsigned long long c, out, k;
    f[0] = 1llu;

    scanf("%d", &t );
    while( t-- ){
    
           scanf("%d %llu", &n, &c );        
           
           out = c + 1llu;
           k = 2llu;
           for( i = 2; i < n; i++, k++ ){
                
                out = ( out * ( ( c + k ) % 1300031llu ) ) % 1300031llu;
                
                if( out ) continue;
                break;
           }
           
           if( out ){
           
               if( n-1 > last )
                   fat( n-1 );
                   
               out = out * inverse( ( int )f[n-1], 1300031 );
               out %= 1300031llu;
                   
           }
           
           printf("%llu\n", out );
           
    }
    
    
    return 0;

}
