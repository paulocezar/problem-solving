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

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k, L, W;
        cin >> n >> k >> L >> W;
        
        if (n == 1) { cout << "0\n"; continue; }
        if (n == 2) { cout << min(L,W) << "\n"; continue; }
        
        int res = 2e9;    
        int routers = 0;
        
        while (true) {
            
            int cur = 2e9;
            int out = max(0, n - routers*k);
            int cable = routers*k - max(routers-1,0)*2;
            
            if (out <= cable)
                cur = routers*W + (out+max(0,routers-1))*L;
            
            
            res = min(res, cur);
            if (routers*k >= n) break;
            routers++;
        }

        cout << res << "\n";
    
    }
	 
	return 0;
}

















