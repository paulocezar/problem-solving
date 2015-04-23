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

#define MAXPASS 10000000
bitset< MAXPASS > bs;
vector<int> primes;

void sieve() {
    primes.clear();
    for (int i = 0; i < MAXPASS; ++i) bs[i] = (i&1);
    bs[1] = false; bs[2] = true;
    for (int i = 3; i <= 3163; i+=2) {
        if (!bs[i]) continue;
        for (int j = i*i; j < MAXPASS; j+=i) bs[j] = false;
    }
    primes.push_back(2);
    for (int i = 3; i < MAXPASS; i+=2) if (bs[i]) primes.push_back(i);
}

#define MAXN 350
int pass[MAXN][MAXN], N;
int seen[MAXN][MAXN], seen_now;

void flood(int i, int j, int par) {
    seen[i][j] = seen_now;
    if (((i+1) < N) && (seen[i+1][j] != seen_now) && (par == (pass[i+1][j]&1)) && !bs[pass[i+1][j]]) 
        flood(i+1,j,par); 
    if (((i-1) >= 0) && (seen[i-1][j] != seen_now) && (par == (pass[i-1][j]&1)) && !bs[pass[i-1][j]]) 
        flood(i-1,j,par);
    if (((j+1) < N) && (seen[i][j+1] != seen_now) && (par == (pass[i][j+1]&1)) && !bs[pass[i][j+1]]) 
        flood(i,j+1,par);
    if (((j-1) >= 0) && (seen[i][j-1] != seen_now) && (par == (pass[i][j-1]&1)) && !bs[pass[i][j-1]]) 
        flood(i,j-1,par);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    sieve();

    int t;
    cin >> t;
    while (t--) {
        cin >> N;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> pass[i][j];
        seen_now++;
        int64 res = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (seen[i][j] == seen_now) continue;
                if (bs[pass[i][j]]) {
                    res += int64(lower_bound(primes.begin(), primes.end(), pass[i][j]) - primes.begin());
            } else {
                    int par = pass[i][j] & 1;
                    if (par) res += (pass[i][j]>>1) + 2;
                    else res += (pass[i][j]>>1);
                    flood(i,j,par);
                }
            }
        }
        cout << res << "\n";
    }
	return 0;
}

















