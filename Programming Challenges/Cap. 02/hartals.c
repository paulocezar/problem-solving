#include <stdio.h>
#include <stdlib.h>

int main(){
    
    char partyDay[3652];
    int cases, i, j, x, out;
    int simulationDays;
    int hartalsParam[101];
    int politicalParties;
    
    scanf("%d", &cases );
    while( cases-- ){
           scanf("%d", &simulationDays );
           scanf("%d", &politicalParties );
           out = 0;
           
           for( i = 1; i <= simulationDays; i++ )
                partyDay[i] = 0;
           
           for( i = 0; i < politicalParties; i++ )
                scanf("%d", &hartalsParam[i] );
           
           x = politicalParties;
           j = 1;
           while( x ){

                  for( i = 0; i < politicalParties; i++ )
                       if( hartalsParam[i] ){
                           partyDay[hartalsParam[i]*j]=1;
                           if( hartalsParam[i]*(j+1) > simulationDays ){
                               hartalsParam[i] = 0; x--;
                           }
                       }
                  j++;
           }
           
           out = 0;
           for( i = 1; i <= simulationDays; i++ )
               if( partyDay[i] ){
                   x = i%7;
                   if( x != 0 && x != 6 ) out++;
               }
           printf("%d\n", out );      
    }
    
    return 0;    
}
