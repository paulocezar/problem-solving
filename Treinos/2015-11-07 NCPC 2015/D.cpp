#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int t[1<<17];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> t[i];

    int ans = 0;
	int lo = 0, hi = 0;
	while (lo < n) {
		while ((hi < n) && (t[hi] < (t[lo]+1000))) hi++;
		ans = max(ans, (hi-lo+k-1)/k);
		lo++;
	}

	cout << ans << "\n";

	return 0;
}
