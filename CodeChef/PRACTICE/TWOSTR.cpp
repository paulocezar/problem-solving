#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
    	string x, y;
    	cin >> x >> y;
    	int n = x.size();
    	bool match = true;
    	for (int i = 0; i < n; ++i) {
    		if (x[i]=='?' || y[i]=='?') continue;
    		if (x[i] != y[i]) { match = false; break; }
    	}
    	if (match) cout << "Yes\n";
    	else cout << "No\n";
    }

	return 0;
}

















