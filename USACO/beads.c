/*
ID: knightp2
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
        
    FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");

    char necklace[710], *ptr;
    int i, j, n, max, rc[710], bc[710];
    
    fscanf( fin, "%d\n", &n );
    fscanf( fin, "%s", necklace );

    ptr = necklace + n ;
    i = 0;
    while( i < n ) *ptr = necklace[i++], ptr++;
    *ptr = 0;
    
    
    if( necklace[n+n-1]=='b' || necklace[n+n-1]=='w' ) bc[n+n-1] = 1;
    else bc[n+n-1] = 0;
    
    if( necklace[0]=='r' || necklace[0]=='w' ) rc[0] = 1;
    else rc[0] = 0;
    
    j = 1;
    for( i = n+n-2; i >= 0; i--, j++ ){
         
         if( necklace[i] == 'b' || necklace[i] == 'w' )
             bc[i] = bc[i+1] + 1;
         else
             bc[i] = 0;
             
         if( necklace[j] == 'r' || necklace[j] == 'w' )
             rc[j] = rc[j-1] + 1;
         else
             rc[j] = 0;
              
    }
    
    max = 0;
    for( i = 0; i < n; i++ )
         if( (rc[i] + bc[i+1]) > max ) max = rc[i] + bc[i+1];
        
    fprintf( fout, "%d\n", max );
    
    return 0;
}

