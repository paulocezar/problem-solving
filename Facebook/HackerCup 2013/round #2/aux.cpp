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

bool mustbe[10][10];
bool used[10];
int n;
int seq[10];
int cnt;

void solve(int pos) {
    if (pos == n) {
        bool ok = true;
        REP(i, n) REP(j, n) {
            if (mustbe[i][j] && seq[i] > seq[j]) ok = false;
        }
        if (ok) cnt++;
    } else {
        REP(i,n) if (!used[i]) {
            used[i] = true;
            seq[pos] = i;
            solve(pos+1);
            used[i] = false;
        }
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    cin >> n;
    int a, b;
    char sgn;
    REP(i, n-1) {
        cin >> a >> sgn >> b;
        if (sgn == '<') mustbe[a][b] = true;
        else mustbe[b][a] = true;
    }
    REP(i, n) used[i] = false;
    cnt = 0;
    solve(0);
    cout << cnt << "\n";

	return 0;
}

















