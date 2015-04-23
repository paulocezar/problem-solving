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

#define MAXN (1<<18)
int64 a[MAXN];

char  state[2][MAXN];
bool cycled[2][MAXN];
bool   addi[2][MAXN];
int64   add[2][MAXN];

int n;

void doit(int decr, int u) {
    state[decr][u] = 1;
    int nu;
    
    if (decr) nu = u - a[u];
    else nu = u + a[u];        
    
    if ((1 <= nu) && (nu <= n)) {
        switch (state[1-decr][nu]) {
            case 0:
                doit(1-decr,nu);
                cycled[decr][u] = cycled[1-decr][nu];
                addi[decr][u] = addi[1-decr][nu];
                add[decr][u] = add[1-decr][nu] + a[u];
            break;
            case 1:
                cycled[decr][u] = true;
            break;
            case 2:
                if (cycled[1-decr][nu]) {
                    cycled[decr][u] = true;
                } else {
                    addi[decr][u] = addi[1-decr][nu];
                    add[decr][u] = add[1-decr][nu] + a[u];
                }
            break;
        }
    } else add[decr][u] = a[u];
    
    state[decr][u] = 2;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    cin >> n;
    
    cycled[0][1] = true;
    state[0][1] = 2;
    
    cycled[1][1] = false;
     state[1][1] = 2;
      addi[1][1] = true;
       add[1][1] = 0LL;
    
    FOR(i,2,n) {
        cin >> a[i];
        state[0][i] = state[1][i] = 0;
        cycled[0][i] = cycled[1][i] = false;
        addi[0][i] = addi[1][i] = false;
        add[0][i] = add[1][i] = 0LL;
    }
        
    FOR(i,2,n) {
        if (!state[1][i]) doit(1,i);
    }
    
    FOR(i,1,n-1) {
        if (cycled[1][i+1]) cout << "-1\n";
        else cout << (int64(i) + add[1][i+1] + (addi[1][i+1]?int64(i):0LL)) << "\n";
    }
    
	return 0;
}

















