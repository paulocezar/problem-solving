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
#include <tr1/unordered_set>

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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;
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

tr1::unordered_set<uint64> dict;

int r, c, dim;

int seen[1<<16], seen_now;
bool cache[1<<16];

int ds[16], ii[16], jj[16];
uint64 grid[16];

bool win(int mask) {
    bool &res = cache[mask];
    if (seen[mask] == seen_now) return res;
    seen[mask] = seen_now;
    res = false;
    for (int sub = mask; sub > 0; sub = (sub-1) & mask) {
        uint64 wrd = 5381ULL;

        REP(i, dim) if (sub & (1<<i)) 
            wrd = 33ULL*wrd + grid[i];

        if (dict.count(wrd)) {
            res = res || !win(mask ^ sub);
            if (res) break;
        }
    }
    return res;
}

int cnt[26];
int main(int argc, char* argv[]) {
	
    int d = next_int();
    REP(i, d) {
        uint64 s = 5381ULL;
        char c = getchar_unlocked();
        while (!('A' <= c && c <= 'Z')) c = getchar_unlocked();
        while ('A' <= c && c <= 'Z') {
            cnt[c-'A']++;
            c = getchar_unlocked();
        }
        REP(i,26) while (cnt[i]) {
            s = 33ULL*s + uint64(i);
            cnt[i]--;
        }
        dict.insert(s);
    }
    
    r = next_int(); c = next_int();
    dim = r*c;

    int all = (1<<dim)-1;
    
    int T = next_int();
    REP(tc, T) {
        REP(i, dim) {
            c = getchar_unlocked();
            while (!('A' <= c && c <= 'Z')) c = getchar_unlocked();
            cnt[c-'A']++;
        }
        int ii = 0;
        REP(i,26) {
            while (cnt[i]) { grid[ii++] = uint64(i); cnt[i]--; }
        }

        seen_now++;
        if (win(all)) puts("Alice");
        else puts("Bob");
    }

	return 0;
}

















