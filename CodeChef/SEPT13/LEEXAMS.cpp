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

int a[50], b[50], p[50];
int last_cached[50][1<<16], cached_now, n;
double pp[50], cache[50][1<<16];

double solve(int pos, int mask) {
    if (pos == n) return 1.0;
    double &res = cache[pos][mask];
    if (last_cached[pos][mask] == cached_now) return res;
    last_cached[pos][mask] = cached_now;
    res = 0.0;
    if (!(mask & a[pos]) && p[pos])
            res += pp[pos] * solve(pos+1, mask | a[pos]);
    if (!(mask & b[pos]) && p[pos] != 100)
            res += (1.0 - pp[pos]) * solve(pos+1, mask | b[pos]);
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    cout << fixed << setprecision(13); 
    int tc;
    cin >> tc;
    while (tc--) {
      cin >> n;  
      REP(i, n) {
        cin >> p[i] >> a[i] >> b[i];
        pp[i] = p[i] / 100.0;
        a[i] = 1<<(a[i]-1);
        b[i] = 1<<(b[i]-1);
      }
      cached_now++;
      cout << solve(0, 0) << "\n";
    }
    
	return 0;
}

















