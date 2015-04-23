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
#include <fstream>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int64 board[128][128];

int64 eval[128][128];
int okay[128][128];

char solved[128][128];
int64 cache[128][128];


int N, M, K;
string pattern[128];


int64 solve(int line, int lastp) {
    if (line == N) return 0LL;
    
    int64 &ret = cache[line][lastp];
    if (solved[line][lastp]) return ret;
    solved[line][lastp] = 1;
    
    bool f = true;
    
    for (int i = 0; i < K; ++i) {
        if (okay[i][lastp]) {
            int64 cur = eval[line][i] + solve(line+1, i);
            if (f || (cur > ret)) ret = cur;
            f = false;
        }
    }
    
    if (f) ret = -2e9;
    
    return ret;
    
}

int64 feval(int line, int pat) {
    int64 res = 0LL;
    for (int j = 0; j < M; ++j) {
        if (pattern[pat][j] == '+') res += board[line][j];
        else if (pattern[pat][j] == '-') res -= board[line][j];
    }
    return res;
}

int isgood(int pat1, int pat2) {
    for (int j = 0; j < M; ++j) {
        if (pattern[pat1][j] == '.') continue;
        if (pattern[pat1][j] == pattern[pat2][j]) return 0;
    }
    return 1;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    while (cin >> N >> M && (N || M)) {
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> board[i][j];
            }
        }
        
        cin >> K;
        for (int i = 0; i < K; ++i) cin >> pattern[i];
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < K; ++j) {
                eval[i][j] = feval(i, j);
            }
        }
        
        for (int i = 0; i < K; ++i) {
            for (int j = i; j < K; ++j) {
                okay[i][j] = okay[j][i] = isgood(i, j);
            }
        }
        memset(solved, 0, sizeof(solved));
        
        int64 ans = eval[0][0] + solve(1, 0);
        for (int j = 1; j < K; ++j) {
            ans = max(ans, eval[0][j] + solve(1, j));
        }
        
        cout << ans << "\n";
    }

	return 0;
}

















