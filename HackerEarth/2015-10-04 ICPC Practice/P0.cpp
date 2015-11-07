#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 H[1024];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T, N;
    int64 Q;
    cin >> T;
    while (T--) {
    	cin >> N >> Q;
    	for (int i = 0; i < N; ++i) cin >> H[i];
    	sort(H, H+N);
    	int64 ans = 0;
    	for (int i = 1; i < N; ++i) {
    		ans += H[i] - H[i-1];
    	}
    	ans *= Q;
    	cout << ans << "\n";
    }

	return 0;
}
