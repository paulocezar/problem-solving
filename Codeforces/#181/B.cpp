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

#define MAXN 64

int comp[MAXN];
int compsz[MAXN];
int ncomps[4];
bool want[MAXN][MAXN];
vector<int> at[MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
        
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        want[u][v] = want[v][u] = true;
    }
    
    int cmp = 1;
    FOR(i,1,n) if (!comp[i]) {
    
        comp[i] = cmp;
        compsz[cmp] = 0;

        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            compsz[cmp]++;
            int u = q.front(); q.pop();
            at[cmp].PB(u);
            FOR(v,1,n) if (want[u][v] && !comp[v]) {
                q.push(v);
                comp[v] = cmp;
            }
        }
        if (compsz[cmp] > 3) {
            cout << "-1\n";
            return 0;
        }
        ncomps[compsz[cmp]]++;
        cmp++;
    }

    if (ncomps[1] < ncomps[2]) {
        cout << "-1\n";
        return 0;
    }
    
    set<int> used;
    FOR(i,1,cmp-1) {
        if (used.count(i)) continue;
        if (compsz[i] == 3) {
            used.insert(i);
            REP(j,3) {
                if (j) cout << " ";
                cout << at[i][j];
            }
            cout << "\n";
        } else if (compsz[i] == 2) {
            used.insert(i);
            FOR(k,i+1,cmp-1) {
                if (used.count(k)) continue;
                if (compsz[k] != 1) continue;
                cout << at[k][0];
                used.insert(k);
                break;
            }
            REP(j,2) cout << " " << at[i][j];
            cout << "\n";
        } else {
            used.insert(i);
            cout << at[i][0];
            
            bool ok = false;
            FOR(k,i+1,cmp-1) {
                if (used.count(k)) continue;
                if (compsz[k] != 2) continue;
                used.insert(k);
                cout << " " << at[k][0] << " " << at[k][1] << "\n";
                ok = true;
                break;
            }

            if (!ok) {
                int foi = 0;
                FOR(k,i+1,cmp-1) {
                    if (used.count(k)) continue;
                    if (compsz[k] != 1) continue;
                    used.insert(k);
                    cout << " " << at[k][0];
                    foi++;
                    if (foi == 2) break;
                }
                cout << "\n";
            }

        }
    }


	return 0;
}

















