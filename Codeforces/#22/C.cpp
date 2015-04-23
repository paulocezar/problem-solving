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



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m, v;
    cin >> n >> m >> v;

    int64 mx = (int64(n-2LL) * int64(n-3LL)) / 2LL;
    mx += int64(n-1LL);

    if ((m < (n-1)) || (m > mx)) cout << "-1\n";
    else {
        FOR(i,1,n) {
            if (i != v) cout << v << " " << i << "\n";
        }
        m -= n-1;
        int u = 1;
        if (u == v) u = 2;

        int a = 1, b = 2;
        while (m) {
                
            if (a != u && a != v && b != u && b != v) {
                cout << a << " " << b <<  '\n';
                m--;
            }
            
            b++;
            if (b > n) {
                a++;
                b = a+1;
            }
        }
    }

	return 0;
}

















