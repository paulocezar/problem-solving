#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    
    long long t, pos;
    long long x, y;
    long long camada;
    long long aux, dist;
    
    while( 1 ){
           
           scanf("%lld %lld", &t, &pos);
           if( (t+pos) == 0ll ) return 0;
           
           x = t/2ll + 1ll;
           y = x;
           
           if( pos == 1ll ) goto hell;
           
           camada = ceil( sqrt( pos ) );
           if( camada%2ll == 0 ) camada++;                     
           aux = camada*camada;
           
           x += camada/2ll;
           y += camada/2ll;
           
           dist = aux - pos;
           
           aux = dist / ( camada-1ll);
           dist %= (camada-1ll);
           
           if( aux == 0ll ) x -= dist;
           else if( aux == 1ll ) x -= (camada-1ll), y -= dist;
           else if( aux == 2ll ) { x -= (camada-1ll), y-= (camada-1ll); x += dist; }
           else { y -= ( camada-1ll ); y += dist; }
           
    hell:
         printf("Line = %lld, column = %lld.\n", x, y );
           
           
    }
    
    return 0;    
}
