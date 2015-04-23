#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main(){
	
	int n, r1, r2, i, p;

	cin >> n >> r1 >> r2;

	list< int > graph[n+1];
	int parent[n+1];
	bool visited[n+1];

	for( i = 1; i <= n; i++ ){
		visited[i] = false;
		if( i == r1 ) continue;
		cin >> p;
		graph[i].push_back( p );
		graph[p].push_back( i );
	}

	visited[r2] = true;
	queue< int > q;
	int u;
	list< int >::iterator v;
	q.push( r2 );

	while( !q.empty() ){
		u = q.front(); q.pop();
		for( v = graph[u].begin(); v != graph[u].end(); v++ ){
			if( !visited[*v] ){
				parent[*v] = u;
				q.push( *v );
				visited[*v] = true;
			}
		}
	}

	for( i = 1; i <= n; i++ ){
		if( i == r2 ) continue;
		printf("%d ", parent[i] );
	}
	
	return 0;
}
