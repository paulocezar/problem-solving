#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int ans[10][10];
string grid[11];
int ds[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

#define INF 0x3F3F3F3F
bool ok( int x, int y ){ return ((x>=0)&&(x<10)&&(y>=0)&&(y<10)); }

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while( t-- ){
		queue< int > q;
		for( int i = 0; i < 10; i++ ){
			cin >> grid[i];
			for( int j = 0; j < 10; j++ ){
				ans[i][j] = INF;
				if( j == 0 ){
					q.push( 10*i );
					ans[i][j] = 0;
				}
			}
		}
		cin >> grid[10];
		while( !q.empty() ){
			int x = q.front(); q.pop();
			int y = x%10; x/=10;
			for( int dir = 0; dir < 4; dir++ ){
				int nx = x + ds[dir][0];
				int ny = y + ds[dir][1];
				if( ok(nx,ny) && abs(grid[nx][ny]-grid[x][y]) <= 1 && ans[x][y]+1 < ans[nx][ny] ){
					ans[nx][ny] = ans[x][y]+1;
					q.push( 10*nx + ny );
				}
			}
		}
		int r = INF;
		for( int i = 0; i < 10; i++ )
				r = min(r,ans[i][9]);
		if( r == INF ) cout << "IMPOSSIBLE\n";
		else cout << r << "\n";
	}
	return 0;
}

