#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 2000000

bitset< MAXN+10 > bs;
vector< int > primes;
int acm[MAXN+10];

int divisors(int x, int sq) {
	int ndiv = 1;
	int cur;
	
	for (int i = 0; (x != 1) && (i < int(primes.size())) && (primes[i] <= sq); ++i) {
		if ((x % primes[i]) == 0) {
			cur = 0;
			while ((x % primes[i]) == 0) cur++, x /= primes[i];
			ndiv *= (cur+1);
		}
	}
	if (x != 1) ndiv *= 2;
	return ndiv;
}

void sieve(){
	primes.clear();
	for (int i = 0; i <= MAXN; ++i) { acm[i] = 0; bs[i] = i&1; }
	primes.push_back(2);
    acm[1] = 0; acm[2] = 1; acm[4] = 1;
    
    bool flg = true;
	for (int i = 3; i <= MAXN; ++i) {
        acm[i] += acm[i-1];
        if (bs[i]) {
		    acm[i]++;
            
            if (i*i > MAXN) flg = false;
            
            if (flg) {
                primes.push_back(i);
                for (int j = i*i; j <= MAXN; j+=i) bs[j] = false;
            }
        }
        if (flg) {
            if (i*i > MAXN) flg = false;
            else if (bs[divisors(i*i, i)]) acm[i*i]++;
        }
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    sieve();

    int N; 
    while (cin >> N) cout << acm[N] << "\n";

	return 0;
}

















