#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    int64 n;
    
    cin >> t;
    while (t--) {
    	cin >> n;
    	if (n == 1LL) cout << "2\n";
    	else {
    		n++;
    		if (n ^ (n & -n)) n = -1;
    		else n = (n>>1) - 1LL;
    		cout << n <<  '\n';
    	}
    }

	return 0;
}

















