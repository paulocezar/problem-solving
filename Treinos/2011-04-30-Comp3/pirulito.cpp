#include <iostream>
#include <cmath>
#include <iomanip>

typedef long long int64;
using namespace std;

template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

int main(){
	
	ios::sync_with_stdio( false );

	int T;
	double P, r, s, t;
	int dt;
	
	cin >> T;
	while( T-- ){
		cin >> P >> r >> s >> dt >> t;
		double menos;
		
		if( dt == 1 ) menos = (s*t*t)/2.0;
		else if( dt == 2 ) menos = ( 2.0*s*t*sqrt( t ) )/3.0;
		else menos = ( 3.0*s*t*cbrt( t ) )/4.0;
		
	 	cout << setprecision( 0 ) << fixed << P + r*t - menos << "\n\n";
	}


	return 0;
}

























