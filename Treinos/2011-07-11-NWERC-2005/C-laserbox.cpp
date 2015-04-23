#include <iostream>
#include <cstring>

using namespace std;

int ds[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

int main(){
	
	ios::sync_with_stdio( false );
	int t;
	
	cin >> t;
	while( t-- ){
	
		int n, r;
		cin >> n >> r;
		char rt[n+2][n+2];
		char vis[n+2][n+2][4];
		int x, y;
			
		for( int i = 0; i <= n+1; i++ ) for( int j = 0; j <= n+1; j++ ){
			rt[i][j] = 0;
			for( int k = 0; k < 4; k++ ) vis[i][j][k] = 0;
		}
		
		while( r-- ){
			cin >> x >> y;
			rt[x][y] = 1;
		}
		cin >> x >> y;
		int dir;
		if( x == n+1 ) dir = 0;
		else if( y == 0 ) dir = 1;
		else if( x == 0 ) dir = 2;
		else dir = 3;
		
		x += ds[dir][0]; y += ds[dir][1];
		while( true ){
			
			if( x < 1 || x > n || y < 1 || y > n ) break;
			if( vis[x][y][dir] ){ x = 0; y = 0; break; }
			vis[x][y][dir] = 1;
			
			if( rt[x][y] ) dir = (dir+1)%4;
			
			x += ds[dir][0];
			y += ds[dir][1];
		}
		cout << x << " " << y << "\n";
		
		
	}

	return 0;
}

