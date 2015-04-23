#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	
	int t; string s;
	double m;
	
	cin >> t;
	int tc = 1;
	while( t-- ){
		cin >> m >> s;
		cout << tc++ << " ";
		
		if( s == "kg" ){
			m = m*2.2046; s = "lb";
		} else if( s == "lb" ){
			m = m*0.4536; s = "kg";
		} else if( s == "g" ){
			m = m*3.7854; s = "l";
		} else {
			m = m*.2642; s = "g";
		}
		cout << fixed << setprecision(4) << m << " " << s << "\n";
	}
	
	return 0;
}