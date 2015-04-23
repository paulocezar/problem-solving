/*
ID: knightp2
LANG: C
TASK: friday
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum{ SAT = 0, SUN = 1, MON, TUE, WED, THU, FRI } day;

char leap( int year ){
     if( year % 100 == 0 ) return ( year % 400 == 0 );
     return ( year % 4 == 0 );
}

int main () {
        
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");
    
    int n, i, year, lyear, mnth, d;
    day actual = MON;
    int out[7] = { 0 };
    
    fscanf( fin, "%d", &n );
    lyear = 1900 + n;
    
    for( year = 1900; year < lyear; year++ ){
         
         for( mnth = 1; mnth <= 12; mnth++ ){
              
              switch( mnth ){
                      case 2:
                             if( leap( year ) ) i = 29;
                             else i = 28;
                             break;
                      case 4:
                      case 6:
                      case 9:
                      case 11:
                            i = 30;
                            break;
                      case 1:
                      case 3:
                      case 5:
                      case 7:
                      case 8:
                      case 10:
                      case 12:
                            i = 31;
                            break;
              }
              
              for( d = 1; d <= i; d++ ){
                   
                   if( actual == 7 ) actual = SAT;
                   if( d == 13 ) out[actual]++;
                   actual++;
              }
         }
         
    }
    
    fprintf( fout, "%d %d %d %d %d %d %d\n", out[0], out[1], out[2], out[3], out[4], out[5], out[6] );

    return 0;
}

