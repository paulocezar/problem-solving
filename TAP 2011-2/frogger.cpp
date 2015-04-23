#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

#define MAXN 202
int x[MAXN], y[MAXN], d[MAXN][MAXN];

int main(){
	ios::sync_with_stdio(false);
	
	int n, dx, dy, tc = 1;
	cout << fixed << setprecision(3);
	
	while( cin >> n && n ){
		for( int i = 0; i < n; i++ ) cin >> x[i] >> y[i];
		
		for( int i = 0; i < n; i++ )
                for( int j = i+1; j < n; j++ ){
                     dx = x[i]- x[j], dy = y[i]- y[j];
                     d[i][j] = d[j][i] = dx*dx + dy*dy;
                }
                
           for( int k = 0; k < n; k++ )
                for( int i = 0; i < n; i++ )
                     for( int j = i+1; j < n; j++ )
                          d[i][j] = d[j][i] = min( d[i][j], max( d[i][k], d[k][j] ) );
                
		cout << "Scenario #" << tc++ << "\nFrog Distance = " << sqrt(d[0][1]) << "\n\n";
		
		
	}

	return 0;
}

