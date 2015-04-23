#include <iostream>
#include <cmath>
#include <algorithm>

#define MAXN 1100

using namespace std;

int main(){

	ios::sync_with_stdio( false );
	int n, m, i;
	double w, wdt, pointsh[MAXN], pointsv[MAXN];
	bool yes;

	while( true ){

		cin >> n >> m >> wdt;
		if( n == m && m == 0 ) return 0;
		yes = false;
		bool yes2 = false;
		w = wdt / 2.0;

		for( i = 0; i < n; i++ ) cin >> pointsv[i];
		for( i = 0; i < m; i++ ) cin >> pointsh[i];
		
		sort( pointsv, pointsv+n );
		if( !(pointsv[0]-w > 0.0) ){
			for( i = 0; i < n-1; i++ )
				if( pointsv[i]+w < pointsv[i+1]-w ) break;
			if( i == n-1 && !(pointsv[n-1]+w < 75.0) ) yes = true;
		}
		
		if( yes ){
			sort( pointsh, pointsh+m );
			if( !(pointsh[0]-w > 0.0) ){
				for( i = 0; i < m-1; i++ )
					if( pointsh[i]+w < pointsh[i+1]-w ) break;
				if( i == m-1 && !(pointsh[m-1]+w < 100.0) ) yes2 = true;
			}
		}
		
		if( yes && yes2 ) cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}

