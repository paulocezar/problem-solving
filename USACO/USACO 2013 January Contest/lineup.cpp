/*
ID: knightp2
PROG: lineup
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

#define MAXN 100000
int b[MAXN];

int main(int argc, char* argv[]) {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    
    int N, K;
    cin >> N >> K;
    
    map<int, int> cnt;
    REP(i, N) {
        cin >> b[i];
        cnt[b[i]]++;
    }
    
    int res = 1;
    int eq = 1;
    FOR(i, 1, N-1) {
        if (b[i] == b[i-1]) eq++;
        else {
            res = max(res, eq);
            eq = 1;
        }
    }
    res = max(res, eq);
    
    
    REP(i, N) {
        if (cnt[b[i]] <= res) {
            cnt[b[i]]--;
            continue;
        }
        
        int cur = 1;
        int kk = K;
        int j = i+1;
        
        set<int> removed;
        
        while (j < N) {
            if (b[j] == b[i]) {
                cur++;
            } else {
                if (removed.insert(b[j]).second) {
                    kk--;
                    if (kk < 0) break;
                }
            }
            j++;
        }
        res = max(res, cur);
        cnt[b[i]]--;
    }
    cout << res << "\n";
	return 0;
}

















