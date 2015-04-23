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
#include <tr1/unordered_map>

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) FOR(i, 0, N-1)
#define RREP(i, N) RFOR(i, N-1, 0)

#define PB push_back
#define MP make_pair

#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3fffffffffll

using namespace std;

typedef unsigned long long hash;

inline hash V(char c) { return hash(c-'a'); }

hash B = 33ULL;
hash h[10][10010];
hash pw[10010];
int sz[10010];

int n;

hash geth(int s, int a, int b) {
	return h[s][b+1] - h[s][a]*pw[b-a+1];
}

bool check(int len) {
	tr1::unordered_map<hash, int> lastseen;
	REP(ss, n) {
		bool fl = false;
		for (int i = 0; i+len <= sz[ss]; ++i) {
			if (lastseen[geth(ss, i, i+len-1)] == ss) {
				lastseen[geth(ss, i, i+len-1)] = ss+1;
				fl = true;
				if (ss+1 == n) {
					return true;
				}
			}
		}
		if (!fl) return false;
	}
	return false;
}

char s[10010];
int next_int() {
	int res = 0;
	char c = getchar_unlocked();
	while (!isdigit(c)) c = getchar_unlocked();
	while (isdigit(c)) {
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}
	return res;
}

void read(int idx) {
	sz[idx] = 0;
	char c = getchar_unlocked();
	while (!('a' <= c && c <= 'z')) c = getchar_unlocked();
	while ('a' <= c && c <= 'z') {
		s[sz[idx]++] = c;
		c = getchar_unlocked();
	}
}

int main(){
	pw[0] = 1ULL;
	for (int i = 1; i <= 10000; ++i) pw[i] = pw[i-1] * B;
	
	int t = next_int();
	
	while (t--) {
		n = next_int();
		int lo = 1, hi = 10000;
		REP(ss, n) {
			read(ss);
			
			hi = min(hi, sz[ss]);
			h[ss][0] = 0ULL;
			REP(i, sz[ss]) {
				h[ss][i+1] = h[ss][i]*B + V(s[i]);
			}
		}
		
		int ans = 0;
		while (lo <= hi) {
			int mid = (lo+hi) >> 1;
			if (check(mid)) {
				ans = mid;
				lo = mid+1;
			} else hi = mid-1;
		}
		printf("%d\n", ans);
	}

    return 0;
}


