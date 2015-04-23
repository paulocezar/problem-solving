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

#define MAXN 90000
#define MAXC 26
#define TRNS (MAXC*sizeof(int))

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

struct state_t {
    state_t *link, *next[MAXC];
    int len, ways;
} state[2*MAXN + 10], *init, *tail;

int v[2*MAXN + 10], p[2*MAXN + 10], sz; 

int trans[2*MAXN][MAXC+1];
char val[2*MAXN][MAXC+1];

void add_transition(int from, int with, int at) {
    state[from].ways += state[from].next[with]->ways;
    trans[from][at] = state[from].next[with] - state;
    val[from][at] = with + 'a';
}

void automata_init() {
    init = tail = state + (++sz);
    init->ways = 1, init->len = 0;
}

void automata_extend(int c) {
    state_t *q = state + (++sz), *p = tail;
    q->len = p->len + 1, q->ways = 1;
    for (;p && !p->next[c]; p = p->link) {
        p->next[c] = q;
    }
    tail = q;
    if (!p) {
        q->link = init;
    } else {
        if (p->next[c]->len == p->len+1) q->link = p->next[c];
        else {
            state_t *u = p->next[c], *r = state + (++sz);
            memcpy(r->next,u->next,TRNS);
            r->ways = 1, r->link = u->link;
            r->len = p->len + 1;
            q->link = u->link = r;
            for (; p && p->next[c] == u; p = p->link) p->next[c] = r;
        }
    }
}

char ans[MAXN+10];
void show(int at, int k) {
    int ll = 0;
    while (k) {
        for (int i = 0, tmp; trans[at][i]; ++i) {
            if (k > state[tmp = trans[at][i]].ways)
                k -= state[tmp].ways;
            else {
                ans[ll++] = val[at][i];
                at = tmp, --k;
                break;
            }
        }
    }
    ans[ll] = '\0';
    puts(ans);
}

int main(int argc, char* argv[]) {
	
	scanf("%s", ans+1);
    int n = strlen(ans+1);
    
    automata_init();
    
    for (int i = 1; i <= n; ++i) automata_extend(ans[i]-'a');
    
    for (int i = 1; i <= sz; ++i) ++v[ state[i].len ];
    for (int i = 1; i <= n; ++i) v[i] += v[i-1];
    for (int i = 1; i <= sz; ++i) p[ v[state[i].len]-- ] = i;
    
    for (int i = sz, j, now; i; --i) {
        for (now = j = 0; j < MAXC; ++j)
            if (state[p[i]].next[j]) 
                add_transition(p[i],j,now++);
        trans[p[i]][now] = 0;
    }
    
    int q, k;
    scanf("%d",&q);
    while (q--) {
        scanf("%d",&k);
        show(init-state,k);
    }
	
	return 0;
}

















