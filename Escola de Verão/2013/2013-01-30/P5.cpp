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

typedef unsigned long long hash;

hash B = 33ULL;
hash h[100001];
hash pw[100001];

inline hash V(char c) { return hash(c-'A'); }
inline hash geth(int a, int b) { return h[b+1] - h[a]*pw[b-a+1]; }


void read(char *s, int &sz) {
	sz = 0;
	char c = getchar_unlocked();
	while (!('A' <= c && c <= 'Z'))  c = getchar_unlocked(); 
    while ('A' <= c && c <= 'Z') {
		s[sz++] = c;
		c = getchar_unlocked();
	}
}

char s[100001]; int sz;
char c1[101]; int c1sz;
char c2[101]; int c2sz;

int main(){
	pw[0] = 1ULL;
	for (int i = 1; i <= 100000; ++i) pw[i] = pw[i-1] * B;
	
	int K = next_int();
	while (K) {
        read(s,sz);
        read(c1,c1sz);
        read(c2,c2sz);
        
          
        
        K = next_int();
	}

    return 0;
}


