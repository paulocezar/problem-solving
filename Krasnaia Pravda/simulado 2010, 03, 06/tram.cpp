#include <iostream>
#include <queue>

#define MAXN 102
#define INF 0x3F3F3F3F

using namespace std;

int graph[MAXN][MAXN];
int out[MAXN];
int d[MAXN];
int point[MAXN];
char used[MAXN];

int n, a, b, min, reached;

void solve(){
     
     int u, v, nd, cst, w;
     priority_queue< pair< int, int >, vector< pair< int, int > >, greater< pair< int, int > > > Q;
     Q.push( make_pair( 0, a ) );
     
     while( !Q.empty() ){
     
            nd = Q.top().first;
            u = Q.top().second; Q.pop();
            
            if( nd >= d[u] && used[u] ) continue;
            used[u] = 1;
            
            for( w = 0; w < out[u]; w++ ){
                 v = graph[u][w];
                 cst = w ? 1 : 0;
                 if( nd + cst < d[v] ){
                     Q.push( make_pair( nd+cst, v ) );
                     d[v] = nd+cst;
                 }
            }
            
     }

          
}

int main(){
    
    int i, k, j, v;
    scanf("%d %d %d", &n, &a, &b );
    
    for( i = 1; i <= n; i++ )
         out[i] = used[i] = 0, d[i] = INF;
         
    for( i = 1; i <= n; i++ ){
         scanf("%d", &k );
         for( j = 0; j < k; j++ ){
              scanf("%d", &v );
              graph[i][out[i]++] = v; 
         }
    }

    if( graph[a][b] && point[a] == b ) puts("0");
    else{
         
         solve(); 
             
         if( d[b] != INF ) printf("%d\n", d[b] );
         else puts("-1");
    }

    return 0;
}
