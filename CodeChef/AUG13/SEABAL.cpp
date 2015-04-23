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

#define MAXN 100001

int a[MAXN];
tr1::unordered_set<int> begin[MAXN], end[MAXN];

int main(int argc, char* argv[]) {

	ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    set<int> active;
    FOR(i,1,n) {
        active.insert(i);
        cin >> a[i];
    }
    
    REP(i, m) {
        int lo, hi;
        cin >> lo >> hi;
        begin[lo].insert(i);
        end[hi].insert(i);
    }

    int ans = 0;
    int k;
    cin >> k;
    while (k--) {
        int x; cin >> x;
        int y = x + ans;
        a[y]--;
        if (!a[y]) {
            int rgt = (active.upper_bound(y) == active.end())?(0):(*active.upper_bound(y));
            int lft = (active.lower_bound(y) == active.begin())?(0):(*(--active.lower_bound(y)));
            active.erase(y);
            
            tr1::unordered_set<int>::iterator interval;
            for (interval = begin[y].begin(); interval != begin[y].end();) {
                if (end[y].count(*interval)) {
                    ans++;
                    end[y].erase(*interval);
                    interval = begin[y].erase(interval);
                } else {
                    begin[rgt].insert(*interval);
                    interval = begin[y].erase(interval);
                }
            }
            
            for (interval = end[y].begin(); interval != end[y].end();) {
                end[lft].insert(*interval);
                interval = end[y].erase(interval);
            }
             
        }
        cout << ans << "\n";
    }

    
	return 0;
}

















