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

#define MAXN 1000100
uint64 p[MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    uint64 n;
    cin >> n;
    
    tr1::unordered_set<uint64> used;

    uint64 hg = 1ULL;
    while ((hg<<1) <= n) hg <<= 1;
    
    uint64 bits = (hg<<1) - 1ULL;
    uint64 res = 0ULL;
    
    
    for (uint64 ii = 0; ii <= n; ++ii) {
        uint64 inv = (~ii) & bits; 
        
        uint64 hh = hg;
        while (inv > n || used.count(inv)) {
            inv = inv & (~hh);
            hh >>= 1;
        }
        
        used.insert(inv);
        p[ii] = inv;
        res += (ii ^ inv);
    }
    
    cout << res << "\n";
    REP(i, int(n)+1) {
        if (i) cout << " ";
        cout << p[i];
    }
    cout << "\n";
    
        
	return 0;
}

















