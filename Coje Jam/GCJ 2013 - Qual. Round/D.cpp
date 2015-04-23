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

#define MAXN 256

int initial[512];

int keys[MAXN];
int t[MAXN];

vector<int> chest[MAXN];


bitset< (1<<20) > cache;
int cached[1<<20], cached_now;

int N;

vector<int> result;

bool solve(int mask) {
    
    if (!mask) return true;
    if (cached[mask] == cached_now) return cache[mask];
    cached[mask] = cached_now;
    
    bool res = false;
    REP(i, N) {
        if ((mask & (1<<i)) && keys[t[i]]) {
                
            keys[t[i]]--;
            REP(j, SIZE(chest[i])) keys[chest[i][j]]++;
                
            res = solve(mask ^ (1<<i));            
            
            REP(j, SIZE(chest[i])) keys[chest[i][j]]--;
            keys[t[i]]++;
            
        }
        if (res) {
            result.PB(i+1);
            break;
        }
    }
    
    cache[mask] = res;
    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int cases;
    cin >> cases;
    FOR(kase,1,cases) {
        
        int K;
        cin >> K >> N;
        
        REP(i, K) cin >> initial[i];
        
        map<int,int> ktp;
        int keytypes = 0;
        
        REP(i, N) {
            cin >> t[i];
            
            if (!ktp.count(t[i])) ktp[t[i]] = keytypes++;
            
            int kk; cin >> kk;
            chest[i].resize(kk);
            
            REP(j,kk) cin >> chest[i][j];
        }
        
        REP(i, N) t[i] = ktp[t[i]];
        REP(i, keytypes) keys[i] = 0;
        
        REP(i, K) if (ktp.count(initial[i]))
            keys[ktp[initial[i]]]++;
        
        REP(i, N) {
            REP(j, SIZE(chest[i])) {
                if (ktp.count(chest[i][j])) chest[i][j] = ktp[chest[i][j]];
                else chest[i][j] = 2e9;
            }
            sort(ALL(chest[i]));
            chest[i].resize(lower_bound(ALL(chest[i]),2e9)-chest[i].begin());
        }
        
        cout << "Case #" << kase << ":";
        
        cached_now++;
        result.clear();
        
        if (solve((1<<N)-1)) {
            REP(i,N) cout << " " << result[N-i-1];
        } else cout << " IMPOSSIBLE";
        
        cout << "\n";
        
    }
    
	return 0;
}

















