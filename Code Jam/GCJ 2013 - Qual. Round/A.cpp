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

string grid[4];

bool win(char who) {
    
    REP(a, 4) {
        bool okl = true;
        bool okc = true;
        REP(b,4) {
            if (grid[a][b] != who) okl = false;
            if (grid[b][a] != who) okc = false;
        }
        if (okl || okc) return true;
    }
    
    bool diag1 = true, diag2 = true;
    REP(i,4) {
        if (grid[i][i] != who) diag1 = false;
        if (grid[i][3-i] != who) diag2 = false;
    }
    
    return (diag1 || diag2);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int cases;
    cin >> cases;
    FOR(kase,1,cases) {
        
        REP(i,4) cin >> grid[i];
        
        int dots = 0, a, b;
        REP(i, 4) REP(j, 4) {
            if (grid[i][j] == 'T') a = i, b = j;
            else if (grid[i][j] == '.') dots++;
        }
        
        cout << "Case #" << kase << ": ";
        grid[a][b] = 'X';
        if (win('X')) cout << "X won\n";
        else {
            grid[a][b] = 'O';
            if (win('O')) cout << "O won\n";
            else if (dots) cout << "Game has not completed\n";
            else cout << "Draw\n";
        }
        
    }
    
	return 0;
}

















