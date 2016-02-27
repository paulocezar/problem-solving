#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 B[1<<17];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T, N;
    int64 P;

    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
    	cin >> N >> P;

    	B[0] = 0LL;
    	int64 ans = 0;

    	for (int i = 1; i <= N; ++i) {
    		cin >> B[i];
    		B[i] += B[i-1];
    		
    		int64 geq = B[i] - P;
    		
    		int lo = 0, hi = i-1;
    		while (lo <= hi) {
    			int mid = (lo+hi) >> 1;
    			if (B[mid] >= geq) {
    				hi = mid-1;
    			} else {
    				lo = mid+1;
    			}
    		}
    		
    		ans += i - lo;
    	}

    	cout << "Case #" << tc << ": " << ans << "\n";
    }

	return 0;
}
