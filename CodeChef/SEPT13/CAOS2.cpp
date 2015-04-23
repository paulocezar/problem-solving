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

int cnt[4][512][512];
string grid[512];

bitset< 512 > bs;
vector<int> primes;

void sieve() {
    for (int i = 0; i <= 500; ++i) bs[i] = i & 1;
    bs[1] = false;
    bs[2] = true;
    primes.push_back(2);
    for (int i = 3; i <= 500; i+=2) {
        if (bs[i]) {
            primes.push_back(i);
            for (int j = i*i; j <= 500; j+=i) bs[j] = false;
        }
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    sieve();
    
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        
        REP(i, r) cin  >> grid[i];
        
        REP(i, r) REP(j, c) {
            if (grid[i][j] == '#') cnt[0][i][j] = 0;
            else if (j) cnt[0][i][j] = cnt[0][i][j-1] + 1;
            else cnt[0][i][j] = 1;
        }
        
        REP(j, c) REP(i, r) {
            if (grid[i][j] == '#') cnt[1][i][j] = 0;
            else if (i) cnt[1][i][j] = cnt[1][i-1][j] + 1;
            else cnt[1][i][j] = 1;
        }
        
        REP(i, r) RREP(j,c) {
            if (grid[i][j] == '#') cnt[2][i][j] = 0;
            else if ((j+1) < c) cnt[2][i][j] = cnt[2][i][j+1] + 1;
            else cnt[2][i][j] = 1;
        }
        
        REP(j, c) RREP(i,r) {
            if (grid[i][j] == '#') cnt[3][i][j] = 0;
            else if ((i+1) < r) cnt[3][i][j] = cnt[3][i+1][j] + 1;
            else cnt[3][i][j] = 1;
        }
        
        int res = 0;
        REP(i, r) REP(j, c) {
            int p = 2e9;
            REP(dir,4) p = min(p, cnt[dir][i][j]);
            p = max(p-1,0);
            
            res += upper_bound(primes.begin(), primes.end(), p) - primes.begin();
        }
        cout << res << "\n";
        
        
        
    }
    
    
	return 0;
}

















