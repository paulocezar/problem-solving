#include <iostream>
#include <cstring>

using namespace std;

char grid[510][510];

int main(){

	int t;
	char dir; int mv;

	cin >> t;
	while( t-- ){
		
		memset( grid, 0, sizeof(grid) );
		
		int x = -1 + 200;
		int y = -5 + 200;
		grid[0+200][-1+200] = 1;
		grid[0+200][-2+200] = 1;
		grid[0+200][-3+200] = 1;
		grid[1+200][-3+200] = 1;
		grid[2+200][-3+200] = 1;
		grid[3+200][-3+200] = 1;
		grid[3+200][-4+200] = 1;
		grid[3+200][-5+200] = 1;
		grid[4+200][-5+200] = 1;
		grid[5+200][-5+200] = 1;
		grid[5+200][-4+200] = 1;
		grid[5+200][-3+200] = 1;
		grid[6+200][-3+200] = 1;
		grid[7+200][-3+200] = 1;
		grid[7+200][-4+200] = 1;
		grid[7+200][-5+200] = 1;
		grid[7+200][-6+200] = 1;
		grid[7+200][-7+200] = 1;
		grid[6+200][-7+200] = 1;
		grid[5+200][-7+200] = 1;
		grid[4+200][-7+200] = 1;
		grid[3+200][-7+200] = 1;
		grid[2+200][-7+200] = 1;
		grid[1+200][-7+200] = 1;
		grid[0+200][-7+200] = 1;
		grid[-1+200][-7+200] = 1;
		grid[-1+200][-6+200] = 1;
		grid[-1+200][-5+200] = 1;
		
		cin >> dir >> mv;
		
		bool ok = true;
		while( dir != 'q' ){
			if( ok ) while( mv > 0 ){
				switch( dir ){
					case 'l': x--; break; 
					case 'r': x++; break;
					case 'd': y--; break;
					case 'u': y++; break;
				}
				if( grid[x][y] ){
					if( dir == 'l' ) x -= mv-1;
					if( dir == 'r' ) x += mv-1;
					if( dir == 'd' ) y -= mv-1;
					if( dir == 'u' ) y += mv-1;
					cout << x-200 << " " << y-200 << " DANGER\n";
					ok = false;
					break;
				} else grid[x][y] = 1;
				mv--;
			}
			if( ok ) cout << x-200 << " " << y-200 << " safe\n";
			
			cin >> dir >> mv;
		}

	
	}

	return 0;
}

