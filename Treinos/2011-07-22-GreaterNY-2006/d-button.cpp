#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long long ff[12], gg[12];
long long c[12][12];

long long g( int n ){
	if( gg[n] != -1 ) return gg[n];
	gg[n] = 0;
	for( int i = 1; i <= n; i++ ) gg[n] += c[n][i]*g( n-i );
	return gg[n];
}

long long solve( int n ){
	if( ff[n] != -1 ) return ff[n];
	ff[n] = 0;
	for( int i = 1; i <= n; i++ ) ff[n] += c[n][i] * g( i );
	return ff[n];
}

int main(){
	ios::sync_with_stdio(false);
	
	memset( ff, -1, sizeof(ff) ); memset( gg, -1, sizeof(gg) ); gg[0] = 1;
	memset( c, 0, sizeof(c) );
	for( int i = 0; i < 12; i++ ){
		c[i][0] = c[i][i] = 1;
		for( int j = 1; j < i; j++ ) c[i][j] = c[i-1][j-1] + c[i-1][j];	
	}		
	
	int t, tc = 1;
	cin >> t;
	while( t-- ){
		int n;
		cin >> n;
		
		cout << tc++ << " " << n << " " << solve(n) << "\n";
				
	}
	
	return 0;
}
