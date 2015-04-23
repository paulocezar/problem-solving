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

const int mod = 1000000007;
int ways[1000001];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    ways[0] = 1, ways[1] = 1;
    FOR(i,2,1000000) {
        ways[i] = (ways[i-1] + ways[i-2]);
        if (ways[i] >= mod) ways[i] -= mod;
    }
    FOR(i,0,1000000) ways[i] = __builtin_popcount(ways[i]);
    
    int t, n, g;
    cin >> t;
    while (t--) {
        cin >> n >> g;
        cout << ((ways[n]==g)?"CORRECT":"INCORRECT") << "\n";
    }

	return 0;
}

















