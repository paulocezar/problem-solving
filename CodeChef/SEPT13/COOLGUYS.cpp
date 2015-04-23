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

int64 gcd(int64 a, int64 b) {
    while (b) {
        a %= b;
        swap(a,b);
    }
    return a;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int tc;
    cin >> tc;
    while (tc--) {
        int64 n; cin >> n;
        int64 u = sqrt(n);
        int64 num = 0;
        int64 den = n * n;
        for (int k = 1; k <= u; ++k) num += n / k;
    
        num *= 2LL;
        num -= u*u;
        int64 g = gcd(num, den);
        num /= g;
        den /= g;
        cout << num << "/" << den << "\n";
    }
    
	return 0;
}

















