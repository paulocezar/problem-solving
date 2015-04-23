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

#define MAXN 100000

int n;

int64 a, b, v[MAXN];
int c[MAXN], opa[MAXN+1];
int colors;
int64 segt[1<<18];

int64 go() {
    int64 res = 0;

    return res;
}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int q;
    cin >> n >> q;
    set<int> seen;
    vector<int> unq;

    REP(i, n) cin >> v[i];
    REP(i, n) {
        cin >> c[i];
        if (seen.insert(c[i]).second) unq.PB(c[i]);
    }
    REP(i, SIZE(unq)) opa[unq[i]] = i;
    REP(i, n) c[i] = opa[c[i]];
    colors = SIZE(unq)-1;
    
    while (q--) {
        cin >> a >> b;
        cout << go() << "\n";
    }

	 
	return 0;
}

















