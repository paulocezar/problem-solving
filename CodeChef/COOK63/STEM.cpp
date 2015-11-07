#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
    	int n;
    	cin >> n;
    	string a[n];

    	int mx = 0;

    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    		mx = max(mx, int(a[i].size()));
    	}

    	string ans = "";
    	while (mx) {

    		for (int i = 0; (i+mx) <= int(a[0].size()); ++i) {
    			string stem = a[0].substr(i, mx);
    			bool ok = true;
    			for (int j = 1; j < n; ++j) {
    				if (a[j].find(stem) == string::npos) ok = false;
    			}
    			if (ok) ans = (ans.size() ? min(ans, stem) : stem);
    		}

    		if (ans.size()) break;
    		mx--;
    	}

    	cout << ans << "\n";

    }

	return 0;
}
