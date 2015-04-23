#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t, n;
	cin >> t;
	while( t-- ){
		cin >> n;
		int cols = (n-1)/2;
		cols = 1 + cols*2;
		
		int from = (cols+1)/2 - 1;
		int to = from;
		
		for( int i = 0; i < n; i++ ){
				
				for( int j = 0; j < cols; j++ ){
					if( from <= j && j <= to ) cout << "*";
					else cout << ".";
				}
				if( i != n-1 || t ) cout << "\n";
				if( i&1 ) from--, to++;
		}

	}
	return 0;
}

