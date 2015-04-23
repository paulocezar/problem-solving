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

#define FILL(X, V) memset((X), (V), sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = (a).begin(); i != (a).end(); ++i)

#define PB push_back
#define MP make_pair
    
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

const double EPS = 1e-9;
inline int SGN(double a) {
    return ((a > EPS)?(1):((a < -EPS)?(-1):(0)));
}
inline int CMP(double a, double b) {
    return SGN(a - b);
}

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1000000
#define SQ 1000

bitset< MAXN+1 > bs;
vector< int > primes;

void sieve() {
    FOR(i,1,MAXN) bs[i] = i&1;
    bs[1] = false;
    bs[2] = true;
    for (int i = 3; i <= SQ; i += 2) if (bs[i]) {
        for (int j = i*i; j <= MAXN; j+=i) bs[j] = false;
    }
    primes.PB(2);
    for(int i = 3; i <= MAXN; i+=2) if(bs[i]) primes.PB(i);
}

int count(int from,int to) {
    return (upper_bound(ALL(primes), to) - 1) - (upper_bound(ALL(primes),from-1)-1);
}

int a, b, k;
bool ok(int l) {
    
    int x = a;
    while (x <= (b-l+1)) {
        if (count(x,x+l-1) < k) return false;
        ++x;
    }
    
    return true;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	
    sieve();
    cin >> a >> b >> k;
    
    int ans = -1;
    int lo = 0, hi = (b-a+1);
    while (lo <= hi) {
       
        int mid = (lo+hi)>>1;
        if (ok(mid)) {
            ans = mid;
            hi = mid-1;
        } else lo = mid+1;
        
    }
    cout << ans << "\n";
    
	return 0;
}

















