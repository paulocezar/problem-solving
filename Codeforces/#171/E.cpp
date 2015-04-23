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

string s;
int cache[2][1000000];

int solve(int pos, int inv) {
    if (pos < 0) return inv;
    
    int &res = cache[inv][pos];
    if (res) return res;
    res = 2e9;
    
    if (s[pos] == '0') {
        res = inv + solve(pos-1,inv);
    } else {
        res = (1-inv) + solve(pos-1,inv);
        if (!inv && pos) {
            res = min(res, 1+solve(pos-1,1));
        } else if (inv) {
            res = min(res, 1+solve(pos-1,0));
        }
    }
    res = min(res, 1 + solve(pos-1,1-inv));
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    cin >> s;
    cout << solve(SIZE(s)-1,0) << "\n";
    
	return 0;
}

















