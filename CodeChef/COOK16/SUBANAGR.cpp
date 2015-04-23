#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	int at[N][26];
	memset( at, 0, sizeof(at) );
	string str;
	
	for( int i = 0; i < N; i++ ){
		cin >> str;
		int sz = int(str.size());
		for( int j = 0; j < sz; j++ ) at[ i ][ str[j]-'a' ]++;
	}
	
	int len = 0;
	for( int j = 0; j < 26; j++ ){
		int mn = at[0][j];
		for( int i = 1; i < N; i++ )
			mn = min( mn, at[i][j] );
		len += mn;
		while( mn-- ) cout << char(j+'a');
	}
	
	if( len == 0 ) cout << "no such string\n";
	else cout << "\n";
	
	return 0;
}
