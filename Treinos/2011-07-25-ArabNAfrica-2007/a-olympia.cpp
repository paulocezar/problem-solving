#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	
	int v[6];
	int acum = 0; for( int i = 0; i < 6; i++ ){ cin >> v[i]; acum += v[i];	}

	while( acum ){
		sort( v, v+6 );
		acum -= ( v[0] + v[5] );
		cout << acum/4.0 << "\n";	

	acum = 0; for( int i = 0; i < 6; i++ ){ cin >> v[i]; acum += v[i]; }
	}

	return 0;
}

