#include <iostream>
#include <stdlib.h>
#include <map>
#include <set>
#include <queue>
#include <string>
#define INF 0x3f3f3f3f
#define BRANCO 1
#define PRETO  2

using namespace std;

int main(){

	int nscenarios;
	int scenario;
	int P, N;
	int i, j, k, u, ptr, aut, indice;
	string linha, autor;
	set<int>::iterator v;
    set<int> grafo[5100];
    char color[5100];
    int numErdos[5100];
	queue<int> q;
    queue< string > nameList;
    	    
    scanf("%d", &nscenarios );
	for( scenario = 1; scenario <= nscenarios ; scenario++ ){
		
        scanf("%d %d", &P, &N ); getchar();

		map< string, int > indices;
 	    
   		indices["Erdos, P."] = 0;
        indice = 1;
        grafo[0].clear();
         
		for( i = 0; i < P; i++ ){
			getline( cin, linha );
			if( linha.size() ){
			    vector< string > autores;
			    ptr = 0, aut = 0;
			    bool first = true;
			    autor = "";
			    while( linha[ptr] && linha[ptr] != ':' ){
                
                       if( linha[ptr] != ' ' && linha[ptr] != '\t' ){
                           if( linha[ptr] == ',' ){
                               if( first ){
                                   first = false;
                                   autor += ", ";
                               }
                               else{
                                    autores.push_back( autor ); autor = "";
                                    aut++;  first = true;
                               }
                           }
                           else
                               autor += linha[ptr];
                       }
                       ptr++;   
                }
			    if( linha[ptr] == ':' && autor[autor.size()-1] != ' ' ){
                    autores.push_back( autor );
                    aut++;
                }

			    for( j = 0; j < aut; j++ ){

				     if( indices.find( autores[j] ) == indices.end() ){
					     indices[autores[j]] = indice;
                         grafo[indice++].clear();                      
	                 }
                }

			    for( j = 0; j < aut; j++ ){
				     for( k = j+1; k < aut; k++ ){
					      grafo[ indices[autores[j]] ].insert( indices[autores[k]] );
					      grafo[ indices[autores[k]] ].insert( indices[autores[j]] );
		             }
		        }
            } else i--;

		}
		
		for( i = 0; i < N; i++ ){
			getline( cin, linha );
			autor = ""; ptr = 0;
			while( linha[ptr] ){
			       if( linha[ptr] != ' ' && linha[ptr] != '\t' ){
			           if( linha[ptr] == ',' ) autor += ", ";
			           else autor += linha[ptr];
                   }   
                   ptr++;
            }        
			if( autor[0] ) nameList.push( autor );
			else i--;
        }

		for( u = 0; u < indice; u++ ){
			color[u] = BRANCO;
			numErdos[u] = INF;
		}

		color[0] = PRETO;
		numErdos[0] = 0;
		q.push( 0 );

		while( !q.empty() ){
			u = q.front(); q.pop();

			for( v = grafo[u].begin(); v != grafo[u].end(); v++ ){
				if( color[*v] == BRANCO ){
					color[*v] = PRETO;
					numErdos[*v] = numErdos[u] + 1;
					q.push( *v );
				}
			}

		}

		printf("Scenario %d\n", scenario );
		for( i = 0; i < N; i++ ){
            autor = nameList.front(); nameList.pop();
            cout << autor << " ";
            if( indices.find( autor ) == indices.end() || numErdos[indices[autor]] == INF )
					printf("infinity\n");
		    else
					printf("%d\n", numErdos[indices[autor]] );
		}

	}
	return 0;
}

