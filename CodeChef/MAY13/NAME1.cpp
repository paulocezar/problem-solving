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

int cnt1[26], cnt2[26];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    string s;
    
    cin >> t;
    while (t--) {
        REP(i,26) cnt1[i] = 0, cnt2[i] = 0;
        
        REP(i,2) {
            cin >> s;
            REP(j,SIZE(s)) cnt1[s[j]-'a']++;
        }
        int n;
        cin >> n;
        REP(i,n) {
            cin >> s;
            REP(j,SIZE(s)) cnt2[s[j]-'a']++;
        }
        
        bool ok = true;
        REP(i,26) if (cnt2[i] > cnt1[i]) ok = false;
        
        if (ok) cout << "YES\n";
        else cout << "NO\n";
        
    }
    
	return 0;
}

















