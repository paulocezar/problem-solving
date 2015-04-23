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

const int64 mod = 1000000007LL;



int64 cache[2][1014];
char seen[2][1024], seen_now;
int K;

int64 solve(int messi, int passes) {
    if (!passes) return messi;
    
    int64 &res = cache[messi][passes];
    if (seen[messi][passes] == seen_now) return res;
    seen[messi][passes] = seen_now;
    res = 0;
    
    if (messi) {
        res += (int64(K) * solve(0, passes-1)) % mod;
        if (res >= mod) res -= mod;
    } else {
        res += (int64(K-1) * solve(0, passes-1)) % mod;
        if (res >= mod) res -= mod;
        res += solve(1, passes-1);
        if (res >= mod) res -= mod;
    }
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        seen_now++;
        cout << solve(1,N) << "\n";
    }
    
	return 0;
}

















