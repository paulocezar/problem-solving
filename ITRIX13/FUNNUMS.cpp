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


int64 f[16];

int64 findindex(string s) {
    
    int n = SIZE(s);
    string ss = s; sort(ALL(ss));
    
    int used = 0;
    int64 cur = 0;
    
    REP(i, n) {
        
        int64 prv = 0;
        REP(j, n) {
            if (used & (1<<j)) continue;
            if (ss[j] == s[i]) {
                cur += prv * f[n-i-1];
                used |= (1<<j);
            }
            prv++;
        }
                
    }
    
    return cur + 1;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
        
    f[0] = 1LL;
    FOR(i,1,15) f[i] = int64(i) * f[i-1];
    
    int t;
    cin >> t;
    while (t--) {
        string s; int64 n;
        cin >> s >> n;
        
        int64 idx = findindex(s);
        int64 wntd = n + idx;
        
        int nn = SIZE(s);
        sort(ALL(s));
        int used = 0;
        REP(i, nn) {
            int64 cur = 0LL;
            REP(j, nn) {
                if (used & (1<<j)) continue;
                if ((cur + f[nn-i-1]) >= wntd) {
                    used |= (1<<j);
                    cout << s[j];
                    wntd -= cur;
                    break;
                } else cur += f[nn-i-1];
            }
            
        }
        
        cout << "\n";
    }
    
	return 0;
}

















