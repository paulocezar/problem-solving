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

int mark[1000100];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    if (n < 3*k) cout << "-1\n";
    else {
        int last = -4;
        FOR(i,1,k) {
            if (i&1) {
                last += 4;
                mark[last] = mark[last+1] = mark[last+3] = i;
            } else {
                last += 2;
                mark[last] = mark[last+2] = mark[last+3] = i;
            }
        }
        if (k & 1) mark[3] = k, mark[3*k] = 1;
        REP(i,n) {
            if (i) cout << " ";
            if (mark[i]) cout << mark[i];
            else cout << 1;
        }
        cout << "\n";
    }
    
	return 0;
}

















