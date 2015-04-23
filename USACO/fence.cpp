/*
ID: knightp2
PROG: fence
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

int edge[512][512];
int deg[512];
int last;
int pos;
int circuit[1024+10];

void recover(int u) {
    
    FOR(v,1,last) if (edge[u][v]) {
        edge[u][v]--;
        edge[v][u]--;
        recover(v);
    }
    circuit[pos++] = u;
}

int main(int argc, char* argv[]) {
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    
    int n;
    cin >> n;
    last = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        edge[x][y]++;
        edge[y][x]++;
        deg[x]++;
        deg[y]++;
        last = max(last, max(x,y));
    }
    
    int odd = 0;
    FOR(i,1,last) odd += (deg[i] & 1);

    if (odd == 0) {
        pos = 0;
        recover(1);
    } else if (odd == 2) {
        FOR(i,1,last) {
            if (deg[i] & 1) {
                pos = 0;
                recover(i);
                break;
            }
        }
    } else {
        return 1;
    }
    
    while (pos) cout << circuit[--pos] << "\n";
	return 0;
}

















