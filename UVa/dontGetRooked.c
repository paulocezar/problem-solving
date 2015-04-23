#include <stdio.h>
#include <stdlib.h>

#define MAXN 6

char tab[MAXN][MAXN];
int n, put = 0, max;

char valid( x, y ){
 
    int i;
     
    if( tab[x][y] == '.' ){
    
        for( i = y+1; tab[x][i] && tab[x][i] != 'X'; i++ )
             if( tab[x][i] == 'R' ) return 0;
        
        for( i = y-1; tab[x][i] && tab[x][i] != 'X'; i-- )
             if( tab[x][i] == 'R' ) return 0;
        
        for( i = x+1; tab[i][y] && tab[i][y] != 'X'; i++ )
             if( tab[i][y] == 'R' ) return 0;
        
        for( i = x-1; tab[i][y] && tab[i][y] != 'X'; i-- )
             if( tab[i][y] == 'R' ) return 0;
             
        return 1;
        
    
    }
    else return 0;    
}

void putRook( int x, int y ){
 
     if( valid( x, y ) ){
         tab[x][y] = 'R';
         put++;
         if( put > max ) max = put;
         if( y+1 <= n )
             putRook( x, y+1 );
         else if( x + 1 <= n )
             putRook( x+1, 1 );
         tab[x][y] = '.';
         put--;
     }
     
     if( y+1 <= n )
         putRook( x, y+1 );
     else if( x + 1 <= n )
         putRook( x+1, 1 );
         
         
}

int main(){
    
    int i;
    
    memset( tab[0], 0, sizeof( char ) * ( MAXN + 1 ) );
    for( i = 1; i <= MAXN; i++ )
         tab[i][0] = 0;
         
    while( 1 ){
           scanf("%d", &n ); getchar();
           if( n == 0 ) return 0;
    

           memset( tab[n+1], 0, sizeof( char ) * n  );
           
           for( i = 1; i <= n; i++ )
                { scanf("%s\n", (tab[i]+1) ); getchar(); }

           
           max = put = 0;     
           putRook( 1, 1 );
           
           printf("%d\n", max );
           
           
    }    
    
    

    return 0;    
}
