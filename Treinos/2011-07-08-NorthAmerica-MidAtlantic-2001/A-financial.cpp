#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	
	double m, acum = 0.0;
	for( int i = 0; i < 12; i++ ){
		cin >> m;
		acum += m;
	}
	cout << "$" << fixed << setprecision(2) << acum/12.0 << "\n";
		
}