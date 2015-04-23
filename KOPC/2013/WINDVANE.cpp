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


int grid[1024][1024];
int lazy[1024][1024];

int m, n;
int xa, xb, ya, yb;

void change(int x, int y, int by) {
    while (x <= m) {
        int yy = y;
        while (yy <= n) {
            lazy[x][yy] += by;
            yy += (yy & -yy);
        }
        x += (x & -x);
    }
}

void change(int wut) {
    change(xa  ,   ya, wut);
    change(xb+1,   ya,-wut);
    change(xa  , yb+1,-wut);
    change(xb+1, yb+1, wut);
}

int rget(int x, int y) {
    int res = 0;
    while (x > 0) {
        
        int yy = y;
        while (yy > 0) {
            res += lazy[x][yy];
            yy -= (yy & -yy);
        }
        
        x -= (x & -x);
    }
    res = ((res%4) + 4)%4;
    return res;
}

int get(int x, int y) {
    int res = grid[x][y] + rget(x,y);
    res = ((res%4) + 4)%4;
    return res;
}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    string ans = "NESW";
    cin >> m >> n;
    FOR(i, 1, m) {
        string line;
        cin >> line;
        REP(j, n) {
            switch (line[j]) {
                case 'N': grid[i][j+1] = 0; break;
                case 'E': grid[i][j+1] = 1; break;
                case 'S': grid[i][j+1] = 2; break;
                case 'W': grid[i][j+1] = 3; break;
            }
        }
    }
    
    int c, d;
    cin >> c;
    while (c--) {
        char cmd;
        cin >> cmd;
        switch (cmd) {
            case 'C':
                cin >> xa >> ya >> xb >> yb >> d;
                if (d == 0) change(1);
                else change(-1);
            break;
            case 'D':
                cin >> xa >> ya;
                cout << ans[get(xa,ya)] << "\n";
            break;
        }
    }
	 
	return 0;
}

















