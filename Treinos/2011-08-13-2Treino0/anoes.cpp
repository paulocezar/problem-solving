#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int acum, t, n[9];
	cin >> t;
	while( t-- ){
		acum = 0;
		for( int i = 0; i < 9; i++ ){
			cin >> n[i];
			acum += n[i];
		}
		sort( n, n+9 );
		int bi, bj;
		for( int i = 0; i < 9; i++ )
			for( int j = 0; j < 9; j++ ) if( i != j ){
				if( acum-n[i]-n[j] == 100 ){
					bi = i, bj = j;
					goto hell;
				}
			}
	hell:
		for( int i = 0; i < 9; i++ ) if( i != bi && i != bj )
			cout << n[i] << "\n";
	}

	return 0;
}

