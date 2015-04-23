#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <list>

using namespace std;

int main(){

	map< int, list<int> > graph ;
	map< int, bool > visit;

	int n, u, v;
	map< int, list< int > >::iterator w;
	list< int >::iterator it;

	cin >> n;
	while( n-- ){
		cin >> u >> v;
		graph[u].push_back( v );
		graph[v].push_back( u );
		visit[u] = visit[v] = false;
	}

	w = graph.begin();
	while( ((*w).second).size() == 2 ) w++;
	v = (*w).first;

	cout << v;
	do{
		visit[v] = true;
		it = graph[v].begin();
		while( it != graph[v].end() ){
			if( !visit[*it] ){ v = *it; break; }
			it++;
		}
		cout << " " << v;
	} while( graph[v].size() != 1 );
	cout << endl;

	return 0;
}

