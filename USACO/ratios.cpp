/*
ID: knightp2
PROG: ratios
LANG: C++
*/
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
#include <fstream>
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

template<typename T> T inline SQR(const T &a) { return a*a; }
template<typename T> T inline ABS(const T &a) { return a < 0 ? -a : a; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main(int argc, char* argv[]) {
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    
    int desired[3];
    REP(i, 3) cin >> desired[i];
    
    int avail[3][3];
    REP(i, 3) REP(j, 3) cin >> avail[i][j];
    
    int res = 2e9;
    int use[3], get[3], ans[3], mult;
    
    for (use[0] = 0; use[0] < 100; ++use[0]) 
    for (use[1] = 0; use[1] < 100; ++use[1]) 
    for (use[2] = 0; use[2] < 100; ++use[2]) {
        int now = use[0] + use[1] + use[2];
        set<int> ft;
        for (int i = 0; i < 3; ++i) {
            get[i] = 0;
            for (int j = 0; j < 3; ++j) {
                get[i] += use[j] * avail[j][i];
            }
           
            if (desired[i]) {
                if (!get[i] || (get[i] % desired[i])) ft.insert(-i-1);
                else ft.insert(get[i]/desired[i]);
            } else {
                if (get[i]) ft.insert(-i-1);
            }
        }
        if (SIZE(ft) == 1) {
            if (res > now) {
                res = now;
                REP(i,3) ans[i] = use[i];
                mult = *ft.begin();
            }
        }
    }
    
    if (res != 2e9) {
        cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << mult << "\n";
    } else cout << "NONE\n";
    
    
        
	return 0;
}

















