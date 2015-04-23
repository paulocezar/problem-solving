#include <iostream>

using namespace std;

#define MAXN 21
double prob[2][MAXN][MAXN];
double p[4];

int ds[][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}  };

bool ok( int x, int y ){ return ((x>=0)&&(x<MAXN)&&(y>=0)&&(y<MAXN)); }

int main(){
	ios::sync_with_stdio(false);
	int t, steps;
	cin >> t;
	while( t-- ){
		cin >> steps >> p[0] >> p[1] >> p[2] >> p[3];
		
		for( int i = 0; i < 4; i++ ) p[i] /= 100.0;

		for( int i = 0; i < MAXN; i++ )
		for( int j = 0; j < MAXN; j++ )
			prob[0][i][j] = 0;
		prob[0][10][10] = 1.0;

		int old = 0, cur =1;
		for( int s = 0; s < steps; s++ ){

			for( int i = 0; i < MAXN; i++ )
			for( int j = 0; j < MAXN; j++ ){
				prob[cur][i][j] = 0;
				for( int dir = 0; dir < 4; dir++ ){
					int oi = i + ds[dir][0];
					int oj = j + ds[dir][1];
					if( ok(oi,oj) )
						prob[cur][i][j] += prob[old][oi][oj]*p[dir];
				}
			}

			old = !old;
			cur = !cur;
		}
		cout << int(100.0*prob[old][10][10]) << "\n";
	}
	return 0;
}

