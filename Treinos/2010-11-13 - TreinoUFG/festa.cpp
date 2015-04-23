#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	ios::sync_with_stdio( false );
	
	int sc, scenarios;
	int d, n, c, i, j, k;
	long long g;
	const double pi = acos( -1 );
	double r, teta, area, out, zji, zik;
	
	cin >> scenarios;
	
	for( sc = 1; sc <= scenarios; sc++ ){
			
			cin >> d >> n >> c >> g;
			r = (double)d/2.0;
		
			int adequados[c];
			double x[c], y[c];
			
			long long ax = 0;
			for( i = 0; i < c; i++, ax++ )
				adequados[i] = (int)( ( ax * g ) %  (long long)n );
				
			sort( adequados, adequados+c );
			
			for( i = 0; i < c; i++ ){
				teta = ( 2.0 * pi / n ) * adequados[i];
				x[i] = cos( teta ) * r;
				y[i] = sin( teta ) * r;
 			}
			
			out = 0.0;
			for( i = 1; i < c; i++ ){
				 zji = 0.0;
				 for( j = 1; j < i; j++ ){ 
					area = x[0]*y[j] + y[0]*x[i] + x[j]*y[i] - x[i]*y[j] - y[i]*x[0] - x[j]*y[0];
					area = abs( area );
					if( zji < area ) zji = area; 
				 }
				 zik = 0.0;
				 for( k = i+1; k < c; k++ ){
					area = x[0]*y[i] + y[0]*x[k] + x[i]*y[k] - x[k]*y[i] - y[k]*x[0] - x[i]*y[0];
					area = abs( area );
					if( zik < area ) zik = area;
				 }
				 if( out < (zji+zik) ) out = zji+zik;
			}
			
			cout << "Cenario #" << sc << ":\n" <<  fixed << setprecision( 6 ) << out/2.0 << "\n\n";
	
	}

	return 0;
}
