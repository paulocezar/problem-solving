#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
#include <utility>

using namespace std;

bool ok[12][12];

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while( t-- ){
		int C, o, d;
		cin >> C;
		memset( ok, false, sizeof(ok) );
		for( int i = 0; i < 5; i++ ){
				cin >> o >> d;
				ok[o][d] = true;
		}
		if( ok[0][1] ) cout << "SIM\n";
		else {
			for( int i = 0; i < C; i++ )
				if( ok[0][i] && ok[i][1] ){
					cout << "SIM\n";
					ok[0][1] = true;
					break;
				}
			if( !ok[0][1] ) cout << "NAO\n";
		}
		
	}
	return 0;
}

