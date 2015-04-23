#include <iostream>
#include <vector>

using namespace std;

#define MAXN 111
#define ok(ni,nj) ((ni>=0)&&(nj>=0)&&(ni<R)&&(nj<C))

vector< int > gr[MAXN];

int ds[][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int low[MAXN], lbl[MAXN], parent[MAXN];
int dfsnum;
int bridges;

void dfs( int u ){
	lbl[u] = low[u] = dfsnum++;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		int v = gr[u][i];
		if( lbl[v] == -1 ){
			parent[v] = u;
			dfs( v );
			if( low[v] > lbl[u] )
				bridges++;
			low[u] = min( low[u], low[v] );
		} else if( v != parent[u] ) low[u] = min( low[u], lbl[v] );
	}
}


int main(){
	ios::sync_with_stdio(false);
	int R, C;
	cin >> R >> C;
	string grid[R];
	int id[R][C];
	int cid = 0;
	for( int i = 0; i < R; i++ ){
		cin >> grid[i];
		for( int j = 0; j < C; j++ ){
			if( grid[i][j] == '.' )
				id[i][j] = cid++;
			else id[i][j] = -1;
		}
	}

	for( int i = 0; i < R; i++ )
		for( int j = 0; j < C; j++ )
		if( id[i][j] != -1 ){
			gr[ id[i][j] ].clear();
			lbl[ id[i][j] ] = low[ id[i][j] ] = parent[ id[i][j] ] = -1;
			for( int dir = 0; dir < 4; dir++ ){
				int ni = i+ds[dir][0];
				int nj = j+ds[dir][1];
				if( ok(ni,nj) && id[ni][nj] != -1 ){
					gr[ id[i][j] ].push_back( id[ni][nj] );
				}
			}
		}
	
	dfsnum = 0;
	bridges = 0;
	bool first = true;
	for( int i = 0; i < cid; i++ ) if( lbl[i] == -1 ){
		if( !first ){ bridges++; break; }
		first = false;
		dfs( i );
	}
	
	if( bridges ) cout << "1\n";
	else cout << "0\n";
		

	return 0;
}

