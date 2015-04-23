#include <queue> 
#include <vector> 
#include <string> 
#include <cstdio>
#include <cstdlib> 
#include <cstring> 
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 10001
vector< int > gr[MAXN];

char seen[MAXN];
int depth[MAXN];
int diameter;

void dfs( int u, int prof = 0 ){
	if( prof > diameter ) diameter = prof;
	seen[u] = true;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		int v = gr[u][i];
		if( !seen[v] ) dfs( v, prof+1 );
	}
}


int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio( false );

	int t, n;
	cin >> t;
	while( t-- ){
		cin >> n;
		for( int i = 1; i <= n; i++ ){
			depth[i] = 2*MAXN;
			seen[i] = false;
			int sz; cin >> sz;
			gr[i].resize(sz);
			for( int j = 0; j < sz; j++ ) cin >> gr[i][j]; 
		}
		
		queue< int > q;
		q.push( 1 ); depth[1] = 0;
		
		int dpst = -1;
		while( !q.empty() ){
			int u = q.front(); q.pop();
			dpst = u;
			for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
				int v = gr[u][i];
				if( depth[u]+1 < depth[v] ){
					depth[v] = depth[u]+1;
					q.push( v );
				}
			}
		}
		
		diameter = 0;
		dfs( dpst );
		cout << 2*(n-1)-diameter << "\n";
		
	}
	
	return 0;
}




