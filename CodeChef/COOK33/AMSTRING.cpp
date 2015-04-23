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
    
    int t;
    cin >> t;
    while (t--) {
        
        int N, K;
        cin >> N >> K;
        
        string a, b;
        cin >> a;
        cin >> b;
        
        int64 res = 0;
        FOR(i,1,K) {
            res += (N-i+1LL) * (N-i+1LL);
        }
        
        REP(la,N) {
            if (la+K >= N) break;
            REP(lb, N) {
                if (lb+K >= N) break;
                
                int ra = la-1, rb = lb-1;
                int dist = 0;
                while (ra < (la+K)) {
                    ra++, rb++;
                    if (a[ra] != b[rb]) dist++;
                }
                
                
                while (((ra+1) < N) && ((rb+1) < N) && (dist <= K)) {
                    res++;
                    ra++, rb++;
                    if (a[ra] != b[rb]) dist++;    
                }
                if (dist <= K) res++;
            }
        }
        
        cout << res << "\n";
    }
    
	return 0;
}

















