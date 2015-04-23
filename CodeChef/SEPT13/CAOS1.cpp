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

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        string grid[r];
        REP(i, r) cin  >> grid[i];
        int res = 0;
        REP(i, r) {
            REP(j, c) {
                if (grid[i][j] != '^') continue;
                int p = 2e9;
                REP(dir, 4) {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    int cnt = 0;
                    while (0 <= ni && ni < r && 0 <= nj && nj < c && cnt < 2) {
                        if (grid[ni][nj] == '^') cnt++;
                        else break;
                        ni += dx[dir];
                        nj += dy[dir];
                    }
                    p = min(p, cnt);
                }
                if (p == 2) res++;
            }
        }
        cout << res << "\n";
    }
    
    
	return 0;
}

















