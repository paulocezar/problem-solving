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

int cur;
char ltr;
void go(int i, int j, vector<string>& s, vector<vector<int> > &a) {
    if (i < 0 || i >= SIZE(s) || j < 0 || j >= SIZE(s[i]) || a[i][j] || s[i][j] != ltr) return;
    a[i][j] = cur;
    go(i+1,j,s,a);
    go(i-1,j,s,a);
    go(i,j+1,s,a);
    go(i,j-1,s,a);
}

void flood(vector<string>& state, vector<vector<int> >&id) {
    cur = 1;
    int n = SIZE(state);
    REP(i,n) {
        int m = SIZE(state[i]);
        
        REP(j, m) if (!id[i][j]) {
            ltr = state[i][j];
            go(i,j,state,id);
            cur++;
        }
    }
}

map<vector<string>,int> memo;
int solve(vector<string>& state) {
    if (state.empty()) return 0;
    if (memo.count(state)) return memo[state];
    int &res = memo[state];
    res = 2e9;
    
    int n = SIZE(state);
    int m = SIZE(state[0]);
    
    vector< vector<int> > comp(n);
    REP(i, n) {
        comp[i] = vector<int>(m,0);
    }
    
    flood(state,comp);
    
    int comps = cur;
    FOR(ccomp,1,comps-1) {
        
        vector<string> nboard;
        REP(i, n) {
            int m = SIZE(state[i]);
            string s = "";
            REP(j, m) {
                if (comp[i][j] != ccomp) s += state[i][j];
                else s += ".";
            }
            nboard.PB(s);
        }
        
        res = min(res, 1 + solve(nboard));
    }
    
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> board(n);
        REP(i, n) cin >> board[i];
        cout << solve(board) << "\n";
    }
    
	return 0;
}

















