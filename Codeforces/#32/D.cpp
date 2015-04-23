#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	
	int n, m, k;
	string grid[310];
	
	cin >> n >> m >> k;
	for( int i = 0; i < n; ++i ) cin >> grid[i];
	
	int maxr = min( n, m )/2;
	
	for( int radi = 1; radi <= maxr; radi++ ){
		for( int i = radi; i+radi < n; i++ ){
			for( int j = radi; j+radi < m; j++ ){
				if( grid[i][j] == '*'
					&& grid[i-radi][j] == '*'
					&& grid[i+radi][j] == '*'
					&& grid[i][j-radi] == '*'
					&& grid[i][j+radi] == '*' ){
						k--;
						if( k == 0 ){
							cout << i+1 << " " << j+1 << "\n";
							cout << i-radi+1 << " " << j+1 << "\n";
							cout << i+radi+1 << " " << j+1 << "\n";
							cout << i+1 << " " << j-radi+1 << "\n";
							cout << i+1 << " " << j+radi+1 << "\n";
							return 0;
						}
				}
			}
		}
	}
	
	cout << "-1\n";
	
	return 0;
}
