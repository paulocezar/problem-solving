#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int a[1<<20];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T, n;
    cin >> T;
    while (T--) {
    	cin >> n;
    	for (int i = 0; i < n; ++i) cin >> a[i];
    	for (int i = 1; i < n; ++i) {
    		if (a[i] < a[i-1]) {
    			swap(a[i], a[i-1]);
    			a[i] = -a[i];
    			a[i-1] = -a[i-1];
    		}
    	}
    	for (int i = 0; i < n; ++i) if (a[i] < 0) a[i] = -a[i];
    	
    	bool ok = true;
    	for (int i = 1; i < n; ++i) if (a[i] < a[i-1]) {
    		ok = false; break;
    	}

    	if (ok) { cout << "YES\n"; }
    	else { cout << "NO\n"; }
    }
    

	return 0;
}
