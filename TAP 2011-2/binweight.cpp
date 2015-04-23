#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio( false );
	int t, n;
	cin >> t;
	while( t-- ){
		cin >> n;
		int lg = 0;
		while( !(n&(1<<lg) && !(n&(1<<(lg+1)))) ) lg++;
		
		int nn = n & ~((1<<(lg+1))-1);
		nn |= (1<<(lg+1));
		int nd = __builtin_popcount( n & ((1<<lg)-1) );
		
		while( nd ){
			nd--;
			nn |= (1<<nd);
		}
		cout << nn << "\n";
	}
	return 0;
}

