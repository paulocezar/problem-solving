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

int n, len[222], grid[222][222];
int seen[222][222], seen_now;
int dp[222][222];

int solve(int i, int j) {
    if (!i && !j) return grid[i][j];
    int &res = dp[i][j];
    if (seen[i][j] == seen_now) return res;
    seen[i][j] = seen_now;
    res = -1;
    if (len[i-1] > len[i]) {
        if (j < len[i-1]) res = max(res,grid[i][j] + solve(i-1,j));
        if ((j+1) < len[i-1]) res = max(res,grid[i][j] + solve(i-1,j+1));
    } else {
        if (j < len[i-1]) res = max(res,grid[i][j] + solve(i-1,j));
        if ((j-1) >= 0) res = max(res,grid[i][j] + solve(i-1,j-1));
    }
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(i, t) {
        cin >> n;
        int ll = 1;
        REP(i, n) {
            len[i] = ll;
            if (i < (n/2)) ll++;
            else ll--;
            REP(j, len[i]) cin >> grid[i][j];
        }
        seen_now++;
        cout << solve(n-1,0) << "\n";
    }
    
    
	return 0;
}

















