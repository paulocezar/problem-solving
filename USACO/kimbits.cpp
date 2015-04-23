/*
ID: knightp2
PROG: kimbits
LANG: C++
*/
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
#include <fstream>
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

template<typename T> T inline SQR(const T &a) { return a*a; }
template<typename T> T inline ABS(const T &a) { return a < 0 ? -a : a; }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bool memo[32][32];
int64 res[32][32];

int64 get(int len, int ones) {
    if (len == 0 || ones == 0) return 1LL;
    if (memo[len][ones]) return res[len][ones];
    int64 &ret = res[len][ones]; memo[len][ones] = true;
    ret = get(len-1,ones) + get(len-1, ones-1);
    return ret;
}

int main(int argc, char* argv[]) {
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    
    int N, L; int64 I;
    cin >> N >> L >> I;
    for (int i = 1; i <= N; ++i) {
        if (get(N-i, L) >= I) cout << "0";
        else {
            I -= get(N-i,L);
            cout << "1";
            L--;
        }
    }
    cout << "\n";
        
	return 0;
}

















