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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

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

template<typename T> T inline SQR(const T &a) { return a*a; }
template<typename T> T inline ABS(const T &a) { return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN(double a){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP(double a, double b){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bitset< 10001 > bs;
vector< int > primes;

void sieve() {
    REP(i,10001) bs[i] = (i&1);
    bs[1] = false;
    bs[2] = true;
    for (int i = 3; i <= 100; i += 2) if (bs[i]) {
        for (int j = i*i; j <= 10000; j += i) bs[j] = false;
    }
    primes.PB(2);
    for (int i = 3; i <= 10000; i += 2) if (bs[i]) primes.PB(i);
}

bool isprime(int x) {
    if (x <= 10000) return bs[x];
    REP(i,SIZE(primes)) {
        if (x % primes[i] == 0) return false;
        if (primes[i]*primes[i] > x) break;
    }
    return true;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    sieve();
    
    int t;
    cin >> t;
    while (t--) {
        int N; cin >> N;
        int res = N/2 + 1;
        //while (res-1N % (res-1) > N % res) res--;
        cout << res << "\n";
    }
	 
	return 0;
}

















