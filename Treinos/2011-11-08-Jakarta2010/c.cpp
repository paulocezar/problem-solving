#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 2500
vector< int > gr[MAXN];

int q[ MAXN ], front, back;
char seen[ MAXN ];

int main(){
	ios::sync_with_stdio(false);
	
	int t, N, M;
	int u, v;
	
	cin >> t;
	while( t-- ){
		
		cin >> N >> M;
		for( int i = 0; i < N; i++ ) gr[i].clear();
		
		for( int i = 0; i < M; i++ ){
			cin >> u >> v;
			gr[u-1].push_back( v-1 );
		}
		
		int ans = 0;
		for( int i = 0; i < N; i++ ){
			for( int j = 0; j < N; j++ ) seen[j] = 0;
			seen[i] = 1;
			front = back = 0;
			q[back++] = i;
			ans--;
			while( front < back ){
				u = q[front++];
				ans++;
				for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
					v = gr[u][i];
					if( !seen[v] ){
						seen[v] = 1;
						q[back++] = v;
					}
				}
			}
		}
		cout << ans << "\n";
		
	}
	
	return 0;
}

