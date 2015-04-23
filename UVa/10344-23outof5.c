#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char used[5];
int n[5], n_used;

char solve( int curr ){

     if( n_used == 5 && curr == 23 ) return 1;
     else if( n_used == 5 ) return 0;     
     
     int i;
     for( i = 0; i < 5; i++ ){
     
          if( !used[i] ){
              used[i] = 1;
              n_used++;
              if( solve( curr+n[i] ) ){
                  return 1;
              } else if( solve( curr-n[i] ) ){
                  return 1;       
              } else if( solve( curr*n[i] ) ){
                  return 1;       
              }
              n_used--;
              used[i] = 0;
          }
          
     }
     
     return 0;    
}

char play( int i ){

     n_used = 1;
     if( i == 5 ) return 0;
     
     used[i] = 1;
     if( solve( n[i] ) ) return 1;
     used[i] = 0;
     return play( i+1 );     
     
}

int main(){
    
    while( 1 ){
           
           scanf("%d %d %d %d %d", n, n+1, n+2, n+3, n+4 );
           if( ( n[0] + n[1] + n[2] + n[3] + n[4] ) == 0 ) return 0;
           
           used[0] = used[1] = used[2] = used[3] = used[4] = 0;
           
           if( play( 0 ) ) puts("Possible");
           else puts("Impossible");
    }
    return 0;
           
    
}
