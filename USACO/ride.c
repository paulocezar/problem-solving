/*
ID: knightp2
LANG: C
TASK: ride
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char comet[8], group[8];
    int a, b, i;
    
    fscanf( fin, "%s %s", comet, group );
    
    a = 1; i = 0;
    while( comet[i] ){ a *= (comet[i] - 'A' + 1); i++; }
    
    b = 1; i = 0;
    while( group[i] ){ b *= (group[i] - 'A' + 1); i++; }
    
    a = a % 47;
    b = b % 47;
    
    fprintf( fout, "%s\n", (a == b ) ? "GO" : "STAY" );

    return 0;
}

