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

inline bool isok(char c) { return ('a' <= c && c <= 'z'); }

#define MAXN 100000

struct state_t {
	int len, link, nxt, best, curbest;
};

int sz, last;
state_t state[2*MAXN];

#define MAXC 26
int next[2*MAXN][MAXC];

void automata_init() {
	sz = last = 0;
	state[0].len = 0;
	state[0].link = -1;
    state[0].nxt = -1;
    state[0].best = 0;
    state[0].curbest = 0;
    ++sz;
}

void automata_extend(int c) {
	int cur = sz++;
	state[cur].len = state[last].len+1;
	state[cur].best = state[cur].len;
	state[cur].curbest = 0;
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

			state[clone].best = state[clone].len;
            state[clone].curbest = 0;
            
			state[clone].nxt = -1;
			memcpy(next[clone], next[q], sizeof(int)*26);			
            
            state[clone].link = state[q].link;

			for (; p != -1 && next[p][c]==q; p=state[p].link) {
				next[p][c] = clone;
			}
            state[q].link = state[cur].link = clone;
		}
	}
	last = cur;
}


int first[MAXN+1];
char str[MAXN+10];

int main(int argc, char* argv[]) {
	
	scanf("%s", str);
    int n = strlen(str);
    
    automata_init();
    REP(i,n) {
        first[i] = -1;
        automata_extend(str[i]-'a');
    }
    first[n] = -1;
    
    for (int v = 0; v < sz; ++v) {
        state[v].nxt = first[state[v].len];
        first[state[v].len] = v;
    }
    bool fl = false;
    while (scanf("%s", str) != EOF) {
        
        int n2 = strlen(str);
        int cur = 0;
        
        int cur_state = 0;
        int cur_len = 0;
        
        while (cur < n2) {
            
            while (cur_state && !next[cur_state][str[cur]-'a']) {
                cur_state = state[cur_state].link;
                cur_len = state[cur_state].len;
            }
            
            if (next[cur_state][str[cur]-'a']) {
                cur_state = next[cur_state][str[cur]-'a'];
                cur_len++;
            }
            
            if (cur_len > state[cur_state].curbest) {
                state[cur_state].curbest = cur_len;
            }
            
            ++cur;
        }
        
    
        for (int i = n; i >= 0; --i) {
            for (int u = first[i]; u != -1; u = state[u].nxt) {
                state[u].best = min(state[u].best, state[u].curbest);
                if (state[u].link != -1)
                    state[ state[u].link ].curbest = max(state[ state[u].link ].curbest, state[u].curbest);
                state[u].curbest = 0;
            }
        }        
        fl = true;
    }
	
    int res = 0;
    if (fl) REP(i,sz) res = max(res,state[i].best);
    printf("%d\n", res);
    
    
    
	return 0;
}

















