#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x3F3F3F3F

int graph[110][110];
char used[110];
int n;

int dfs( int u ){
	
	int v;
	used[u] = 1;
	 
	for( v = 1; v <= n; v++ )
		if( graph[u][v] && !used[v] )
			return  ((graph[u][v]>0)?dfs(v):(dfs(v)-graph[u][v]));
		
	return  ((graph[u][1]>0)?0:(-graph[u][1]));
}

int main(){
    
    int u, v, i, c;
    int best;
    
    scanf("%d", &n );
    
    for( u = 1; u <= n; u++ )
         for( v = 1; v <= n; v++ )
              graph[u][v] = 0;
    
	int total = 0;
    for( i = 0; i < n; i++ ){
         scanf("%d %d %d", &u, &v, &c );
		 graph[u][v] = 1;
		 graph[v][u] = -c;
		 total += c;
    }
    
	best = dfs(1);
	if( total-best < best ) best = total-best;
    
	printf("%d\n", best );
    return 0;
    
}
