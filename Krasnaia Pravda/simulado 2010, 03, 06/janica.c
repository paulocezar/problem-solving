#include <stdio.h>
#include <stdlib.h>

typedef struct {
        int id;
        int time;        
}skier;

int comp( const void* a, const void* b ){
    return ((skier*)a)->time -((skier*)b)->time;
}

int main(){

    skier contestant[101];
    int n, m, i, a, b;
    float first, dif;
    char neg;
    
    scanf("%d %d", &n, &m );
     
    scanf("%d.%d", &a, &b ); getchar();
    
    first = 100*a + b;
    contestant[0].id = 1, contestant[0].time = first;
    
    for( i = 1; i < n; i++ ){
         scanf("%c%d.%d", &neg, &a, &b ); getchar();
         dif = 100*a + b;
         if( neg == '-' ) dif = -dif;
         contestant[i].id = i+1, contestant[i].time = first + dif;
         if( contestant[i].time < first ) first = contestant[i].time;
    }
    
    qsort( contestant, n, sizeof( skier ), comp );

    scanf("%d.%d", &a, &b ); getchar();
    first = 100*a + b;    
    contestant[m-1].time = first;
    for( i = m-2; i >= 0; i-- ){
         scanf("%c%d.%d", &neg, &a, &b ); getchar();
         dif = 100*a + b;
         if( neg == '-' ) dif = -dif;
         contestant[i].time = first + dif;
         if( contestant[i].time < first ) first = contestant[i].time;
    }    
    
    qsort( contestant, m, sizeof( skier ), comp );
     
    for( i = 0; i < 3; i++ )
         printf("%d\n", contestant[i].id );

    return 0;    
}
