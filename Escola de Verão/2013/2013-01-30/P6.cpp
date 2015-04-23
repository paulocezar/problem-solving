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
#include <tr1/unordered_set>

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)

#define PB push_back
#define MP make_pair

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3fffffffffll

using namespace std;

typedef long long int64;
int64 P;

vector<int> primes;
tr1::unordered_set<int> gg;

void gen(int pos, int val, int has) {
	if (primes[pos] > has) {
		gg.insert(val);
		return;
	}
	int64 vv = val;
	int add = 0;
	while (add <= has) {
		gen(pos+1, vv, has-add);
		vv *= int64(primes[pos]); if (vv >= P) vv %= P;
		add += primes[pos];
	}
}

int main(){
    ios::sync_with_stdio(false);
	
	bitset<77> bs;
	REP(i, 77) bs[i] = i&1;
	primes.PB(2);
	for (int i = 3; i <= 70; i+=2) {
		if (bs[i]) {
			primes.PB(i);
			for (int j = i*i; j <= 70; j+=2*i) bs[j] = false;
		}
	}
	primes.PB(77);
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N >> P;
		gg.clear();
		gen(0,1,N);
		cout << int(gg.size()) << "\n";
	}
    return 0;
}
