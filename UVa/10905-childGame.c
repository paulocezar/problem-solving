#include <stdio.h>
#include <stdlib.h>

#define MAXS 100
#define MAXN 52

typedef struct{
        char wrd[MAXS];
} word;

int comp( const void *a, const void *b ){

    int i = 0, r, f = 0;
    char *pa = ((word*)a)->wrd;
    char *pb = ((word*)b)->wrd;
    
    while( *pa ){
           r = *pb - *pa;
           if( r ) return r;
           pa++, pb++;
           if( !(*pb) ){ pb = ((word*)a)->wrd; f = 1; }
    }
    
    pa = ((word*)b)->wrd;
    while( *pa ){
           r = *pb - *pa;
           if( r ) return r;
           pa++, pb++;
           if( !(*pb) ) pb = ((word*)a)->wrd;
    }
    
    if( f ) return 1;
            
    return 0;
}

int main(){

    word numbers[MAXN];
    int n, i;

    while( 1 ){
           scanf("%d", &n ); getchar();
           if( n == 0 ) return 0;
           
           for( i = 0; i < n; i++ )
                { scanf("%s", &numbers[i].wrd ); getchar(); }
                
           qsort( numbers, n, sizeof( word ), comp );
           
           for( i = 0; i < n; i++ )
                printf("%s", numbers[i].wrd );
           printf("\n");
           
    }

    return 0;    
}
