#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
 
    int freq[27];
    int cases, r, c, m, n, i, j, x;
    int max, nmax, out;
    char line[22];
    
    memset( freq, 0, sizeof( freq ) );
    
    scanf("%d", &cases );
    for( x = 1; x <= cases; x++ ){
           
           scanf("%d %d %d %d", &r, &c, &m, &n ); getchar();
           for( i = 0; i < r; i++ ){
                gets( line );
                for( j = 0; j < c; j++ )
                     freq[line[j]-'A']++;           
           }
           
           max = nmax = 0;
           for( i = 25; i >= 0; i-- ){
                if( freq[i] > max ){ max = freq[i]; nmax = 1; }
                else if( freq[i] == max ) nmax++;
                freq[i] = 0;
           }
           
           out = ( nmax * max * m ) + ( n * ( (r*c) - (nmax*max) ) );
           
           printf("Case %d: %d\n", x, out );
           
           
    }
    
    return 0;
    
}
