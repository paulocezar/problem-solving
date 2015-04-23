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

typedef long long int64;
typedef unsigned long long uint64;

uint64 solve(uint64 n) {
	if (n == 1) return 1;
	if (n & 1) return max(n, solve(3*n + 1));
	return max(n, solve(n/2));
}

int main(){
    ios::sync_with_stdio(false);
	int t;
	cin >> t;

	while (t--) {
		int ds, n;
		cin >> ds >> n;
		cout << ds << " " << solve(n) << "\n";
	}
    return 0;
}
