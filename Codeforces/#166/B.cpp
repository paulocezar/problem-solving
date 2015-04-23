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

#define MAXP 120000
bitset< MAXP > bs;
vector<int> primes;

void sieve() {
    primes.clear();
    for (int i = 0; i < MAXP; ++i) bs[i] = (i&1);
    bs[1] = false; bs[2] = true;
    for (int i = 3; i <= 350; i+=2) {
            if (!bs[i]) continue;
            for (int j = i*i; j < MAXP; j+=2*i) bs[j] = false;
        }
    primes.push_back(2);
    for (int i = 3; i < MAXP; i+=2) if (bs[i]) primes.push_back(i);
}

int dist[512][512];
int line[512];
int colm[512];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    sieve();    

    int n, m;
    cin >> n >> m;
    
    REP(i, n) REP(j,m) {
        int x; cin >> x;
        int pp = *lower_bound(ALL(primes),x);
        dist[i][j] = pp - x;
        line[i] += dist[i][j];
        colm[j] += dist[i][j];
    }
    
    int best = line[0];
    REP(i,n) best = min(best,line[i]);
    REP(j,m) best = min(best,colm[j]);
    cout << best << "\n";

	return 0;
}

















