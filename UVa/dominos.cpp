#include <iostream>
#include <set>

#define MAXV 100005

using namespace std;

set< int > graph[MAXV];

int list[MAXV];
char used[MAXV];

int n, ans, end;

void topologicSort( int u ){
     
     set< int >::iterator v;
     used[u] = 1;
     
     for( v = graph[u].begin(); v != graph[u].end(); v++ )
          if( !used[*v] ) topologicSort( *v );
     
     list[end--] = u; 
}


void dfs( int u ){
     
     set< int >::iterator v;
     used[u] = 0;

     for( v = graph[u].begin(); v != graph[u].end(); v++ )
          if( used[*v] ) dfs( *v );

}

int main(){

    int cases, m, u, v, i, x;
    
    scanf("%d", &cases );
    while( cases-- ){
     
           scanf("%d %d", &n, &m );
           for( i = 1; i <= n; i++ ){
                used[i] = 0;
                graph[i].clear();
           }
           
           for( i = 0; i < m; i++ ){
                scanf("%d %d", &u, &v );
                graph[u].insert( v );
           }
           
           ans = 0;
           end = n-1;
           for( u = 1; u <= n; u++ )
                if( !used[u] ) topologicSort( u );
          
           for( u = 0; u < n; u++ ){
                if( used[list[u]] ){
                    ans++;
                    dfs( list[u] );
                }        
           }
          
          printf("%d\n", ans );
    }    
    
    return 0;
}
