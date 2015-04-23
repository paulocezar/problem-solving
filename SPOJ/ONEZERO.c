#include <stdio.h>
#include <stdlib.h>

#define MAXN 21000

char used[MAXN];
int queue[MAXN];
char dig[MAXN];
int par[MAXN];

void printSol( int x ){
     if( x == -1 ) return;
     printSol( par[x] );
     putchar( dig[x] );
}

int main(){
    
    int t, n, u, v, m, beg, end;
    
    scanf("%d", &t );
    while( t-- ){
    
           scanf("%d", &n );
           memset( used, 0, sizeof( char ) * n );
           
           u = 1%n;
           par[u] = -1;
           dig[u] = '1';
           beg = end = 0;
           queue[end++] = u;
           used[u] = 1;
           
           while( beg != end ){
               
               u = queue[beg++];
               if( u == 0 ){
                   printSol( u );
                   break;
               }
               
               v = 10*u % n;
               if( !used[v] ){
                   par[v] = u;
                   dig[v] = '0';
                   used[v] = 1;
                   queue[end++] = v;
               }
               v = (10*u +1 ) % n;
               if( !used[v] ){
                   par[v] = u;
                   dig[v] = '1';
                   used[v] = 1;
                   queue[end++] = v;
               }
               
           }
           puts("");
    
    }
    
    return 0;
}
