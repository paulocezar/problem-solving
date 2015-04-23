#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

int main(){

	int v, t = 1;
	set< int >::iterator it;

	while( 1 ){
		
		scanf("%d", &v );
		if( v < 0 ) return 0;

		if( t > 1 ) cout << endl;
		set< int > el;

		
		do {

			el.insert( -v );
			it = el.find( -v );
			it++;
			if( it != el.end() ) el.erase( it );

			scanf("%d", &v );
		} while( v > 0 );
		
		cout << "Test #" << t++ << ":\n  maximum possible interceptions: " << el.size() << endl;
	}

	return 0;
}

