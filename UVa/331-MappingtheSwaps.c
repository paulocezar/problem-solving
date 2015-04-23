#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 6

int n, map, min_swaps;
int a[MAXN];

char ordered(){
     int i = 0;
     while( i < n-1 ){
            if( a[i] > a[i+1] ) return 0;
            i++;
     }
     return 1;
}

void calcMin(){
    int i = 0, j;
    
    min_swaps = 0;
    while( i < n ){
           j = i+1;
           while( j < n ){
                  if( a[j] < a[i] ) min_swaps++;
                  j++;       
           }       
           i++;
    }
}

void solve( int swaps ){
     if( swaps > min_swaps ) return;
     if( swaps == min_swaps ){
         if( ordered() ) map++;
         return;
     }
     int i;
     
     for( i = 0; i < n-1; i++ ){
          a[i] ^= a[i+1];
          a[i+1] ^= a[i];
          a[i] ^= a[i+1];
          solve( swaps+1 );
          a[i] ^= a[i+1];
          a[i+1] ^= a[i];
          a[i] ^= a[i+1];     
     }
}


int main(){
    
    int i, inp_set = 1;
    while( 1 ){
           
           scanf("%d", &n );
           if( n == 0 ) return 0;
           
           i = 0;
           while( i < n ) scanf("%d", a+(i++) );
           
           calcMin();
           map = 0;
           if( min_swaps != 0 ) solve( 0 );
           printf("There are %d swap maps for input data set %d.\n", map, inp_set++ );
           
    }
    return 0;
           
    
}
