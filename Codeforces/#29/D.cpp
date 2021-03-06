#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 303

vector<int> gr[MAXN];
int parent[MAXN], depth[MAXN];

void explore( int u ){
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ )
		if( gr[u][i] != parent[u] ){
			depth[ gr[u][i] ] = depth[u]+1;
			parent[ gr[u][i] ] = u;
			explore( gr[u][i] );
		}
}

vector< int > ans;
int aux[MAXN];

void lca( int from, int to ){
	int pos = 0;
	
	while( from != to ){
		if( depth[from] > depth[to] ){
			ans.push_back( from );
			from = parent[from];
		} else {
			aux[pos++] = to;
			to = parent[to];
		}
	}
	ans.push_back( from );
	while( pos > 1 ) ans.push_back( aux[--pos] );
}

int main(){
	ios::sync_with_stdio(false);
	
	int n, u, v;
	cin >> n;
	
	for( int i = 0; i < n-1; i++ ){
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	
	parent[1] = -1;
	depth[1] = 0;
	explore(1);
	
	u = 1;
	ans.clear();
	while( cin >> v ){ lca( u, v ); u = v; }
	lca( u, 1 );
	
	if( int(ans.size()) > 2*n-1 ) cout << "-1\n";
	else {
		for( size_t i = 0, sz = ans.size(); i < sz; i++ )
			cout << ans[i] << " ";
		cout << "\n";
	}
	
	return 0;
}
