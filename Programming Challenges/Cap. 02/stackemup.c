#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NVALUES 13
#define NSUITS 4
#define MAX_SHUFFLES 101

int shuffle[MAX_SHUFFLES][53];
int deck[53];
int temp[53];

void apply_shuffle( int x ){
     int i;
     for( i = 1; i < 53; i++ )
          temp[i] = deck[shuffle[x][i]];
     for( i = 1; i < 53; i++ )
          deck[i] = temp[i];
     return;
}

int main(){
    
    char values[NVALUES][6] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
    char suits[NSUITS][9] = { "Clubs", "Diamonds", "Hearts", "Spades" };
    
    int cases;
    int n, i, j;
    char line[5];
    
    scanf("%d", &cases );
    while( cases-- ){
    
           scanf("%d", &n );
           for( i = 1; i < 53; i++ ) deck[i] = i;
           
           for( i = 1; i <= n; i++ )
                for( j = 1; j < 53; j++ )
                     scanf("%d", &shuffle[i][j] );
           getchar(); 
           
           while( gets( line ) ){
                  
                  if( line[0] == 0 ) break;
                  sscanf( line, "%d", &n );
                  apply_shuffle( n );       
           }
           
           for( i = 1; i < 53; i++ )
                printf("%s of %s\n", values[(deck[i]-1)%NVALUES], suits[(deck[i]-1)/NVALUES] );
           if( cases ) printf("\n");
    }
    return 0;
    
}
