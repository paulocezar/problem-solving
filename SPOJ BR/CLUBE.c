#include <stdio.h>
#include <stdlib.h>

#define INF 0x4FFFFFFF

int m, n, l, numTabuas;
int tabuas[100005];

int comp( const void* a, const void* b ){
    return *(int*)a - *(int*)b;
}

int numTabs(){
    
    if( ( ( 100 * m ) % l ) != 0 ) return INF;
    
    int precisa = ( 100 * m ) / l;
    int ntab = 0;
    int i, t, tem = 0, p = 0;
        
    i = numTabuas-1;
    while( tabuas[i] > n ) i--;
    while( tabuas[i] == n ){ ntab++; tem++; i--; }
    if( tem >= precisa ) return precisa;
    
    for( ; p < i; i-- ){
         t = tabuas[p] + tabuas[i];
         if( t == n ){
             ntab += 2;
             tem++;
             p++;
         }
         else if( t < n ){
              p++; i++;
         }
         if( tem == precisa ) return ntab;
    }
    
    return INF;
}

int main(){
    

    int i, a, b, out;
    
    while( 1 ){
           scanf("%d %d", &m, &n );
           if( (m+n) == 0 ) break;
                        
           scanf("%d", &l );
           scanf("%d", &numTabuas );       
               
           for( i = 0; i < numTabuas; i++ )
                scanf("%d", &tabuas[i] );
           
           qsort( tabuas, numTabuas, sizeof( int ), comp );
           
           a = numTabs();
           b = m; m = n; n = b;
           b = numTabs();
           
           if( a < b ) out = a;
           else out = b;
           
           if( out != INF )
               printf("%d\n", out );
           else
               printf("impossivel\n");
           
    }

    return 0;    
}
