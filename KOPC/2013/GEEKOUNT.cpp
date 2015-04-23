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

string s;
int dp[2][2][2][10];
int calc[2][2][2][10], last_calc;

int doit(int nzr, int eq, int even, int pos) {
    if (pos == SIZE(s)) {
        return ((nzr && even) ? (1) : (0));
    }
    int &res = dp[nzr][eq][even][pos];
    if (calc[nzr][eq][even][pos] == last_calc) return res;
    calc[nzr][eq][even][pos] = last_calc;
    res = 0;
    int hi = eq ? (s[pos]-'0') : 9;
    int dig = 0;
    int nnzr, neq, neven;
    while (dig <= hi) {
        nnzr = nzr || (dig != 0);
        neq = eq && (dig == hi);
        neven = even
                || (nzr && (!(dig & 1)))
                || (!nzr && dig && (!(dig & 1)));
        res += doit(nnzr, neq, neven, pos+1);
        ++dig;
    }
    return res;
}

int solve(int lim) {
    s = "";
    while (lim) {
        s += char((lim%10)+'0');
        lim /= 10;
    }
    if (s == "") return 0;
    reverse(ALL(s));
    last_calc++;
    return doit(0,1,0,0);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
        
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        cout << solve(R)-solve(L-1) << "\n";
    }
	 
	return 0;
}

















