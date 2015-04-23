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

#define MAXN 100000
int64 B[MAXN], L[MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int N; cin >> N;
        REP(i, N) cin >> B[i] >> L[i];
        tr1::unordered_map<int64, int64> lwst;
        REP(i, N) {
            if (lwst.count(B[i])) lwst[B[i]] = min(lwst[B[i]], L[i]);
            else lwst[B[i]] = L[i];
        } 
        
        int64 res = 0LL;
        int64 bands = 0LL;
        
        vector<int64> wgs;
        for (__typeof(lwst.begin()) it = lwst.begin(); it != lwst.end(); it++) {
            wgs.PB(it->second);
        }
        sort(ALL(wgs));
        
        REP(i, SIZE(wgs)) {
            ++bands;
            res += bands * wgs[i];
        }
        
        REP(i, N) {
            if (lwst[B[i]] == L[i]) lwst[B[i]] = -1;
            else res += bands * L[i];
        }
        
        cout << res << "\n";
        
    }
    
	return 0;
}

















