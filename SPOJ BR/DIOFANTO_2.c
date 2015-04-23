#include <stdio.h>
#include <stdlib.h>

long long f[2000006];
long long x = 1ll;
int last = 0;

long long extended_gcd( long long* a, long long b) {
    
    long long x = 0ll, lastx = 1ll;
    long long y = 1ll, lasty = 0ll;
    long long temp;
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

long long inverse( long long a, long long m ){
         
    long long x = extended_gcd( &a, m );
    return ( (x + m) % m );

}

void fat( int n ){
	
	int i;
	
	for( i = last+1; i <= n; i++, x++ )
		f[i] = ( x * f[i-1] ) % 1300031ll;
	last = n;
	return;
}

int main(){
    

    int t, n;
    long long c, out, num, den;
    
	f[0] = 1ll;
    
	scanf("%d", &t );
    while( t-- ){
    
           scanf("%d %lld", &n, &c );        
		
		   if( last < n+c-1 ) fat( n+c-1 );
		
           num = f[c+n-1];
		   den = ( f[n-1]*f[c] ) % 1300031ll ;
		   den = inverse( den, 1300031ll );
          
		   out = ( num * den ) % 1300031ll;
           
           printf("%lld\n", out );
           
    }
    
    
    return 0;

}
