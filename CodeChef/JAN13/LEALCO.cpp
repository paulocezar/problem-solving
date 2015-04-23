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

#define MAXN 17
int R[MAXN];

int main(int argc, char* argv[]) {
    
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int N, K, M;
        cin >> N >> K >> M;
        for (int i = 0; i < N; ++i) cin >> R[i];
        int all = (1<<N)-1;
        int res = -1;
        for (int mask = 0; mask <= all; ++mask) {
            int cur = __builtin_popcount(mask);
            if ((res != -1) && (cur > res)) continue;
            
            bool ok = true;
            for (int j = 0; j+K <= N; ++j) {
                int mx = -1, cnt;
                for (int i = j; i < j+K; ++i) {
                    int RR = R[i] + ((mask >> i) & 1);
                    if (RR > mx) mx = RR, cnt = 1;
                    else if (RR == mx) cnt++;
                }
                if (cnt >= M) { ok = false; break; }
            }
            if (ok) {
                if (res == -1) res = cur;
                else res = min(res, cur);
            }
        }
        cout << res << "\n";
    }
    return 0;
}

















