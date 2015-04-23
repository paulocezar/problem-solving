#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1003
int a[MAXN];

int main(){

	ios::sync_with_stdio( false );

	int T, N;

	cin >> T;
	while( T-- ){
		
		cin >> N;
		for( int i = 0; i < N; i++ )
			cin >> a[i];
		
		int ans = 0;
		for( int i = 0; i < N; i++ ){
			for( int j = i-1; j >= 0; j-- ) if( a[j] > a[i] ) ans++;
		}
		cout << ans << "\n\n";

	}

	return 0;
}

