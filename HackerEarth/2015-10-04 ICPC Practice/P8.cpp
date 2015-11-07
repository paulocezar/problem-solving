#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

const int64 mod = 1e9 + 7;

int64 x[1<<18];
int64 y[1<<18];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
    	cin >> x[i] >> y[i];
    }
    sort(x, x+N);
    sort(y, y+N);

    int64 ans = 0;
    for (int i = 1; i < N; ++i) {
    	int64 dx = (((i*x[i]%mod) - x[i-1])+mod)%mod;
    	int64 dy = (((i*y[i]%mod) - y[i-1])+mod)%mod;
    	ans += (dx+dy)%mod;
    	ans %= mod;
    	x[i]+=x[i-1]; x[i] %= mod;
    	y[i]+=y[i-1]; y[i] %= mod;
    }
    cout << ans << "\n";

	return 0;
}
