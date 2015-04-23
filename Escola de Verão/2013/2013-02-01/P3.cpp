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

using namespace std;

typedef unsigned long long hash;
typedef long long int64;

inline int next_int() {
	int res = 0;
	char c = getchar_unlocked();
	while (!isdigit(c)) c = getchar_unlocked();
	while (isdigit(c)) {
		res = 10*res + (c-'0');
		c = getchar_unlocked();
	}	
	return res;
}

void reads(char* s, int &sz) {
	sz = 0;
	char c = getchar_unlocked();
	while (!('a' <= c && c <= 'z')) c = getchar_unlocked();
	while ('a' <= c && c <= 'z') {
		s[sz++] = c;
		c = getchar_unlocked();
	}
}

const hash BASE = 71ULL;
inline hash V(char c) {
    if ('a' <= c && c <= 'z') return hash(c-'a');
    return hash(c-'A'+26);
}

hash h[2][100001];
hash pw[100001];

inline hash geth(int i, int a, int b) {
	return h[i][b+1] - h[i][a]*pw[b-a+1];	
}

char s[2][100001]; int sz[2];
int ai, af, at, bi, bf, bt;

bool calc_lcp() {
	int lo = 1, hi = min(at-af+1, bt-bf+1);
	int ans = 0;
	while (lo <= hi) {
		int mid = (lo+hi)>>1;
		if (geth(ai,af,af+mid-1) == geth(bi,bf,bf+mid-1)) {
			ans = mid;
			lo = mid+1;
		} else hi = mid-1;
	}
	return ans;
}

bool comp_str() {
	int slcp = calc_lcp();
	int lena = at-af+1;
	int lenb = bt-bf+1;
	int mxlen = min(lena,lenb);
	if (slcp == mxlen) return lena < lenb;
	return s[ai][af+slcp] < s[bi][bf+slcp];
}

bool comp(int a, int b) {
    ai = 0, af = a, at = sz[0]-1, bi = 0, bf = b, bt=sz[0]-1;
	return comp_str();
}

int sa[100001];

int main(){
	pw[0] = 1ULL;
	FOR(i, 1, 100000) pw[i] = pw[i-1]*BASE;
	int t = next_int();
	while (t--) {
		reads(s[0], sz[0]);
		h[0][0] = 0ULL;
		REP(i, sz[0]) h[0][i+1] = h[0][i]*BASE + V(s[0][i]);
	
		reads(s[1], sz[1]);
		h[1][0] = 0ULL;
		REP(i, sz[1]) h[1][i+1] = h[1][i]*BASE + V(s[1][i]);

		REP(i, sz[0]) sa[i] = i;
		sort(sa,sa+sz[0],comp);

		int64 res = 0;
		
		int from = 0, to = 0;
		while (from < sz[0] && s[0][sa[from]] < s[1][0]) from++;
		to = from;
		while (to < sz[0] && s[0][sa[to]] == s[1][0]) to++;
		to--;
		
		FOR(len, 1, sz[1]-1) {
			
			while (from <= to) {
			    if (sz[0]-sa[from] < len) from++;
			    else if (geth(0,sa[from],sa[from]+len-1) != geth(1,0,len-1)) from++;
			    else if (sz[0]-sa[to] < len) to--;
			    else if (geth(0,sa[to],sa[to]+len-1) != geth(1,0,len-1)) to--;
			    else break;    
			}		
			if (from > to) break;

			int lo, hi;
			int sfrom, sto;
			lo = 0, hi = sz[0]-1;
			sfrom = -1;
			while (lo <= hi) {
				int mid = (lo+hi)>>1;
				int alen = min(sz[0]-sa[mid], sz[1]-len);
				ai = 0, af = sa[mid], at = sa[mid]+alen-1, bi = 1, bf = len, bt = sz[1]-1;
				if (comp_str()) {
					lo = mid+1;
				} else {
				    if (alen == (sz[1]-len)) {
					    if (geth(0,sa[mid],sa[mid]+alen-1) == geth(1,len,sz[1]-1)) {
					    	sfrom = mid;
					    }
					}
					hi = mid-1;
				}
			}
			if (sfrom == -1) continue;
			lo = sfrom, hi = sz[0]-1;
			sto = sfrom;
			while (lo <= hi) {
				int mid = (lo+hi)>>1;
				int alen = min(sz[0]-sa[mid], sz[1]-len);
				ai = 0, af = sa[mid], at = sa[mid]+alen-1, bi = 1, bf = len, bt = sz[1]-1;
				if (comp_str()) {
					lo = mid+1;
				} else {
				    int lena = min(sz[1]-len, sz[0]-sa[mid]);
				    if (lena == (sz[1]-len)) {
					    if (geth(0,sa[mid],sa[mid]+alen-1) == geth(1,len,sz[1]-1)) {
					    	sto = mid;
					    	lo = mid+1;
					    } else hi = mid-1;
					} else hi = mid-1;
				}
			}
			res += int64(to-from+1)*int64(sto-sfrom+1);
			
		}
		printf("%lld\n", res);
	}
    return 0;
}


