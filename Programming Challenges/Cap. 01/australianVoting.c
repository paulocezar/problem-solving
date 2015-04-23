#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    int cases, n, i, j;
    char candidates[21][82];
    int ballots[1001][21];
    int* ballotp[1001];
    int votes[21];
    char eliminated[21];
    char ballot[150];
    int numBallots, winner, elect, max, min;
    char noWinner; char* p;
    
    scanf("%d", &cases );
    
    while( cases-- ){
           scanf("%d", &n ); getchar();
           
           memset( eliminated+1, 0, sizeof( char ) * n );
           memset( votes+1, 0, sizeof( int ) * n );
               
           for( i = 1; i <= n; i++ )
                gets( candidates[i] );
           
           i = 0;
           while( gets( ballot ) ){
                  if( ballot[0] == 0 ) break;
                  ballotp[i] = &ballots[i][0];
                  p = ballot;
                  for( j = 0; j < n; j++ ){
                    sscanf( p, "%d", &ballots[i][j] );
                    if( ballots[i][j] < 10 ) p+=2;
                    else p+= 3;
                  }
                  i++;
           }
           
           numBallots = i;
           winner = numBallots/2;
           
           noWinner = 1;
           
           for( i = 0; i < numBallots; i++ )
                votes[*ballotp[i]]++;

           do{
                                   
                  min = 2000; max = 0;
                  for( i = 1; i <= n; i++ ){
                       if( !eliminated[i] ){
                           if( votes[i] > winner ) { elect = i; max = 1; min = 2; noWinner = 0; break; }
                           if( votes[i] > max ) max = votes[i];
                           if( votes[i] < min ) min = votes[i];
                       }
                  }
                  
                  if( min == max ){ noWinner = 0; }
                  
                  if( noWinner ){
                      for( i = 1; i <= n; i++ )
                       if( votes[i] == min ) eliminated[i] = 1;
                       
                      for( i = 0; i < numBallots; i++ ){
                       if( eliminated[*ballotp[i]] ){
                           while( eliminated[*ballotp[i]] ) ballotp[i]++;
                           votes[*ballotp[i]]++;
                       }
                      }
                 
                  }
                  
           } while( noWinner );
           
           if( min == max ){
               for( i = 1; i <= n; i++ )
                    if( !eliminated[i] )
                        printf("%s\n", candidates[i] );
           }else
               printf("%s\n", candidates[elect] );
           if( cases > 0 ) printf("\n");
    }
    return 0;    
}
