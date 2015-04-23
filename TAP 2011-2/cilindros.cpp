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
#include <iomanip>

using namespace std;

int n;
double r[111];
double xc[111], yc[111];

int main(){
	ios::sync_with_stdio(false); 
	
	int t, tc = 1;
	cin >> t;
	while( t-- ){
		cin >> n;
		for( int i = 0; i < n; i++ ) cin >> r[i];
		xc[0] = r[0];
		yc[0] = r[0];

		double ans = 2*r[0];
		
		for( int i = 1; i < n; i++ ){
			xc[i] = r[i];
			yc[i] = r[i];
			for( int j = 0; j < i; j++ ){
				double nxc = xc[j] + sqrt( (r[i]+r[j])*(r[i]+r[j]) - (r[i]-r[j])*(r[i]-r[j]) );
				
				xc[i] = max( xc[i], nxc );			
			}
			ans = max( ans, xc[i]+r[i] );
		}
		cout << fixed << setprecision(1) << "#" << tc++ << ": " << ans << "\n";
	}	

	return 0;
}


