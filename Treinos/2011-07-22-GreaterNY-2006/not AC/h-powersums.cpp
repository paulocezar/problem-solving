#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int val[31][20];

bool solve( int i, int j, int n ){
	if(n == 0){
		return true;
	}	
		
	for( int ii = 31; ii >= i+1; ii-- ){
		for(int jj = j-1; jj >= 0; jj--)
		{
			if(val[ii][jj] != -1 && val[ii][jj] <= n)
			{
			//cout << val[ii][jj] << endl;
				if(solve(ii, jj, n - val[ii][jj])){
					cout << " [" << ii << ", " << jj << "]";
					return true;
				}
			}
		}
	}
	
	return false;
}

int main(){

	memset( val, -1, sizeof(val) );
	for( int a = 0; a < 31; a++ ){
		long long p = 1;
		for( int b = 0; b < 20 && (1LL<<a)*p < (1LL<<31); b++, p *= 3LL ){
			val[a][b] = (1LL<<a)*p;
		}
	}
	
	int t, tc = 1;
    cin >> t;
    while( t-- ){
		int n;
		cin >> n;
		
		cout << tc++ << " ";
		for(int i = 30; i >= 0; i--){
			for(int j = 0; j < 20; j++ ){
				if(val[i][j] != -1 && val[i][j] <= n)
				if(solve( i, j, n - val[i][j])){
					cout << "[" << i << ", " << j << "]";
					goto hell;
				}
			}
		}
	hell:			
		cout << "\n";
    }

    return 0;
}
