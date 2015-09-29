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

bool is_palin(int64 x) {
    int64 ax = x, ix = 0LL;
    while (ax) {
        ix = 10LL*ix + (ax%10LL);
        ax /= 10LL;
    }
    return (x == ix);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    vector<int64> sqpal;
    
    FOR(half,1,9999) {
        
        int64 whole = half;
        int64 ah = half, ih = 0LL;
        while (ah) {
            ih = 10LL*ih + (ah%10LL);
            ah /= 10LL;
            whole *= 10LL;
        }
        whole += ih;
        int64 square = whole * whole;
        if (is_palin(square)) sqpal.PB(square);
        
        whole = half;
        ah = half/10LL, ih = 0LL;
        while (ah) {
            ih = 10LL*ih + (ah%10LL);
            ah /= 10LL;
            whole *= 10LL;
        }
        whole += ih;
        square = whole * whole;
        if (is_palin(square)) sqpal.PB(square);
    }
    sort(ALL(sqpal));
    
    
    int cases;
    cin >> cases;
    FOR(kase,1,cases) {
        int64 A, B;
        cin >> A >> B;
        int res = upper_bound(ALL(sqpal),B) - upper_bound(ALL(sqpal),A-1LL);
        cout << "Case #" << kase << ": " << res << "\n"; 
        
    }
    
    return 0;
}

















