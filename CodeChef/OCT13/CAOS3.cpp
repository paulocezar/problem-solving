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

int monster[32][32];

int cache[32][32][32][32];
int last_cached[32][32][32][32], cached_now;

int grundy(int lox, int loy, int hix, int hiy) {
    if (lox > hix || loy > hiy) return 0;
    
    int &res = cache[lox][loy][hix][hiy];
    if (last_cached[lox][loy][hix][hiy] == cached_now) return res;
    last_cached[lox][loy][hix][hiy] = cached_now;
        
    tr1::unordered_set<int> seen;
    
    for (int i = lox; i <= hix; ++i) {
        for (int j = loy; j <= hiy; ++j) {
            if (monster[i][j]) {
                int cur = grundy(lox,loy,i-1,j-1);
                cur ^= grundy(lox,j+1,i-1,hiy);
                cur ^= grundy(i+1,loy,hix,j-1);
                cur ^= grundy(i+1,j+1,hix,hiy);
                seen.insert(cur);
            }
        }
    }               
    
    res = 0;
    while (seen.count(res)) res++;
    return res;
    
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        int R, C;
        cin >> R >> C;
        
        string grid[R];
        REP(i, R) cin  >> grid[i];
        
        REP(i, R) {
            REP(j, C) {
                
                monster[i][j] = 0;
                if (grid[i][j] != '^') continue;
                int p = 2e9;
                REP(dir, 4) {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    int cnt = 0;
                    while (0 <= ni && ni < R && 0 <= nj && nj < C && cnt < 2) {
                        if (grid[ni][nj] == '^') cnt++;
                        else break;
                        ni += dx[dir];
                        nj += dy[dir];
                    }
                    p = min(p, cnt);
                }
                if (p == 2) monster[i][j] = 1;
            }
        }
        
        cached_now++;
        if (grundy(0,0,R-1,C-1)) cout << "Asuna\n";
        else cout << "Kirito\n";
        
    }    
        
	return 0;
}

















