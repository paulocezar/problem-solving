#include <iostream>
#include <algorithm>

#define mp make_pair

int ABS( int A ){ if( A < 0 ) return -A; return A; }

using namespace std;

int main(){

	ios::sync_with_stdio( false );
	int T;
	cin >> T;

	while( T-- ){
		
		int u;
		cin >> u;
	
		int lvls = 2*u + 1;
		int xc = (lvls+1)/2;
		int yc = xc;
		int zc = xc;

		for( int cur = 1; cur <= lvls; cur++ ){
			cout << "nivel #" << cur << ":\n";
			for( int x = 1; x <= lvls; x++ ){
				for( int y = 1; y <= lvls; y++ ){
					
					if( ABS(cur-zc)+ABS(x-xc)+ABS(y-yc) > u ) cout << ".";
					else cout << ABS(cur-zc)+ABS(x-xc)+ABS(y-yc);

				}
				cout << "\n";
			}
		}
		cout << "\n";

	}

	return 0;
}

