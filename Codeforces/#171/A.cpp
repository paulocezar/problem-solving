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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int times = 1;
    int keep = 2;
    int done = 0;
    int res = 0;
    
    
    int x, y;
    cin >> x >> y;
    int curx = 0, cury = 0, dir = 0;
    
    while (curx != x || cury != y) {
        if (done == times) {
            keep--;
            done = 0;
            if (!keep) { times++; keep = 2; }

            dir++; if (dir == 4) dir = 0;
            res++;
        }
        
        curx += dx[dir];
        cury += dy[dir];
        done++;
    }
    
    cout << res << "\n";
    
	return 0;
}

















