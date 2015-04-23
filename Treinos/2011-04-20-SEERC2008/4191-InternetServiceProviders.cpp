#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	long long n, c, m;
	
	
	while (cin >> n >> c) {
		
		
		if (n) {
			
			double d = ( 1.0*c )  / ( 2.0*n );
			int g = c / ( 2*n );
			
			if (d <= g + .5) cout << g << "\n";
			else cout << (g+1) << "\n";
			
		}
		else cout << "0\n";
	}
	
	return 0;
}