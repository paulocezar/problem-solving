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

#define MAXN 100

int mx[MAXN];
int a[MAXN][MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int cases;
    cin >> cases;
    FOR(kase,1,cases) {
        
        int N, M;
        cin >> N >> M;
        int mx[N];
        REP(i, N) {
            mx[i] = -1;
            REP(j, M) {
                cin >> a[i][j];
                mx[i] = max(mx[i], a[i][j]);
            }
        }
        
        bool bad = false;
        REP(i, N) REP(j, M) {
            if (a[i][j] < mx[i]) {
                REP(ii,N) {
                    if (a[ii][j] > a[i][j]) {
                        bad = true;
                        goto hell;
                    }
                }
            }
        }
    hell:
        cout << "Case #" << kase << ": " << (bad?"NO\n":"YES\n");
    }
    
	return 0;
}

















