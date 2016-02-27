#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXVAL 1800000
#define SQMV 1342

bitset< MAXVAL+1 > bs;
int a[18];

void sieve() {
    for (int i = 1; i <= MAXVAL; ++i) bs[i] = (i&1);
    bs[1] = false;
    bs[2] = true;
    for (int i = 3; i <= SQMV; i += 2) if (bs[i]) {
        for (int j = i*i; j <= MAXVAL; j += i) bs[j] = false;
    }
}

unordered_set<int> primes;
void gen(int pos, int val = 0) {
    if (pos < 0) {
        if (bs[val]) primes.insert(val);
        return;
    }
    gen(pos-1, val);
    gen(pos-1, val+a[pos]);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];

    sieve();
    gen(N-1);
    
    cout << primes.size() << "\n";

	return 0;
}
