#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char col[1001], di[1001];
char seen[1001][1001];
		

int main(){

    int t, tc = 1;
 	int n, pos;
 	
    cin >> t;
    while( t-- ){
		
		cin >> n;
		pos = (2*n + 1)/3;
		int x = n;
		int y = n/2;
		
		memset( col, 0, sizeof(col) );
		memset( di, 0, sizeof(di) );
		memset( seen, 0, sizeof( seen ) );
		
		col[y] = 1;
		di[ x-y ] = 1;
		
		cout << tc++ << " " << n << " " << pos << "\n";
		int ct = 1;
		cout << "[" << x << "," << y << "]";
		
		bool fl = true;
		x--;
		while( ct != pos ){
			
			if( y >= x+1 ) y = 1;
			
			while( col[y] || di[x-y] ){
				cout << x << " " << y << endl;
				seen[x][y] = 1;
				y++;
				if( y == x+1 ) y = 1;
				if( seen[x][y] ){
					x--;
					y = 1;
				}
			}
			col[y] = 1;
			di[x-y] = 1;
			
			if( fl ) cout << " ";
			else fl = true;
			cout << "[" << x << "," << y << "]"; ct++;
			x--;
			if( ct % 8 == 0 ){ 
				cout << "\n";
				fl = false;
			}
		}
		cout << "\n";
    }

    return 0;
}
