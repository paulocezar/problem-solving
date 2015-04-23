#include <iostream>
#include <map>
#include <list>
#include <string>
#include <queue>

using namespace std;

static map< string, int > vertices;
static list<int> folhas;
static list<int> arestas[1001];
static char cor[1001];
static int  dist[1001];
static queue< int > fila;
static pair< int, int > maior ( 0, -1 );
static int grau = -1;

void bfs( int origem ){

	for(int i = 1; i <= vertices.size(); i++ ){
		cor[i] = 1;
		dist[i] = 0;
	}
	fila.push( origem );

	dist[origem] = 0;
	cor[origem] = 0;

	while( !fila.empty() ){
		int u = fila.front(); fila.pop();

		if( dist[u] > grau ){
			maior.first = origem;
			maior.second = u;
			grau =dist[u];
		}

		for( list< int >::iterator it = arestas[u].begin(); it != arestas[u].end(); it++ ){
			if( cor[*it] ){
				cor[*it] = 0;
				dist[*it] = dist[u] + 1;
				fila.push( *it );
			}
		}
	}
}

int main(){

  int N;
  int vertice = 0;
  string filho, pai;
  string nomes[1001];
  scanf("%d", &N );
 
  for( int i = 0; i < N; i++ ){
	cin >> pai >> filho;
		
	vertices[pai]++;
	vertices[filho]++;
	
	if( vertices[pai] == 1 ){
		vertices[pai] = ++vertice;
		nomes[vertice] = pai;
	}else
		vertices[pai]--;
	if( vertices[filho] == 1 ){
		vertices[filho] = ++vertice;
		nomes[vertice] = filho;
	}else
		vertices[filho]--;

	arestas[vertices[pai]].push_back(vertices[filho]);
	arestas[vertices[filho]].push_back(vertices[pai]);

	folhas.push_back( vertices[filho] );
	folhas.remove( vertices[pai] );

 }

list<int>::iterator listit = folhas.begin();
for( int i = 1; i <= folhas.size(); listit++ ){
	bfs( *listit );
	i++;
}

	if( nomes[maior.first].compare(nomes[maior.second]) < 0  )
		cout << nomes[maior.first] << " " << nomes[maior.second] << " " << grau << endl;
	else
		cout << nomes[maior.second] << " " << nomes[maior.first] << " " << grau << endl;

  return 0;
}

