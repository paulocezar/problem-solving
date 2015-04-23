/*
 *  Problema: The day of the competitors ( Spoj Classical )
 *  Tecnica Utilizada:  Line-Sweep
 *	
 *		 Se ordenarmos os competidores por uma das competicoes ( por exemplo a ultima ), 
 *		ao analisarmos eles seguindo essa ordenacao, sempre que estivermos analisando um
 *		competidor X, todos os competidores que poderiam ser melhores que X ja foram analisados
 *		( todos que estao a frente tem uma colocacao pior na terceira competicao ), 
 *      
 *			... digerir ... http://forums.topcoder.com/?module=Thread&threadID=575041
 *
 *  Dificuldade: Dificil
 *	Complexidade:
 *				O( N logN )
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>

#define MAXN 100010

using namespace std;

struct contestant_t {
	int a, b, c;
};

contestant_t contestant[MAXN];

bool comp( contestant_t a, contestant_t b ){
	return a.c < b.c;
}

int main(){

	int t, n, i, out;
	ios::sync_with_stdio( false );
	queue< pair< int, int > > rem;
	set< pair< int, int> >::iterator it;
	
	cin >> t;
	while( t-- ){
	
		cin >> n;
		
		for( i = 0; i < n; i++ ){
			cin >> contestant[i].a >> contestant[i].b >> contestant[i].c;
		}
		sort( contestant, contestant+n, comp );
		
		set< pair< int, int> > exc;
		exc.insert( make_pair( contestant[0].a, contestant[0].b ) );
		out = 1;
		for( i = 1; i < n; i++ ){
			
			it = exc.lower_bound( make_pair( contestant[i].a, contestant[i].b ) );
			
			if( it == exc.begin() || contestant[i].b < (--it)->second  ){
				out++;
				it = exc.lower_bound( make_pair( contestant[i].a, contestant[i].b ) );
				for( ; it != exc.end(); it++ ){
					if( contestant[i].b < it->second ){
						rem.push( *it );
					}
				}
				while( !rem.empty() ){
					exc.erase( rem.front() );
					rem.pop();				
				}
				exc.insert( make_pair( contestant[i].a, contestant[i].b ) );
			}
			
		}
		
		cout << out << endl;
		
	}

	return 0;
}
