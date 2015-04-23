#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

int popc( int a ){
	int ans =0;
	while( a > 0 ){
		ans++;
		a -= (a & -a);
	}
	return ans;
}

int main(){
	
	int t;
	cin >> t;
	while( t-- ){
		int n;
		cin >> n;
		int mode, mask = 0;
		for( int i = 0; i < n; i++ ){
			cin >> mode;
			if( mode ) mask |= (1<<i);
		}
		
		map< int, int > vis;
		vis[mask] = 0;
		priority_queue< pair<int,int> > q;
		q.push( make_pair( -popc(mask) , mask ) );

		while( !q.empty() ){
			
			mask = q.top().second; q.pop();
			
			for( int i = 0; i < n; i++ ) if( !( mask & (1<<i)) ){
			}

		}

		cout << vis[0] << "\n";
	}

	return 0;
}


