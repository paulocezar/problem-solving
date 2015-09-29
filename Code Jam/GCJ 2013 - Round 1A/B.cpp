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
#include <tr1/unordered_map>
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

#define MAXN 10

int E, R, N;
int v[MAXN];

map< int, map<int, int> > cache;

int solve(int curE, int pos) {
    
    if (pos == N) return 0;
    if (cache[curE].count(pos)) return cache[curE][pos];
    
    int &res = cache[curE][pos];
    
    REP(xpnd,curE+1) {
        res = max(res, xpnd*v[pos] + solve(min(E,curE-xpnd+R),pos+1));
    }
    
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int kases;
    cin >> kases;
    FOR(kase,1,kases) {
        cin >> E >> R >> N;
        REP(i, N) cin >> v[i];
        cache.clear();
        cout << "Case #" << kase << ": " << solve(E,0) << "\n";
    }
    
    
	return 0;
}

















