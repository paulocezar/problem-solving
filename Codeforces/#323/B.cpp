#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int a[1024];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    int got = 0;
    int pos = 0;
    int dir = 1;
    int ans = 0;
    while (got < n) {

    	while ((0 <= pos) && (pos < n)) {
    		if (got >= a[pos]) {
    			got++;
    			a[pos] = 2e9;
    		}
    		pos += dir;
    	}

    	if (pos < 0) pos = 0;
    	if (pos >= n) pos = n-1;
    	dir *= -1;
    	if (got < n) ans++;
    }

	cout << ans << "\n";

	return 0;
}

















