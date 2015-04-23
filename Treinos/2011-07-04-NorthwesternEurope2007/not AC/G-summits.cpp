#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>

#define REP( i, a ) for( int i = 0; i < a; i++ )

using namespace std;

#define MAXH 500
#define MAXW 500

int heigh[MAXH][MAXW];
bool seen[MAXH][MAXW];

int h, w, d;
int val, mval;

bool flood( int i, int j ){
	if( heigh[i][j] > val ) return false;
	if( heigh[i][j] <= mval ) return true;
	
	seen[i][j] = true;
	bool r = true;
	if( i+1 < h && !seen[i+1][j] ) r = r && flood( i+1, j );
	if( r && i-1 >= 0 && !seen[i-1][j] ) r = r && flood( i-1, j );
	if( r && j+1 < w && !seen[i][j+1] ) r = r && flood( i, j+1 );
	if( r && j-1 >= 0 && !seen[i][j-1] ) r  = r && flood( i, j-1 );
	seen[i][j] = false;
	return r;
}

int main(){
	
	ios::sync_with_stdio( false );
	int t;
	
	cin >> t;
	while( t-- ){
	
		cin >> h >> w >> d;
		
		int mx = -1;
		REP( i, h ) REP( j, w ){
			cin >> heigh[i][j];
			seen[i][j] = false;			
			mx = max( mx, heigh[i][j] );
		}
		
		int ans = 0;
		REP( i, h ) REP( j, w ){
			if( heigh[i][j] == mx ) ans++;
			else{
				val = heigh[i][j];
				mval = heigh[i][j]-d;				
				if( flood( i, j ) ) ans++;
			}
		}
		cout << ans << "\n";
		
	}

	return 0;
}

