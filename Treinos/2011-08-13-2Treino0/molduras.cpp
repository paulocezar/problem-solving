#include <iostream>
#include <string>

using namespace std;

int bg[5] = { 2, 1, 0, 1, 2 };
int stp[5] = { 4, 2, 4, 2, 4 };

int bgs[5] = { 10, 9, 8, 9, 10 };
int stps[5] = { 0, 2, 4, 2, 0 };

int main(){
	
	int t;
	cin >> t;
	string txt;

	while( t-- ){
		cin >> txt;
		int N = int( txt.size() );
		int cols = 5 + (N-1)*4;
		
		string ans[5];
		for( int i = 0; i < 5; i++ ){
			ans[i] = "";
			for( int j = 0; j < cols; j++ )
				ans[i] += ".";
			ans[i] += "\n";
		}
		
		for( int i = 0; i < 5; i++ )
			for( int j = bg[i]; j < cols; j += stp[i] )
				ans[i][j] = '#';
		
		for( int i = 0; i < 5; i++ )
			for( int j = bgs[i]; j+1 < cols; j += 12 )
				ans[i][j] = ans[i][j+stps[i]] = '*';
		
		for( int i = 0, j = 2; i < N; i++, j += 4 )
			ans[2][j] = txt[i];
		
		for( int i = 0; i < 5; i++ ) cout << ans[i];
			
	}

	return 0;
}

