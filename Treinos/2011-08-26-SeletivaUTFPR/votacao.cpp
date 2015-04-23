#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <queue>

using namespace std;

queue< int > q[1111];

int main(){
	
	ios::sync_with_stdio( false );
	int t;
	cin >> t;
	while( t-- ){
		int N;
		cin >> N; cin.ignore();
		string name[N];
		bool out[N];
		int votes[N];
		
		for( int i = 0; i < N; i++ ){
			getline( cin, name[i] );
			out[i] = false;
		}
		
		int v, P = 0;
		cin >> v;
		while( v ){
			while( !q[P].empty() ) q[P].pop();
			q[P].push( v-1 );
			for( int i = 1; i < N; i++ ){ cin >> v; q[P].push( v-1 ); }
			P++;
			cin >> v;
		}
		
		int nd = P/2;
		int mx, mn;
		
		while( true ){
			
			for( int i = 0; i < N; i++ ) votes[i] = 0;
			
			for( int i = 0; i < P; i++ ){
				while( out[ q[i].front() ] ) q[i].pop();
				votes[ q[i].front() ]++;
			}
			
			mx = 0, mn = P;
			for( int i = 0; i < N; i++ ) if( !out[i] ){
				mx = max( mx, votes[i] );
				mn = min( mn, votes[i] );
			}
			if( mx > nd ) break;
			else {
				int tot = 0, mnn = 0;
				for( int i = 0; i < N; i++ ) if( !out[i] ){
					tot++;
					if( votes[i] == mn ) mnn++; 
				}
				if( mnn == tot ) break;
				for( int i = 0; i < N; i++ ) if( votes[i] == mn ) out[i] = true;
			}
		}
		for( int i = 0; i < N; i++ ) if( votes[i] == mx )
			cout << name[i] << "\n";
		cout << "\n";
		
		
	}
	
	return 0;
}
