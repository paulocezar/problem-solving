#include <stdio.h>
#include <stdlib.h>

#define NJOBS 1001

typedef struct{
        int ndays;
        int fee;
        int id;
} task;

int comp( const void* a, const void* b ){

    double ra = (double)((task*)a)->fee / (double)((task*)a)->ndays;
    double rb = (double)((task*)b)->fee / (double)((task*)b)->ndays;

    if( ra > rb )
        return -1;
    if( rb > ra )
        return 1;
    
    return ((task*)a)->id - ((task*)b)->id;     
}

int main(){
    
    int cases, n, i;
    task jobs[NJOBS];
    
    scanf("%d", &cases );
    while( cases-- ){
           
           scanf("%d", &n );
           for( i = 0; i < n; i++ ){
                scanf("%d %d", &jobs[i].ndays, &jobs[i].fee );
                jobs[i].id = i+1;
           }
           
           qsort( jobs, n, sizeof( task ), comp );
           
           printf("%d", jobs[0].id );
           for( i = 1; i < n; i++ )
                printf(" %d", jobs[i].id );
           printf("\n");        
           
           if( cases ) printf("\n");
    }          
    
    return 0;
}
