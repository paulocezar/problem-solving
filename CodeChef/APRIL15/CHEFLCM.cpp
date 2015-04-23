#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 32000

bitset< MAXN+10 > bs;
vector< int > primes;

void sieve(){
	primes.clear();
	for (int i = 0; i <= MAXN; ++i) bs[i] = i&1;
	primes.push_back(2);
	for (int i = 3; i < MAXN; i+=2) if (bs[i]) {
		primes.push_back(i);
        for (int j = i*i; j <= MAXN; j+=i) bs[j] = false;
	}
}

int64 sigma(int n){
	int64 ans = 1LL;
	
	for (int i = 0; primes[i] * primes[i] <= n; ++i) {	
		if (n % primes[i] == 0) {
			int v = primes[i];
			
			while (n % primes[i] == 0) {
				v *= primes[i];
				n /= primes[i]; 
			}
			
			ans *= int64((v - 1) / (primes[i] - 1));
		}
	}
	
	if (n > 1) { 
        ans *= int64(n + 1);
    }
    
	return ans;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    sieve();
    
    int T;
    cin >> T;
    
    while (T--) {
        int n; cin >> n;
        cout << sigma(n) << "\n";
    }

	return 0;
}

















