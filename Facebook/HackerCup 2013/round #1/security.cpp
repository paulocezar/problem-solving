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

#define MAXM 64

vector< int > gr[MAXM];

int m1[MAXM], m2[MAXM];
int seen[MAXM], seen_now;

int dfs(int u) {
    if (u < 0) return 1;
    if (seen[u] == seen_now) return 0;
    seen[u] = seen_now;
    for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
        if (dfs(m2[gr[u][i]])) {
            m1[u] = gr[u][i];
            m2[gr[u][i]] = u;
            return 1;
        }
    }
    return 0;
}

int dfsExp(int u) {
    seen_now++;
    return dfs(u);
}

int m;
int bipMatch() {
    for (int i = 0; i < m; ++i) m1[i] = -1;
    for (int i = 0; i < m; ++i) m2[i] = -1;
    int aug, ans = 0;
    do {
        aug = 0;
        bool first = true;
        for (int i = 0; i < m; ++i) if (m1[i] < 0) {
            if (first) aug += dfsExp(i);
            else aug += dfs(i);
            first = false;
        }
        ans += aug;
    } while (aug);
    return ans;
}

int l;
string k1, k2;

bool cool(int f1, int f2) {
    REP(i, l) {
        if (k1[f1+i] != k2[f2+i]) {
            bool ck1 = (k1[f1+i] != '?');
            bool ck2 = (k2[f2+i] != '?');
            if (ck1 && ck2) return false; 
        }
    }
    return true;
}

void update_edges(int u) {
    gr[u].clear();
    int f1 = u*l;
    REP(j, m) {
        if (cool(f1, j*l)) {
            gr[u].push_back(j);
        }
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    int kases;
    cin >> kases;
    for (int kase = 1; kase <= kases; ++kase) {
        cin >> m;
        cin >> k1;
        cin >> k2;
        l = SIZE(k1) / m;
        REP(i, m) update_edges(i);
        int match = bipMatch();
        if (match == m) {
            REP(i, SIZE(k1)) {
                if (k1[i] == '?') {
                    REP(j, 6) {
                        k1[i] = char('a'+j);
                        update_edges(i/l);
                        if (bipMatch() == m) break;
                    }
                }
            }
            cout << "Case #" << kase << ": " << k1 << "\n";
        } else { 
            cout << "Case #" << kase << ": IMPOSSIBLE\n";
        }
    }
    
	 
	return 0;
}

















