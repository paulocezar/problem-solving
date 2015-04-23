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



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    map< int, vector<string> > candidates;
    int a[3];
    
    int lo = 2, hi = 5;
    for (a[0] = lo; a[0] <= hi; a[0]++) {
        for (a[1] = a[0]; a[1] <= hi; a[1]++) {
            for (a[2] = a[1]; a[2] <= hi; a[2]++) {
                
                ostringstream out;
                out << a[0] << a[1] << a[2];
                string guess = out.str();
                
                REP(mask,(1<<3)) {
                    int res = 1;
                    REP(i, 3) if (mask & (1<<i)) res *= a[i];
                    candidates[res].PB(guess);
                }
            }
        }
    }
    
    FORIT(x,candidates) {
        sort(ALL(x->second));
        (x->second).resize(unique(ALL(x->second)) - (x->second).begin());
    }
    
    int t; cin >> t;
    cout << "Case #1:\n";
    int R, N, M, K;
    cin >> R >> N >> M >> K;
    while (R--) {
        int x; cin >> x;
        vector<string> ans = candidates[x];
        
        
        vector<string> res(100);
        REP(i, K-1) {
            cin >> x;
            
            set_intersection(ALL(ans), ALL(candidates[x]), res.begin());
            ans = res;
        }
        
        cout << ans[0] << "\n";
        
        
    }
    
	return 0;
}

















