#include <stdio.h>
#include <stdlib.h>

#define MAXA 101
#define STHOUR 10
#define STMIN 0
#define ENDHOUR 18
#define ENDMIN 0

typedef struct{
        int ini;
        int end;
} appointment;

int comp( const void* a, const void* b ){
    return ((appointment*)a)->ini - ((appointment*)b)->ini;
}

int main(){

    int n;
    appointment list[MAXA];
    int i, sth, stm, endh, endm;
    int actual, best, beststrt, last;
    int day = 1;
    char line[300];
    
    while( scanf("%d", &n ) != EOF ){
           getchar();
           
           for( i = 0; i < n; i++ ){
                gets( line );
                sscanf( line, "%d%*c%d %d%*c%d ", &sth, &stm, &endh, &endm );
                list[i].ini = sth*60 + stm;
                list[i].end = endh*60 + endm;
           }
           
           qsort( list, n, sizeof( appointment ), comp );
           
           last = STHOUR*60 + STMIN; best = 0;
           for( i = 0; i < n; i++ ){
                actual = list[i].ini - last;
                if( actual > best ){
                    best = actual;
                    beststrt = last;
                }
                last = list[i].end;
           }
           actual = (ENDHOUR*60 + ENDMIN) - last ; 
           if( actual > best ){
               best = actual;
               beststrt = last;
           }
           
           printf("Day #%d: the longest nap starts at %d:%02d and will last for ", day++, beststrt/60, beststrt%60 );
           if( best >= 60 )
               printf("%d hours and %d minutes.\n", best/60, best%60 );
           else
               printf("%d minutes.\n", best );           
           
    }

    return 0;    
}
