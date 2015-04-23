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

#define FILL(X, V) memset((X), (V), sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = (a).begin(); i != (a).end(); ++i)

#define PB push_back
#define MP make_pair
    
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

const double EPS = 1e-9;
inline int SGN(double a) {
    return ((a > EPS)?(1):((a < -EPS)?(-1):(0)));
}
inline int CMP(double a, double b) {
    return SGN(a - b);
}

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1000000

struct state_t {
	int len, link, cnt, nxt;
};

#define MAXC 26
int next[2*MAXN][MAXC];

int sz, last;
state_t state[2*MAXN];

void automata_init() {
	sz = last = 0;
	state[0].len = 0;
	state[0].link = -1;
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
			memcpy(next[clone], next[q], sizeof(int)*MAXC);
			state[clone].link = state[q].link;
			state[clone].nxt = -1;
            
			for (; p != -1 && next[p][c]==q; p=state[p].link) {
				next[p][c] = clone;
			}
            state[q].link = state[cur].link = clone;
		}
	}
	last = cur;
}

int first[MAXN+1];

int period(string &s) {
	int n = SIZE(s);
    first[0] = first[1] = 0;
		
	for (int i = 1; i < n; ++i) {
		int j = first[i];
		while (s[i] != s[j]) {
            if (j == 0) { j = -1; break; }
            j = first[j];
        }
		first[i+1] = ++j;
	}
    
    int r = n / (n-first[n]);
    if (r*(n-first[n]) == n) return n-first[n];
    return n;
}


int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	
    string s;
    cin >> s;
    int n = SIZE(s);
    
    automata_init();
    REP(i,n) automata_extend(s[i]-'a');

    REP(i,n+1) first[i] = -1;
    
    for (int v = 0; v < sz; ++v) {
        state[v].nxt = first[state[v].len];
        first[state[v].len] = v;
    }

    for (int i = n; i >= 0; --i) {
        for (int u = first[i]; u != -1; u = state[u].nxt) {
            if (state[u].link != -1)
                state[ state[u].link ].cnt += state[u].cnt;
        }
    }
    state[0].cnt = 0;
    
    int q;
    cin >> q;
    while (q--) {
        cin >> s;
        
        int pr = period(s);
        int len = SIZE(s);
            
        int cur = 0;
        int t = 0;
        int cur_len = 0;
        
        while (cur < len) {
            while (t && !next[t][s[cur]-'a']) { 
                t = state[t].link;
                cur_len = state[t].len;
            }
        
            if (next[t][s[cur]-'a']) {
                t = next[t][s[cur]-'a'];
                cur_len++;
            }
            ++cur;
        }
        int res = 0;
        if (cur_len == len) res += state[t].cnt;
        
        cur = 1;
        while (cur < pr) {
            
            if (cur_len == len) {
                cur_len--;
                if (t && cur_len <= state[state[t].link].len) {
                    t = state[t].link;
                }
            }
            
            while (t && !next[t][s[cur-1]-'a']) { 
                t = state[t].link;
                cur_len = state[t].len;
            }
        
            if (next[t][s[cur-1]-'a']) {
                t = next[t][s[cur-1]-'a'];
                cur_len++;
            }
            ++cur;
        
            if (cur_len == len) res += state[t].cnt;
        }
        
        cout << res << "\n";        
    }
	
	return 0;

}
