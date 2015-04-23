#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = a.begin(); i != a.end(); i++)

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR(const T &a) { return a*a; }
template<typename T> T inline ABS(const T &a) { return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN(double a){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP(double a, double b){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 250000

struct state_t {
	int len, link, cnt, nxt;
};

int next[2*MAXN][26];

inline bool isalph(char c) { return ('a' <= c && c <= 'z'); }

int sz, last;
state_t state[2*MAXN];

void automata_init() {
	sz = last = 0;
	state[0].len = 0;
	state[0].link = -1;
    state[0].cnt = 0;
    state[0].nxt = -1;
	++sz;
}

void automata_extend(int c) {
	int cur = sz++;
	state[cur].len = state[last].len+1;
    state[cur].cnt = 1;
    state[cur].nxt = -1;
    
    int p = last;
    
	for (; p != -1 && !next[p][c]; p = state[p].link) {
		next[p][c] = cur;
    }
    
	if (p == -1) {
        state[cur].link = 0;
	} else {
		int q = next[p][c];
		if (state[p].len+1 == state[q].len) {
            state[cur].link = q;
		} else {
			int clone = sz++;
			state[clone].len = state[p].len+1;
			memcpy(next[clone], next[q], sizeof(int)*26);
            state[clone].link = state[q].link;
            
            state[clone].cnt = 0;
            state[cur].nxt = -1;
    

			for (; p != -1 && next[p][c]==q; p=state[p].link) {
				next[p][c] = clone;
			}
            state[q].link = state[cur].link = clone;
		}
	}
	last = cur;
}

int lcnt[MAXN+1];
int q[2*MAXN];
int F[MAXN+1];

int main(int argc, char* argv[]) {
	
	char c = getchar_unlocked();
    while (!isalph(c)) c = getchar_unlocked();
    
    int n = 0;
    automata_init();
    
    while (isalph(c)) {
        automata_extend(c-'a');
        n++;
        c = getchar_unlocked();
    }
	    
    for (int v = 0; v < sz; ++v) lcnt[ state[v].len ]++;
    for (int i = 1; i <= n; ++i) lcnt[i] += lcnt[i-1];
    for (int v = 0; v < sz; ++v) q[ --lcnt[state[v].len] ] = v;
    
    for (int i = sz-1; i >= 0; --i) if (state[ q[i] ].link != -1)
        state[ state[q[i]].link ].cnt += state[ q[i] ].cnt;
    
    for(int i = 0; i < sz; ++i)
        F[state[i].len] = max(F[state[i].len], state[i].cnt);
    
    for (int i = n; i > 1; --i) F[i-1] = max(F[i], F[i-1]);
    for (int i = 1; i <= n; ++i) printf("%d\n", F[i]);
    	
	return 0;
}

















