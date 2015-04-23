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

#define MAXM 101010
int w[MAXM];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    
    REP(i, m) {
        int a;
        cin >> a >> w[i];
    }
    
    sort(w, w+m);
    
    int lo = 1, hi = m/2;
    int odd = 0, even = 0;
    
    while (lo <= hi) {    
        int mid = (lo+hi) / 2;
        
        int val = mid*2;
        
        int64 need = (val / 2LL) * (val-1LL) + mid;
        if (need <= n) {
            even = val;
            lo = mid+1;
        } else hi = mid-1;   
    }
    
    lo = 1, hi = (m+1)/2;
    while (lo <= hi) {    
        int mid = (lo+hi) / 2;
        
        int val = 2*mid - 1;
        
        int64 need = val * ((val-1LL)/2LL) + 1LL;
        
        if (need <= n) {
            odd = val;
            lo = mid+1;
        } else hi = mid-1;   
    }
    
    int res = max(odd, even);
    int64 ans = 0LL;
    REP(i, res)  {
        ans += w[m-i-1];
    }
    cout << ans << "\n";
    

	return 0;
}

















