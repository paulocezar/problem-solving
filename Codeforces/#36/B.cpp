#include <fstream>
#include <string>
#include <iostream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

char pt[5][5];
char end[250][250];

int n;

int e( int a, int b ){
	int r = 1;
	while( b-- ) r *= a;
	return r;
}

void fractal( int d, char c, int x, int y ){
	
	int i, j, sz;

	if( d == 0 ){
		if( c == '.' ){
 			end[x][y] = '.';
		} else {
			end[x][y] = '*';
		}
		return;
	}
	
	sz = e( n, d-1 );
	if( c == '.' ){
		
		for( i = 0; i < n; i++ ){
			for( j = 0; j < n; j++ ){
				fractal( d-1, pt[i][j], x+sz*i, y+sz*j );
			}
		}
		
	} else {
		
		for( i = 0; i < n; i++ ){
			for( j = 0; j < n; j++ ){
				fractal( d-1, '*', x+sz*i, y+sz*j );
			}
		}
		
	}	
	
}

int main () {
    
	int k, i, j, sz;
	
    fin >> n >> k;
	for( i = 0; i < n; i++ ) fin >> pt[i];
	
	sz = e( n, k-1 );
	for( i = 0; i < n; i++ ){
		for( j = 0; j < n; j++ ){
			fractal( k-1, pt[i][j], sz*i, sz*j );
		}
	}	
	
	sz = e( n, k );
	for( i = 0; i < sz; i++ ){
		for( j = 0; j < sz; j++ ){
			fout << end[i][j];
		}
		fout << endl;
	}
	
	
    return 0;
}
