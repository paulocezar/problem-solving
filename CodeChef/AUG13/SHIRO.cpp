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

int sum, a[128];
double p[128];

double cache[128][128*128];
int cached_now, cached[128][128*128];

double solve(int pos, int abra) {
    if (pos < 0) {
        int kadabra = sum - abra;
        if (abra >= kadabra) return 1.0;
        return 0.0;
    }
    double &ret = cache[pos][abra];
    if (cached[pos][abra] != cached_now) {
        ret = p[pos]*solve(pos-1,abra+a[pos]) +
                (1.0-p[pos])*solve(pos-1,abra);
        cached[pos][abra] = cached_now;
    }
    return ret;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    cout << fixed << setprecision(13);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        sum = 0;
        REP(i, n) {
            cin >> a[i];
            sum += a[i];
        }
        REP(i, n) {
            int pp; cin >> pp;
            p[i] = double(pp) / 100.0;
        }
        cached_now++;
        cout << solve(n-1, 0) << "\n";
    }
    
	return 0;
}

















