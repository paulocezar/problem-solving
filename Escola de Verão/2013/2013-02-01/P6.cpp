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

#define MAXN 100010

int n;
int a[MAXN];
int mx[MAXN];
int mn[MAXN];
int mxvl, mnvl;

const int64 mod = 1000000007LL;
const int64 inv2 = 500000004LL;

int64 cache[4][MAXN];
int calc[4][MAXN], calc_now;

int64 solve(int got, int pos) {
	if (pos == (n+1)) return ((got == 3)?1LL:0LL);
	
	int64 &res = cache[got][pos];
	if (calc[got][pos] == calc_now) return res;
	calc[got][pos] = calc_now;
	
	res = solve(got, pos+1);
	
	if (mxvl == a[pos]) got |= 1;
	if (mnvl == a[pos]) got |= 2;
	
	res += solve(got, pos+1);
	if (res >= mod) res = mod;
	return res;
}

int64 fstpw(int64 a, int b) {
	int64 res = 1;
	while (b > 0) {
		if (b & 1) { res *= a; res %= mod; }
		a *= a; a %= mod;
		b >>= 1;
	}
	return res;
}


int main(){
    ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		mxvl = -1, mnvl = 2e9;
		FOR(i, 1, n) {
			cin >> a[i];
			mxvl = max(mxvl, a[i]);
			mnvl = min(mnvl, a[i]);
		}
		
		if (mxvl == mnvl) {
			int64 sstr = (((int64(n) * int64(n+1))%mod)*inv2)%mod;
			int64 sseq = fstpw(2,n);
			cout << sstr << " " << sseq << "\n";
		} else {
			int64 sstr = 0LL;

			mx[0] = 0;
			mn[0] = 0;
	
			FOR(i, 1, n) {
				mx[i] = mx[i-1];
				mn[i] = mn[i-1];
				if (a[i] == mnvl) mn[i]++;
				if (a[i] == mxvl) mx[i]++;
			}

			FOR(beg,1, n) {
				int lo = beg+1, hi = n;
				int ans = n+1;
				while (lo <= hi) {
					int mid = (lo+hi)>>1;
					int hasmx = mx[mid]-mx[beg-1];
					int hasmn = mn[mid]-mn[beg-1];
					if (hasmx && hasmn) {
						ans = mid;
						hi = mid-1;
					} else {
						lo = mid+1;
					}
				}
				sstr += (n-ans+1LL);
				if (sstr >= mod) sstr -= mod;
			}

			calc_now++;
			int64 sseq = solve(0,1);
			cout << sstr << " " << sseq << "\n";
		}

	}

    return 0;
}
