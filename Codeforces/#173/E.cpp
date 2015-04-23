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

#define MAXN 100000
int64 a[MAXN+10];

struct node_t {
    node_t* chld[2];
    int cnt[2];
    node_t() {
        chld[0] = chld[1] = NULL;
        cnt[0] = cnt[1] = 0;
    }
};

void add(int64 x, node_t *rt) {
    RREP(bit,41) {
        int v = (x>>bit) & 1LL;
        if (rt->chld[v] == NULL) rt->chld[v] = new node_t();
        rt->cnt[v]++;
        rt = rt->chld[v];
    }
}

void rem(int64 x, node_t *rt) {
    RREP(bit,41) {
        int v = (x>>bit) & 1LL;
        rt->cnt[v]--;
        rt = rt->chld[v];
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    a[0] = 0LL;
    FOR(i,1,n) cin >> a[i];
    
    int64 xr = 0LL;
    node_t* trie = new node_t();
    add(xr,trie);
    
    int64 res = 0LL;

    RFOR(i,n,1) {
        xr ^= a[i];
        res = max(res, xr);
        add(xr,trie);
    } 

    int64 cur = 0;
    FOR(i,1,n) {
       rem(xr,trie);
       cur ^= a[i];
       xr ^= a[i];
       int64 get = 0LL;
       node_t *rt = trie;
       RREP(bit,41) {
        int v = (cur>>bit) & 1LL;
        if (rt->cnt[1-v]) {
            get |= (1LL<<bit);
            rt = rt->chld[1-v];
        } else {
            rt = rt->chld[v];
        }
       }
       res = max(res,get);
    }

    cout << res << "\n";
	return 0;
}

















