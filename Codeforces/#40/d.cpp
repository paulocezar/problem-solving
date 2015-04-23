/*
 *  Problema:
 *  Tecnica Utilizada:  
 *	
 *
 *  Dificuldade: 
 *	Complexidade:
 *				O(  )
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int dp[110][110][12];
int path[110][110][12];
int grid[110][110];

int n, m, k;
string spath;

int construct( int i, int j, int r ){
	
	int ans;
	if( i == n-1 ) return j+1;
	
	if( path[i][j][r] == -1 ){
		ans = construct( i+1, j-1, (dp[i][j][r]-grid[i][j])%k );
		spath += 'R';
		return ans;
	}
	
	ans = construct( i+1, j+1, (dp[i][j][r]-grid[i][j])%k );
	spath += 'L';
	return ans;
}

int main(){

	int i, j, r, ans;
	string line;
	ios::sync_with_stdio( false );
		
	cin >> n >> m >> k;
	k++;
	
	for( i = 0; i < n; i++ ){
		cin >> line;
		for( j = 0; j < m; j++ ) grid[i][j] = line[j] - '0';
	}
	
	for( i = 0; i < n; i++ )
		for( j = 0; j < m; j++ )	
			for( r = 0; r < k; r++ )
				dp[i][j][r] = -1;
	
	for( j = 0; j < m; j++ )
		dp[n-1][j][ grid[n-1][j] % k ] = grid[n-1][j];

	for( i = n-2; i >= 0; i-- ){
		for( j = 0; j < m; j++ ){	
			
			for( r = 0; r < k; r++ ){
				
				 if( j && dp[i+1][j-1][r] >= 0 ){
					ans = dp[i+1][j-1][r]+grid[i][j];
					if( ans > dp[i][j][ ans % k ] ){
						dp[i][j][ans % k] = ans;
						path[i][j][ans % k ] = -1;
					}	
				 }
				 
				 if( j != m-1 && dp[i+1][j+1][r] >= 0 ){	
					ans = dp[i+1][j+1][r]+grid[i][j];
					if( ans > dp[i][j][ ans % k ] ){
						dp[i][j][ans % k] = ans;
						path[i][j][ans % k ] = 1;
					}
				 }
					
			}
			
		}
	}
	
	ans = -1;
	for( j = 0; j < m; j++ ) if( dp[0][j][0] > ans ) { ans = dp[0][j][0]; i = j; }

	if( ans == -1 ) cout << "-1\n";
	else {
		
		cout << ans << endl;
		spath = "";
		cout << construct( 0, i, 0 ) << "\n";
		cout << spath << "\n";
	
	}

	return 0;
}
