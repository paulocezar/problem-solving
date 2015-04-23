#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

#define MAXR 30
#define MAXC 100
char ans[MAXR][MAXC];

int main(){
	ios::sync_with_stdio(false);
	
	int t, tc = 1;
	int r, c;
	string line;
	
	cin >> t;
	while( t-- ){

		cin >> r >> c; cin.ignore(); getline( cin, line );
		
		for( int i = 0; i < r; i++ ){
			for( int j = 0; j < c; j++ ) ans[i][j] = ' ';
			ans[i][c] = '\n'; ans[i][c+1] = '\0';
		}
		
		int i = 0, j = 0;
		int p = 0, sz = int(line.size());
		string s = ""; bool op = false;
		while( p < sz ){
			if( line[p] == '[' ) op = true;
			if( line[p] == ']' ){
				if( op ) op = false;
				// verifica o que s é
			} else {
				if( op ) s += line[p];
				else ans[i][j++] = line[p];
				
			}
			s += line[p];
			p++;
		}		
		
		cout << tc++ << "\n";
		for( int i = 0; i < r; i++ ) cout << ans[i];
		cout << "\n";
		
	}
	
	return 0;
}
