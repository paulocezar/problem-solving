#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t, n;
	int u, d, e, r;
	int nu, nd, ne;
	
	cin >> t;
	while(t--){
		cin >> n;
		
		r = 0;
		u = n;
		d = e = 0;
		
		while(u != 1 || d != 1){
			cout << "Round " << r++ << ": " << u << " undefeated, " << d << " one-loss, " << e << " eliminated\n"; 
			nu = u; nd = d; ne = e;
			
			ne += d/2;
			nd += u/2 - d/2;
			nu -= u/2;
			
			u = nu; d = nd; e = ne;
		}
		cout << "Round " << r++ << ": " << u << " undefeated, " << d << " one-loss, " << e << " eliminated\n"; 
		cout << "Round " << r++ << ": " << 0 << " undefeated, " << 2 << " one-loss, " << e << " eliminated\n"; 
		cout << "Round " << r << ": " << 0 << " undefeated, " << 1 << " one-loss, " << e+1 << " eliminated\n"; 
		cout << "There are " << r << " rounds.\n";
		
		if(t) cout << "\n";
	}
	return 0;
}
