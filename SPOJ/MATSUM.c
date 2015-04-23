#include <stdio.h>
#include <stdlib.h>

#define MAXN 1030

int bit[MAXN][MAXN];
int grid[MAXN][MAXN];
int N;

int up( int x, int y, int val ){
    int ny;
    while( x <= N ){
           
           ny = y;
           while( ny <= N ){
                  bit[x][ny] += val;
                  ny += ( ny & -ny );
           }
           x += ( x & -x );
    }
}

int get( int x, int y ){
    int ny;
    int sum = 0;
    while( x  ){
           ny = y;
           while( ny ){
                  sum += bit[x][ny];
                  ny -= ( ny & -ny );
           }
           x -= ( x & -x );
    }
    return sum;
}

int main(){

    int t, x1, y1, x2, y2, val;
    char com[5];
    
    scanf("%d", &t );
    while( t-- ){
           
           scanf("%d", &N );
           for( x1 = 0; x1 <= N; x1++ )
                for( x2 = x1; x2 <= N; x2++ )
                     bit[x1][x2] = bit[x2][x1] = grid[x1][x2] = grid[x2][x1] = 0;
           
           scanf("%s", com );
           while( com[0] != 'E' ){
              
              if( com[1] == 'E' ){
                  scanf("%d %d %d", &x1, &y1, &val ); 
                  x1++, y1++;
                  up( x1, y1, val-grid[x1][y1] );
                  grid[x1][y1] = val;
              } else {
                  scanf("%d %d %d %d", &x1, &y1, &x2, &y2 );
                  x2++, y2++;
                  val = get( x2, y2 ) + get( x1, y1 ) - get( x1, y2 ) - get( x2, y1 );
                  printf("%d\n", val );
              }
              
              scanf("%s", com );
           }
           
    }

    return 0;    
}
