/*
 *  Problema: 
 *  Tecnica Utilizada: 
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define MAXN 101
#define INF 0x3F3F3F3F

int gmap[MAXN][MAXN], ans;
int n, M , Father[MAXN];
bool vis[MAXN], Circle[MAXN];

void dfs (int x) {
	vis[x] = true;
    for( int i = 1; i <= n; ++i )
        if( !vis[i] && gmap[x][i] < INF )
			dfs(i);
}

bool Connect () {
	memset( vis, 0, sizeof( vis ) );
	dfs(1);
    for( int i = 1; i <= n; ++i )
        if( !vis[i] ) return false;
    return true;
}

int exist_circle (){
	Father[1] = 1; // root of the parent node is the root
    for( int i = 2; i <= n; ++i ) // for all entry points to find the minimum degree of edge
    {
        if( !Circle[i] ) // point does not shrink
        {
			Father[i] = i; 
			gmap[i][i] = INF; // elimination from the ring
            for( int j = 1; j <= n; ++j ) // find the minimum-degree edge
            {
                if( !Circle[j] && gmap[j][i] < gmap[Father[i]][i] ) 
						Father[i] = j;
			}
		}
	}
    for( int i = 2; i <= n; ++i ) // determine whether there was to ring
    {
        if( Circle[i] ) continue;
		memset( vis, 0, sizeof(vis) );
        int j = i;
        while( !vis[j] ){
			vis[j] = true;
			j = Father[j];
		}
        if( j == 1 ) continue; // Finally, the parent node root, not the Central
        else return j; // otherwise loop vertex
    }
    return -1; // This map has the smallest tree diagram
}

// contractile ring for a little t, and update the edge Right, here is more complex theory, to achieve difficult
void Update( int t ) { 
	
    /* New graph with minimum weight tree is an old figure that the ring contraction of the right
       and is the original rights of the smallest tree. */
    ans += gmap[ Father[t] ][t];
    for( int i = Father[t]; i != t; i = Father [i] ) // put the value inside the ring all together
    { 
		ans += gmap[ Father[i] ][i];
		Circle[i] = true;
	}

    for( int i = 1; i <= n; ++i ) // update all the relevant points with the point side of t right
    {
        if( !Circle[i] && gmap[i][t] != INF ) 
			gmap[i][t] -= gmap[ Father[t] ][t];
	}
    
    for( int i = Father[t]; i != t; i = Father[i] ) // update all the points with the ring right on the edge
    {
        for( int j = 1; j <= n; ++j ){
            if( Circle[j] ) continue;

            if( gmap[j][i] != INF ) gmap[j][t] = min( gmap[j][t], gmap[j][i] - gmap [Father[i]][i] );
			// updated into the right side
            /* If the new figure the right e w'(e) is the original weight of e w(e) less in [u] the right,
			  then we delete in [u], and will e back to original state when the weight of this tree is still
			  the right of the new graph tree plus the right ring, and this weight is the weight of the smallest tree */
            gmap[t][j] = min( gmap[i][j], gmap[t][j] ); // update the edge weight
        }
	}
}

void solve(){ 
	
	memset( Circle, 0, sizeof( Circle ) );
    
	int t;
	while( (t = exist_circle() ) != -1 )
		Update(t); // existing ring, contractile ring until the ring does not exist so far

    for( t = 2; t <= n; ++t )
        if( !Circle[t] ) ans += gmap[Father[t]][t]; // put all together not a right to the edge ring
}

struct Edge {
    int u, v, Flow, cost;
    void Get () { scanf("%d %d %d %d", &u, &v, &Flow, &cost ); v++, u++; }
} EDGE[11000];

int max_cost;

bool Build( int MID ){ 
	
    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ ) gmap[i][j] = INF;

    for( int i = 0; i < M; i++ ){
        if( EDGE[i].Flow >= MID ){
            int u = EDGE[i].u, v = EDGE[i].v, cost = EDGE[i].cost;
            if( gmap[u][v] > cost ) gmap[u][v] = cost;
		}
	}
    if( !Connect() ) return false;
	ans = 0; solve();
	return ans <= max_cost;
}

void bs(){
	
    int left = 1, right = 1048578;
    while( left <= right ){
        int MID = (left + right) / 2;
        if( Build( MID ) ) left = MID + 1;
        else right = MID - 1;
	}
	if( right ) printf( "%d kbps\n", right );
    else puts("streaming not possible.");
}

int main () {
	
	int i;
    int T;
	scanf("%d", &T );
    while( T-- ){
		scanf("%d %d %d", &n, &M, &max_cost );
        for(i = 0; i < M; ++i ) EDGE[i].Get(); 
		bs();
	}
    return 0;
}
