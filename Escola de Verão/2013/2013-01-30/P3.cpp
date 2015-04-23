#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <cfloat>
#include <sstream>
#include <utility>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <bitset>

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)

#define PB push_back
#define MP make_pair

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3fffffffffll

using namespace std;

bitset< 1000 > bs;
vector<int> primes;

void sieve() {
	FOR(i,1,1000) bs[i] = i&1;
	bs[1] = false;
	bs[2] = true;
	primes.push_back(2);
	for (int i = 3; i <= 1000; i+=2){
		if (bs[i]) {
			primes.push_back(i);
			for (int j = i*i; j <= 1000; j+=2*i) bs[j] = false;
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
	sieve();
	int t;
	cin >> t;
	while (t--) {
		int lo, hi;
		cin >> lo >> hi;
		bool first = true;
		while(lo <= hi) {
			
			int divs = 1;
			int xx = lo;
			for (int j = 0; primes[j]*primes[j] <= xx; j++) {
				int e = 0;
				while (xx % primes[j] == 0) {
					e++; xx /= primes[j];
				}
				divs *= (e+1);
			}
			if (xx != 1) divs *= 2;
			if (bs[divs]) {
				if (!first) cout << " ";
				cout << lo;
				first = false;
			}
			
			lo++;
		}
		if (first) cout << "-1";
		cout << "\n";
	}
    return 0;
}
