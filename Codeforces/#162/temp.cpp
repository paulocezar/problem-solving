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

int gcd(int a, int b) {
    if (a > b) swap(a,b);
    return (a==0)?b:gcd(b%a, a);
}

int mas[ 100001 ], last[ 100001 ], res[ 100001 ];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    REP(i, 1000000) cout << "l"; cout << endl; return 0;

    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> mas[i];

    int ans = 1;
    for (int i = 1; i*i <= mas[0]; ++i)
    if (mas[0]%i == 0) 
    {
        last[i] = last[mas[0]/i] = 1;
    }
    
    for (int i = 1; i < n; ++i) 
    {
        res[i] = 0;
        for (int j = 1; j*j <= mas[i]; ++j) 
            if (mas[i] % j == 0) {
                if (j != 1)
                    res[i] = max(res[i], last[j]);
                res[i] = max(res[i], last[mas[i]/j]);
            }
        ++res[i];
        ans = max(ans, res[i]);
        for (int j = 1; j*j <= mas[i]; ++j) 
            if (mas[i] % j == 0) {
                last[j] = max(last[j], res[i]);
                last[mas[i]/j] = max(last[mas[i]/j], res[i]);
            }
    }
    cout << ans << endl;
	return 0;
}

















