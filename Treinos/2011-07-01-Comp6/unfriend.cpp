#include <iostream>
#include <set>

using namespace std;

int main(){
	
	ios::sync_with_stdio( false );

	int t;
	cin >> t;
	while( t-- ){
		
		int P;
		cin >> P;
		int parent[P+1]; parent[P-1] = -1;
		for( int i = 0; i < P-1; i++ ){
			cin >> parent[i]; parent[i]--;
		}

		set< int > ans;
		int lmask = 1<<(P);
		for( int curset = 0; curset < lmask; curset++ ){
			
			if( curset & (1<<(P-1)) ) continue;
			
			int nset = curset;
			for( int i = 0; i < P-1; i++ ){
				for( int j = 0; j < P-1; j++ ){
					if( nset & (1<<parent[j]) ) nset |= (1<<j);
				}
			}
			ans.insert( nset );

		}
		cout << ans.size() << "\n";

	}
	return 0;
}

