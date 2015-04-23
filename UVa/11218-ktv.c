#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 90

typedef struct{
        int a, b, c, s;
} combscore;

int main(){
    
    int ncase = 1, n, i, j, k;
    int cur, best;
    char used[10];
    combscore comb[MAXN];
    
    memset( used, 0, sizeof( used ) );
    while( 1 ){
    
           scanf("%d", &n );
           if( n == 0 ) return 0;
           
           for( i = 0; i < n; i++ )
                scanf("%d %d %d %d", &comb[i].a, &comb[i].b, &comb[i].c, &comb[i].s );
           
           best = -1;
           for( i = 0; i < n; i++ ){
                used[comb[i].a] = used[comb[i].b] = used[comb[i].c] = 1;
                for( j = i+1; j < n; j++ ){
                     if( used[comb[j].a] || used[comb[j].b] || used[comb[j].c] ) continue;
                     used[comb[j].a] = used[comb[j].b] = used[comb[j].c]= 1;
                     for( k = j+1; k < n; k++ ){
                          if( used[comb[k].a] || used[comb[k].b] || used[comb[k].c] ) continue;
                          cur = comb[i].s + comb[j].s + comb[k].s;
                          
                          if( cur > best ) best = cur;
                          
                     }
                     used[comb[j].a] = used[comb[j].b] = used[comb[j].c]= 0;
                }
                used[comb[i].a] = used[comb[i].b] = used[comb[i].c] = 0;
           }
           
           printf("Case %d: %d\n", ncase++, best );
           
           
    }

    return 0;
}

