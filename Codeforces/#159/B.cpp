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

pair<int,int> get(int red, int blue) {
    int has[2] = {red-1, blue};
    int last = 0, eq = 0, dif = 0;
    int pos = 1;
    while (pos < (red + blue)) {
        if (pos & 1) {
            if (has[1-last]) {
                dif++;
                last = 1-last;
            } else {
                eq++;
            }
        } else {
            if (has[last]) {
                eq++;
            } else {
                dif++;
                last = 1-last;
            }
        }
        has[last]--;
        pos++;
    }
    return make_pair(eq, dif);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    pair<int,int> a = get(n,m);
    pair<int,int> b = get(m,n);
	pair<int,int> res = max(a, b);
    cout << res.first << " " << res.second << "\n";
    return 0;

}

















