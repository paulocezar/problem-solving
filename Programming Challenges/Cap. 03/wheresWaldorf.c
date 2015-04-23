#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m, n, w, sw;
char grid[51][51];
char words[21][51];

char up( int x, int y ){
     if( (x - sw + 1 ) < 0 ) return 0;
     int i;
          
     for( i = 1, x--; i < sw; i++, x-- )
          if( grid[x][y] != words[w][i] ) return 0;
     
     return 1;
}

char down( int x, int y ){
     if( (x + sw - 1 ) >= m ) return 0;
     int i;
     
     for( i = 1, x++; i < sw; i++, x++ )
          if( grid[x][y] != words[w][i] ) return 0;
     
     return 1;
}

char left( int x, int y ){
     if( (y + sw + 1 ) < 0 ) return 0;
     int i;
     
     for( i = 1, y--; i < sw; i++, y-- )
          if( grid[x][y] != words[w][i] ) return 0;
     
     return 1;
}

char right( int x, int y ){
     if( (y + sw - 1 ) >= n ) return 0;
     int i;
     
     for( i = 1, y++; i < sw; i++, y++ )
          if( grid[x][y] != words[w][i] ) return 0;
     
     return 1;
}

char upleft( int x, int y ){
     if( (x - sw + 1 ) < 0 || (y + sw + 1 ) < 0 ) return 0;
     int i;
          
     for( i = 1, y--, x--; i < sw; i++, x--, y-- )
          if( grid[x][y] != words[w][i] ) return 0;
     
     return 1;     
}

char upright( int x, int y ){
     if( (x - sw + 1 ) < 0 || (y + sw - 1 ) >= n ) return 0;
     int i;
          
     for( i = 1, x--, y++; i < sw; i++, x--, y++ )
          if( grid[x][y] != words[w][i] ) return 0;
     
     return 1;     
}

char downleft( int x, int y ){
     if( (x + sw - 1 ) >= m || (y + sw + 1 ) < 0 ) return 0;
     int i;
          
     for( i = 1, x++, y--; i < sw; i++, x++, y-- )
          if( grid[x][y] != words[w][i] ) return 0;
     
     return 1;     
}

char downright( int x, int y ){
     if( (x + sw - 1 ) >= m || (y + sw - 1 ) >= n ) return 0;
     int i;
          
     for( i = 1, x++, y++; i < sw; i++, x++, y++ )
          if( grid[x][y] != words[w][i] ) return 0;
     
     return 1;     
}

int main(){

    int cases, k;
    int i, j;
    char c, find;
    
    scanf("%d", &cases );
    while( cases-- ){
           scanf("%d %d", &m, &n ); getchar();
           for( i = 0; i < m; i++ ){
                for( j = 0; j < n; j++ ){
                    c = getchar();
                    if( c <= 'Z' ) c = c-'A'+'a';
                    grid[i][j] = c;
                }
                getchar();
           }
           scanf("%d", &k ); getchar();
           for( i = 0; i < k; i++ ){
                c = getchar(); j = 0;
                while( c && c != '\n' ){
                       if( c <= 'Z' ) c = c-'A'+'a';
                       words[i][j++] = c;
                       c = getchar();       
                }
                words[i][j] = 0;
           }
           
           for( w = 0; w < k; w++ ){
                find = 0;
                sw = strlen( words[w] );
                for( i = 0; i < m && !find; i++ )
                     for( j = 0; j < n; j++ )
                            if( grid[i][j] == words[w][0] ){
                                if( up( i, j ) || left( i, j ) || down( i, j ) || right( i, j ) ||
                                    upleft( i, j ) || upright( i, j ) || downleft( i, j ) || downright( i, j ) ){
                                            printf("%d %d\n", i+1, j+1 );
                                            find = 1;
                                            break;
                                }
                            }
           }
           if( cases ) printf("\n");
           
    }
        
    return 0;
}

