/*
ID: knightp2
PROG: necklace
LANG: C++
*/
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
#include <fstream>
#include <utility>
#include <iostream>
#include <algorithm>

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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

string a, b;
int N, M;

#define MAXM 1024
int p[MAXM];

void prefixfunction() {
    p[0] = p[1] = 0;
    FOR(i, 2, M) {
        int j = p[i-1];
        while (b[i-1] != b[j]) {
            if (j == 0) { j = -1; break; }
            j = p[j];
        }
        p[i] = ++j; 
    }
}

char cached[10000][1024];
int cache[10000][1024];

int next[26][1024];

int solve(int pos, int match) {
    if (pos == N) return 0;
    
    int &res = cache[pos][match];
    if (cached[pos][match]) return res;
    cached[pos][match] = 1;
    res = 1 + solve(pos+1, match);
    
    match = next[a[pos]][match];
    
    if (match != M) res = min(res, solve(pos+1, match));
    return res;
}


int main(int argc, char* argv[]) {
    freopen("necklace.in", "r", stdin);
    freopen("necklace.out", "w", stdout);
    
    cin >> a >> b;
    N = SIZE(a);
    M = SIZE(b);
    prefixfunction();
    REP(i,N) a[i] -= 'a';
    REP(i,M) b[i] -= 'a';
    
    REP(ltr,26) {
        REP(match,M+1) {
            int cmatch = match;
            while (ltr != b[cmatch]) {
                if (cmatch == 0) {
                    cmatch = -1;
                    break;
                }
                cmatch = p[cmatch];
            }
            next[ltr][match] = cmatch+1;
        }
    }
    
    cout << solve(0,0) << "\n";
	return 0;
}

















