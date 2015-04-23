#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10001

int main(){

    int n, m, i, j, p;
    int a, b, gcd, tickets[MAXN], totalTickets;
    char line[300]; line[0] = ' ';
    char *ptr;
    
    while( 1 ){
           scanf("%d %d", &n, &m ); getchar();
           if( (n+m) == 0 ) return 0;
           
           totalTickets = 0;
           for( i = 0; i < n; i++ ){
                gets( line+1 );
                ptr = line+1; 
                
                while( *ptr ) ptr++;
                ptr--;
                
                p = 1; a = 0;
                while( *ptr != ' ' ){
                       a += (*ptr-'0') * p;
                       p *= 10;
                       ptr--;
                }
                tickets[i] = a;
                totalTickets += a;
           }
           
           
           for( i = 0; i < n; i++ ){
                gcd = totalTickets; b = tickets[i];
                
                while( b ){
                       a = gcd;
                       gcd = b;
                       b = a % gcd;
                }
                
                printf("%d / %d\n", tickets[i]/gcd, totalTickets / gcd );
           }
                      
    }    
    
    return 0;
}

