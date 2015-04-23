#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int from, to, cap;

#define MAXN 1001
#define MAXC 101
#define INF 0x3F3F3F3F

vector< pair<int,int> > grafo[MAXN];
int dp[MAXN][MAXC];
int p[MAXN]; 

void solve( int at, int comb ){
	
	priority_queue< pair<int, pair<int, int > > > q;
	q.push(make_pair(0, make_pair(at, comb)));
	
	while(!q.empty()){
		int custo = -q.top().first;
		at = q.top().second.first;
		comb = q.top().second.second;
		q.pop();
		
		if( custo > dp[at][comb] ) continue;
		if( at == to ) break;
		
		if( comb < cap && dp[at][comb+1] > dp[at][comb]+p[at] ){
				dp[at][comb+1] = dp[at][comb]+p[at];
				q.push(make_pair( -dp[at][comb+1], make_pair(at, comb+1)));
		}
		
		for( int i = 0; i < (int)grafo[at].size(); i++ ){
			int peso = grafo[at][i].second;
			int v = grafo[at][i].first;
			if( comb >= peso && dp[v][comb-peso] > dp[at][comb] ){
				dp[v][comb-peso] = dp[at][comb];
				q.push(make_pair( -dp[v][comb-peso], make_pair(v, comb-peso)));
			}
		}
	}
}

int main(){

	ios::sync_with_stdio( false );
	
	int n, m;
	cin >> n >> m;

	for( int i = 0; i < n; i++ ){
		cin >> p[i];
		grafo[i].clear();
	}
	
	for( int i = 0; i < m; i++ ){
		int u, v, c;
		cin >> u >> v >> c;
		grafo[u].push_back( make_pair( v, c ) );	
		grafo[v].push_back( make_pair( u, c ) );
	}
	
	int q;
	cin >> q;
	while( q-- ){
		
		cin >> cap >> from >> to;
		for( int i = 0; i < n; i++ ) for( int j = 0; j <= cap; j++ ) dp[i][j] = INF;
		dp[from][0] = 0;
		solve( from, 0 );
		
		int ans = INF;
		for( int i = 0; i <= cap; i++ ) ans = min( ans, dp[to][i] );
		if( ans == INF ) cout << "impossible\n";
		else cout << ans << "\n";
		
	}
	return 0;
}

