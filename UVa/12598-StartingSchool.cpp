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

#define MAXK 50000
int a[MAXK+10];
int s[MAXK+10];
int u[MAXK+10];
int qq[MAXK+10];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int kases;
    cin >> kases;
    s[0] = 0;
    u[0] = 0;
    
    FOR(kase,1,kases) {
        int n, k, q;
        cin >> n >> k >> q;
        FOR(i,1,k) cin >> a[i];
        
        REP(i,q) cin >> qq[i];
        REP(i,k+1) s[i] = a[i];
        
        sort(s,s+k+1);
        s[k+1] = 1000000001;
        
        FOR(i,1,k+1) {
            u[i] = u[i-1];
            u[i] += s[i]-s[i-1]-1;
        }
        
        REP(i,q) {
            
            if (qq[i] <= k) qq[i] = a[qq[i]];
            else {
                
                int wntd = qq[i] - k;
                int pos = lower_bound(u,u+k+2,wntd) - u;
                qq[i] = s[pos-1] + (wntd - u[pos-1]);
                
            }
        }
        cout << "Case " << kase << ":\n";
        REP(i,q) cout << qq[i] << "\n";
    }
    
	return 0;
}

















