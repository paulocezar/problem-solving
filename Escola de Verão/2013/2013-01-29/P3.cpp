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
int cnt[10];
int stotal, dtotal;
int seen[10][11][101], seen_now;
int cache[10][11][101];

int solve(int dig, int seven, int deven) {
	if (dig == 10) {
		int sodd = (stotal - seven + 11)%11;
		int dodd = dtotal - deven;
		int mod = (seven + 10*sodd) % 11;
		if (mod) return 2e9;
		if (dodd <= deven) {
			// might need xtra odds
			return max(0,deven-1-dodd);
		} else {
			// need xtra evens
			return dodd-deven;
		}
	}
	int &res = cache[dig][seven][deven];
	if (seen[dig][seven][deven] == seen_now) return res;
	seen[dig][seven][deven] = seen_now;

	res = 2e9;
	FOR(put,0,cnt[dig]) 
		res = min(res, solve(dig+1,(seven+put*dig)%11, deven+put));
	return res;
}

int main(){
    ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while (t--) {
		stotal = 0, dtotal = 0;
		FOR(i,1,9) {
			cin >> cnt[i];
			stotal = (stotal + cnt[i]*i)%11;
			dtotal += cnt[i];
		}
		seen_now++;
		int xtra = solve(1,0,0);
		if (xtra == 2e9) cout << "-1\n";
		else cout << (dtotal+xtra) << "\n";
	}
    return 0;
}
