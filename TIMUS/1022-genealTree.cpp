#include <iostream>
#include <list>

using namespace std;

static list<int> graph[101];
static char cor[101];
static list<int> output;

void dfsVisit( int u ){

	cor[u] = 0;

	for( list< int >::iterator it = graph[u].begin(); it != graph[u].end(); it++ )
		if( cor[*it] )
			dfsVisit( *it );

	output.push_front( u );

}

void topologicalSort( int n ){

	for( int u = 1; u <= n; u++ )
		cor[u] = 1;

	for( int u = 1; u <=n; u++ )
		if( cor[u] )
		dfsVisit( u );
}

int main(){

  int n;

  scanf("%d", &n );

  for( int i = 1; i <= n; i++ )
	while( 1 ){
	 int x;
	 scanf("%d", &x );
	 if( x == 0 ) break;
	 graph[i].push_back( x );
	}

  topologicalSort( n );

  list<int>::iterator it = output.begin();
  cout << *it;
  it++;
  while(  it != output.end() ){
	cout << " " <<  *it ;
	it++;
  }
  cout << endl;

  return 0;
}

