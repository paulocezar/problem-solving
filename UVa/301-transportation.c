#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXC 10
#define MAXO 25

int orders[MAXO][3];
int train[MAXC];
int N, B, n_orders;
int best;
int curr;

void solve( int order ){
    
    int i;
    char acc;
    
    if( order == n_orders ){
        if( curr > best ) best = curr;
        return;
    }
    
    acc = 1;
    for( i = orders[order][0]; i < orders[order][1]; i++ )
         if( train[i] + orders[order][2] > N ){ acc = 0; break; }
    
    if( acc ){

        for( i = orders[order][0]; i < orders[order][1]; i++ )
             train[i] += orders[order][2];
        
        curr += ( (orders[order][1]-orders[order][0])*orders[order][2] );
        solve( order+1 );
        curr -= ( (orders[order][1]-orders[order][0])*orders[order][2] );
        
        for( i = orders[order][0]; i < orders[order][1]; i++ )
             train[i] -= orders[order][2];
                        
    }
    solve( order+1 );
    
}

int main(){
    
    int i;
    
    while( 1 ){
    
           scanf("%d %d %d", &N, &B, &n_orders );
           if( (N+B+n_orders) == 0 ) return 0;
     
           for( i = 0; i <= B; i++ )
                train[i] = 0;
                
           for( i = 0; i < n_orders; i++ )
                scanf("%d %d %d", &orders[i][0], &orders[i][1], &orders[i][2] );
           
           curr = best = 0;
           solve( 0 );
           printf("%d\n", best );    
           
    }
    
    return 0;    
}
