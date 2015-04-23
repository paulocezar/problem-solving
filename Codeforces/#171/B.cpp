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

#define MAXN 100000
int64 a[MAXN+1];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n; int64 t;
    cin >> n >> t;
    
    a[0] = 0;
    FOR(i,1,n) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    
    int res = 0;
    FOR(i, 1, n) {
        int pos = upper_bound(a+i,a+n+1,a[i-1]+t) - a;
        res = max(res, pos-i);
        
    }
    cout << res << "\n";
    
	return 0;
}

















