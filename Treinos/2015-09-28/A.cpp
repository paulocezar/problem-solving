#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int64 fpw(int64 a, int b, int64 mod) {
	int64 res = 1LL; a %= mod;
	while (b) {
		if (b & 1) res = (a * res) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int64 a, b, p;
    while (cin >> a >> b >> p) {
    	a %= p;
    	b = fpw(b, p-2, p);
    	a *= b; a %= p;
    	cout << a << "\n";
    }
    

	return 0;
}

















