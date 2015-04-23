#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n, v[33];
long long dp[33][33][1001];

long long solve( int pos, int mn, int rem ){
	if( pos == n || rem < v[pos] ){
		if( mn == 0 ) return 1LL;
		if( v[mn-1] > rem ) return 1LL;
		return 0LL;
	}
	
	if( dp[pos][mn][rem] == -1 ){
		
		dp[pos][mn][rem] = 0LL;
		
		if( mn == 0 ) dp[pos][mn][rem] = solve( pos+1, pos+1, rem );
		else dp[pos][mn][rem] = solve( pos+1, mn, rem );
		
		dp[pos][mn][rem] += solve( pos+1, mn, rem-v[pos] );
	}
	return dp[pos][mn][rem];
}

int main(){
	ios::sync_with_stdio(false);
	
	int b, t, tc = 1;
	cin >> t;
	while( t-- ){
		
		cin >> n >> b;
		for( int i = 0; i < n; i++ ){
			cin >> v[i];
			for( int j = 0; j <= n; j++ ) for( int k = 0; k <= b; k++ ) dp[i][j][k] = -1;
		}
		sort( v, v+n );
		
		if( b < v[0] ) cout << tc++ << " 0\n";
		else cout << tc++ << " " << solve( 0, 0, b ) << "\n";
				
	}
	
	return 0;
}
