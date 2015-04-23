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

int N, H;

int chng[100][100];
int ehop[100][1000];

int len, hop[1000];

int dp[100][1001];


/*int solve(int config, int pos) {    
    
    if (pos == len) return chng[config][0];
    
    int &res = mem[config][pos];
    if (calc[config][pos] == calc_now) return res;
    calc[config][pos] = calc_now;
    res = 2e9;
    
    FOR(nconf, 1, N-1) {
        res = min(res, chng[config][nconf] + ehop[nconf][hop[pos]] + solve(nconf, pos+1));
    }
    return res;
}

void show(int config, int pos) {    
    bool first = true;
    int res;
beg:
    if (pos == len) { cout << "\n"; return; }
    
    if (first) first = false;
    else cout << " ";
    
    res = solve(config, pos);
    
    FOR(nconf, 1, N-1) {
        if (res == (chng[config][nconf] + ehop[nconf][hop[pos]] + solve(nconf, pos+1))) {
            cout << nconf;
            config = nconf;
            pos++;
            goto beg;
        }
    }
    
}*/

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

inline bool next_seq() {
    char c = getchar_unlocked();
    int cur;
    while (!isdigit(c)) {
        if (c == EOF) return false;
        c = getchar_unlocked();
    }
    len = 0;
nxtone:    
    cur = 0;
    while (isdigit(c)) {
        cur = 10*cur + (c-'0');
        c = getchar_unlocked();
    }
    hop[len] = cur;
    len++;
    if (c == ' ') {
        c = getchar_unlocked();
        goto nxtone;
    }
    return true;
}

int main(int argc, char* argv[]) {
	
	N = next_int();
    H = next_int();
    
    REP(i, N) REP(j, N)
        chng[i][j] = next_int();
    REP(i,N) REP(j, H)
        ehop[i][j] = next_int();
    
    while (next_seq()) {
        
        REP(config, N) dp[config][len] = chng[config][0];
        dp[0][len] = 2e9;
    
        RREP(pos,len) {
            REP(config, N) {
                int &res = dp[config][pos];
                res = 2e9;
                if (pos && !config) continue;
                FOR(nconf, 1, N-1) {
                    res = min(res, chng[config][nconf] + ehop[nconf][hop[pos]] + dp[nconf][pos+1]);
                }
            }
        }
        printf("%d\n", dp[0][0]);
        
        int c = 0, p = 0;
        while (p < len) {
            if (p) printf(" ");
            FOR(nc, 1, N-1) {
                if (dp[c][p] == (chng[c][nc] + ehop[nc][hop[p]] + dp[nc][p+1])) {
                    c = nc;
                    printf("%d", c);
                    break;
                }
            }
            p++;
        }
        puts("");
    }
    
	 
	return 0;
}

















