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

int di[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1,-1, 1,-1, 0, 1};

int layout[128][128];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
	FOR(i, 1, N) FOR(j, 1, M) cin >> layout[i][j];

    set<int> bad;
    
    FOR(i, 1, N) FOR(j, 1, M) {
        REP(dir, 8) {
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if (layout[i][j] == layout[ni][nj])
                bad.insert(layout[i][j]);
        }
    }

    int res = SIZE(bad);
    if (bad.count(-1)) res--;
    cout << res << "\n";
	return 0;
}

















