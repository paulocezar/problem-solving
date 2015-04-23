#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>

using namespace std;

int dp[1111][1111];
string from, to;

int backtrace( int i, int j ){
	
	if( i + j == 0 ) return 0;
	
	int mov;
	
	if( i == 0 ){
		mov = backtrace( 0, j-1 );
		cout << "INSERT " << mov+1 << " " << to[j-1] << "\n";
		return mov+1;
	} else if( j == 0 ){
		mov = backtrace( i-1, 0 );
		cout << "DELETE " << i+mov << "\n";
		return mov-1;
	}
	
	if( from[i-1] == to[j-1] ){
		return backtrace( i-1, j-1 );
	} else {
		
		int d = min( dp[i-1][j-1], min( dp[i-1][j], dp[i][j-1] ) );
		
		if( d == dp[i-1][j-1] ){
			
			mov = backtrace( i-1, j-1 );
			cout << "REPLACE " << i+mov << " " << to[j-1] << "\n";
			return mov;
			
		} else if( d == dp[i-1][j] ){
			mov = backtrace( i-1, j );
			cout << "DELETE " << i+mov << "\n";
			return mov-1;
			
		} else {
			
			mov = backtrace( i, j-1 );
			cout << "INSERT " << i+1+mov << " " << to[j-1] << "\n";
			return mov+1;
		}
		
	}
	
}

int main(){
	
	int i, j;
	cin >> from >> to;

	int n = from.size();
	int m = to.size();
	
	for( i = 0; i <= n; i++ ) dp[i][0] = i;
	for( j = 0; j <= m; j++ ) dp[0][j] = j;
	
	for( i = 1; i <= n; i++ ){
		for( j = 1; j <= m; j++ ){
			
			if( from[i-1] == to[j-1] ) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = dp[i-1][j-1]+1;
			
			dp[i][j] = min( dp[i][j], min( dp[i-1][j], dp[i][j-1] )+1 );			
		}
	}

	cout << dp[n][m] << "\n";
	backtrace( n, m );
	
	return 0;
}
