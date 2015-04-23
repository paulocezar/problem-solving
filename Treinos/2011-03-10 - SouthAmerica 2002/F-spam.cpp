#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>

using namespace std;

#define MAXN 21
#define MAXM 101

list< int > graph[MAXN];		
bool visited[MAXN];
string ans[MAXN][MAXM];

int main(){
	
	ios::sync_with_stdio( false );
	int n;
	
	cin >> n;
	while( n ){
		
		
		for( int i = 0; i < n; i++ ){
			graph[i].clear();
			int v;
			cin >> v;
			while( v ){
				graph[i].push_back( v-1 );
				cin >> v;
			}
		}
		
		int p;
		cin >> p;
		int msg = 0;
		while( p ){
			
			int t1, t2;
			string n1, n2, n3;
			cin >> t1 >> t2 >> n1 >> n2 >> n3;
			
			for( int i = 0; i < n; i++ ) visited[i] = false;
			queue< int > q;
			p--;
			q.push( p );
			visited[p] = true;

			while( !q.empty() ){
				int u = q.front(); q.pop();
				for( list< int >::iterator v = graph[u].begin(); v != graph[u].end(); v++ )if( !visited[*v] ){
					visited[*v] = true;
					q.push( *v );
				}
			}
				
			for( int i = 0; i < n; i++ ) if( visited[i] ){
				if( int(graph[i].size()) >= t2 ) ans[i][msg] = n3;
				else if( int(graph[i].size()) >= t1 ) ans[i][msg] = n2;
				else ans[i][msg] = n1;
			} else ans[i][msg] = n1;
			
			msg++;
			cin >> p;
			
		}
		
		for( int i = 0; i < n; i++ ){
			string name;
			cin >> name;
			cout << name << ":";
			for( int j = 0; j < msg; j++ ) cout << " " << ans[i][j];
			cout << "\n";
		}
		
		cin >> n;
	}
	

	return 0;
}


