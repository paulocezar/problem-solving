#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <cstring>

#define INF 0x3F3F3F3F

using namespace std;

struct state {
	char board[9][9];
	int r, c, e, s;
};

string sstate( state &u ){
	string s = "";
	int i, j;
	for( i = 0; i < 9; i++ )
		for( j = 0; j < 8; j++ )
			s += u.board[i][j];
	s += u.s;
	return s;
}

void npos( int &r, int &c, int &x, int &y, int *nx, int *ny ){
	int i, j, dst, min = INF;
	for( i = -1; i < 2; i++ ){
		for( j = -1; j < 2; j++ ){
			if( i==0 && j == 0 ) continue;
			if( x+i < 0 || x+i > 8 || y+j < 0 || y+j > 7 ) continue;
			
			dst = (r-x-i)*(r-x-i) + (c-y-j)*(c-y-j);
			if( dst < min ){
				min = dst;
				*nx = x+i;
				*ny = y+j;
			}
		}
	}
}

map< string, bool > visited;

bool play( state u ){
	
	if( u.e == 0 ) return true;
	if( u.s > 8 ) return false;

//cout << "at with " << u.s << "steps" << endl;
//for( int x = 0; x < 9; x++ ){
//for( int y = 0; y < 8; y++ )
//cout << u.board[x][y] ;
//cout << endl;
//} cout << endl;

	int i, j, dx, dy, nx, ny;
	state v;
	bool flag;
	int ene;
	int n_ene[9][2];
	bool isolated = true;

	visited[sstate(u)] = true;

	for( dx = -1; dx < 2; dx++ ){
		for( dy = -1; dy < 2; dy++ ){
			
			if( dx == 0 && dy == 0 ) continue;
			if( u.r+dx < 0 || u.r+dx > 8 || u.c+dy < 0 || u.c+dy > 7 ) continue;
			if( u.board[u.r+dx][u.c+dy] == '#' ) continue;
			if( u.board[u.r+dx][u.c+dy] == 'E' ) { isolated = false; continue; }	
			
			isolated = false;		
			
			v.e = u.e;
			v.s = u.s+1;
			v.r = u.r+dx;
			v.c = u.c+dy;
//		cout << "goto" << v.r << " " << v.c << endl;	
			for( i = 0; i < 9; i++ )
				for( j = 0; j < 8; j++ )
					v.board[i][j] = u.board[i][j];
			
			v.board[u.r][u.c] = '.';
			v.board[v.r][v.c] = 'S';

			flag = true;
			ene = 0;
			for( i = 0; i < 9 && flag; i++ ){
				for( j = 0; j < 8; j++ ){
					if( u.board[i][j] == 'E' ){
						npos( v.r, v.c, i, j, &nx, &ny  );
						if( v.board[nx][ny] == '#' ){
							v.e--;
							v.board[i][j] = '.';
						}
						else if( v.board[nx][ny] == 'S' ){
							flag = false;
							break;
						}
						//else if( v.board[nx][ny] == '.'){
						//	v.board[nx][ny] = 'E';
						//	v.board[i][j] = '.';
						//}
						else {
							v.board[i][j] = '.';
							n_ene[ene][0] = nx;
							n_ene[ene][1] = ny;
							ene++;
						}
					}
				}
			}
			
			if( flag ){
				bool des;
				for( i = 0; i < ene; i++ ){
					des = false;
					if( n_ene[i][0] == -1 ) continue;
					for( j = i+1; j < ene; j++ ){
						if( n_ene[i][0] == n_ene[j][0] && n_ene[i][1] == n_ene[j][1] ){
							n_ene[j][0] = -1;
							des = true;
							v.e--;
						}
					}
					if( des ){
						v.board[n_ene[i][0]][n_ene[i][1]] = '#';
						v.e--;
					} else{
						v.board[n_ene[i][0]][n_ene[i][1]] = 'E';
					}
				}

				if( visited.find( sstate( v ) ) == visited.end() ){
					if( play( v ) ) return true;
				}
			}
		}
	}
	
	return isolated;

}

int main(){

	int t, i, j;
	state ini;

	scanf("%d", &t );
	while( t-- ){

		ini.e = 0;
		ini.s = 0;

		for( i = 0; i < 9; i++ ){
			scanf("%s", ini.board[i] );
			for( j = 0; j < 9; j++ ){
				if( ini.board[i][j] == 'S' ) ini.r = i, ini.c = j;
				else if( ini.board[i][j] == 'E' ) ini.e++;
			}
		}
		
		visited.clear();
		if( play( ini ) ) puts("I'm the king of the Seven Seas!");
		else puts("Oh no! I'm a dead man!");
	
	}

	return 0;
}
