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

int mouses[128][128];
int dp[128][128][2][2];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        string line;
        FOR(i,1,n) {
            mouses[i][0] = mouses[i][m+1] = 0;
            cin >> line;
            FOR(j,1,m) mouses[i][j] = (line[j-1]-'0');
        }
        FOR(j,1,m) mouses[0][j] = mouses[n+1][j] = 0;
        mouses[0][0] = mouses[n+1][0] = mouses[0][m+1] = mouses[n+1][m+1] = 0;
        
        REP(a,2) REP(b,2) {
            FOR(i,1,n) dp[i][0][a][b] = n*m;
            FOR(j,1,m) dp[0][j][a][b] = n*m;
            dp[1][1][a][b] = mouses[1][1] + mouses[1][2] + mouses[2][1];
        }
        
        FOR(i,1,n) {
            FOR(j,1,m) {
                if (i == j && i == 1) continue;
                REP(a,2) REP(b,2) {
                    int oi = i, oj = j;
                
                    if (b)  oi--;
                    else oj--;
                    
                    dp[i][j][a][b] = min(dp[oi][oj][0][a], dp[oi][oj][1][a]);
                    
                    dp[i][j][a][b] += mouses[i+1][j] + mouses[i][j+1];
                    if (a && b) dp[i][j][a][b] += mouses[i][j-1];
                    if (!a && !b) dp[i][j][a][b] += mouses[i-1][j];
                }
            }
        }
        
        int res = n*m;
        REP(i,2) REP(j,2) res = min(res, dp[n][m][i][j]);
        cout << res << "\n";
    }
    
	return 0;
}

















