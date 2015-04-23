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



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    string grid[n];
    REP(i,n) cin >> grid[i];
    
    int acm[n+1][m+1];
    FILL(acm, 0);

    REP(i,n) REP(j, m) {
        acm[i+1][j+1] = acm[i][j+1] + acm[i+1][j] - acm[i][j];
        if (grid[i][j]=='1') acm[i+1][j+1]++;
    }

    int res = 0;
    FOR(i1,1,n) {
        FOR(i2,i1,n) {
            FOR(j1,1,m) {
                FOR(j2,j1,m) {
                    int has = acm[i2][j2] - acm[i2][j1-1] - acm[i1-1][j2] + acm[i1-1][j1-1];
                    if (!has) res = max(res, 2*(i2-i1+1) + 2*(j2-j1+1));
                }
            }
        }
    }
    cout << res << "\n";
	return 0;
}

















