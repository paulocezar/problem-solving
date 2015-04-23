#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

#define MAXN 110
#define INF 0x3F3F3F3F

using namespace std;

int dis[MAXN][MAXN];
int minDists[MAXN*MAXN];

int main(){

	ios::sync_with_stdio( false );
	int sc, scenarios, i, j, k, p, n;
	int req, pos;

	cin >> scenarios;
	for( sc = 1; sc <= scenarios; sc++ ){

		cin >> p >> n;
		for( i = 0; i < n; i++ ){
			for( j = 0; j < n; j++ ){
				cin >> dis[i][j];	
				if( dis[i][j] == -1 ) dis[i][j] = INF;
			}
		}

		for( k = 0; k < n; k++ ){
			for( i=0; i < n; i++ ){
				for( j = 0; j < n; j++ ){
					if( dis[i][k]+dis[k][j] < dis[i][j] )
						dis[i][j] = dis[i][k]+dis[k][j];
				}
			}
		}
		
		pos = 0;
		for( i = 0; i < n; i++ ){
			for( j = 0; j < n; j++ ){
				if( i != j && dis[i][j] != INF )
					minDists[pos++] = dis[i][j];
			}	
		}

		sort( minDists, minDists+pos );

		req = ceil( (double)(pos*p)/100.0 ) -1;
		cout << "Cenario #" << sc << ":\n" << minDists[req] << "\n\n";

	}

	return 0;
}


