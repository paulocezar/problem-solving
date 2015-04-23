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

#define MAXN 100000
int dp[MAXN];

bitset< MAXN+1 > bs;
vector<int> primes;

void sieve() {
    primes.clear();
    for (int i = 0; i <= MAXN; ++i) bs[i] = (i&1);
    bs[1] = false; bs[2] = true;
    for (int i = 3; i <= 317; i+=2) {
        if (!bs[i]) continue;
        for (int j = i*i; j <= MAXN; j+=i) bs[j] = false;
    }
    primes.push_back(2);
    for (int i = 3; i <= MAXN; i+=2) if (bs[i]) primes.push_back(i);
}

int cand[10000];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    sieve();
    int n;
    cin >> n;
       
    int res = 0;

    REP(i, n) {
       int longest = 1;
       int x; cin >> x;
       
       int nn = 0;
       int j = 0;
       
       while (int64(x) >= (int64(primes[j])*int64(primes[j]))) { 
           if ((x % primes[j]) == 0) {
            cand[nn] = j; nn++;
            while ((x % primes[j]) == 0) x /= primes[j];
           }
           j++;
       }
       if (x != 1) { 
            while (primes[j] != x) j++;
            cand[nn] = j; nn++;
       }
       REP(kk, nn) longest = max(longest, dp[cand[kk]]+1);
       REP(kk, nn) dp[cand[kk]] = max(dp[cand[kk]], longest);
       res = max(res, longest);
    }
	
    cout << res << "\n";
	return 0;
}

















