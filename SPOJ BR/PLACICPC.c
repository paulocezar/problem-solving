#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXT 110
#define INF 0x3FFFFFFF

typedef struct {
	int solved, ttime, wrong, p;
} team;

team teams[MAXT];

int comp( const void *a, const void *b ){
    int r = ((team*)b)->solved - ((team*)a)->solved;
    if( r ) return r;
    return ((team*)a)->p - ((team*)b)->p;
}

int main(){
    
    int t, p;
    int i, j, a, b;
    int min, max, er, tm, w;
    char line[100];
    char *ptr, *optr;
    
	while( 1 ){
		
        scanf("%d %d", &t, &p ); getchar();
        if( t+p == 0 ) return 0;
        
        for( i = 0; i < t; i++ ){
			teams[i].solved = 0;
			teams[i].ttime = 0;
			teams[i].wrong = 0;
			
			scanf("%[^\n]", line ); getchar();
			ptr = optr = line;
			
			for( j = 0; j < p; j++ ){
                 ptr = strchr( optr, '/' ) + 1;
      
				if( *ptr != '-' ){
                    sscanf( optr, "%d/%d", &a, &b );
                    teams[i].ttime += b;
					teams[i].solved++;
					teams[i].wrong += ( a - 1 );
				}
				optr = strchr( ptr, ' ' ) +1;
							
			}
			teams[i].p = teams[i].ttime + 20*teams[i].wrong;
		}
		
		qsort( teams, t, sizeof( team ), comp );
        min = 1, max = INF;
				
        for( i = 1; i < t && teams[i].solved; i++ ){
			
            if( teams[i].solved == teams[i-1].solved ){
                
				if( teams[i].p == teams[i-1].p ){
					max = min = 20;
					break;
				} else {
					
                    tm = teams[i-1].ttime - teams[i].ttime;
					er = teams[i].wrong - teams[i-1].wrong;
					
					if( er < 0 ){
                        
                        w = ( tm / er );
                        if( tm % er == 0 ) w--;
                        
						if( w > 0 && ( w < max ) ) max = w;
					
                    }
                    else if( er > 0 ){
						
                        w = ( tm / er ) + 1;
						if( w > min ) min = w;
					
                    }
				}
			}
		}
		
        printf("%d ", min );
        if( max == INF ) printf("*\n");
		else printf("%d\n", max );
		
	}
	
	return 0;
	
}
