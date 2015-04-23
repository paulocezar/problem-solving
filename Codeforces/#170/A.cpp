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

#define MAXN 100
vector<int> knows[MAXN];

int pa[MAXN], rk[MAXN];
int find(int x) {
    int ax, px = x;
    while (px != pa[px]) px = pa[px];
    while (x != px) {
        ax = pa[x];
        pa[x] = px;
        x = ax;
    }
    return px;
}

bool fUnion(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (rk[x] < rk[y]) swap(x,y);
    pa[y] = x;
    if (rk[x] == rk[y]) rk[x]++;
    return true;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    int someone = 0;
    
    REP(i, n) {
        pa[i] = i, rk[i] = 0;
        int k; cin >> k;
        while (k--) {
            int l; cin >> l;
            knows[i].PB(l);
            someone = 1;
        }
        sort(ALL(knows[i]));
    }
    
    int comp = n;
    REP(i, n) FOR(j,i+1,n-1) {
        REP(k, SIZE(knows[i])) {
            if (binary_search(ALL(knows[j]),knows[i][k])) {
                if (fUnion(i,j)) comp--;
                break;
            }
        }
    }

    cout << (comp-someone) << "\n";

	return 0;
}

















