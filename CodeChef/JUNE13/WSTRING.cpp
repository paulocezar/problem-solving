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

int occ[26][10101];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        
        string s;
        cin >> s;
        int n  = SIZE(s);
        
        REP(c, 26) occ[c][0] = 0;
        
        vector<int> pos;
    
        REP(i, n) {
            REP(c,26) occ[c][i+1] = occ[c][i];
            
            if (s[i] != '#') occ[s[i]-'a'][i+1]++;
            else pos.PB(i);
        }
        
        int res = 0;
        
        REP(i, SIZE(pos)-2) {
            int p1 = pos[i], p2 = pos[i+1], p3 = pos[i+2];
            
            int c1  = 0, c2 = 0, c3 = 0, c4 = 0;
            
            REP(c, 26) {
                c1 = max(c1, occ[c][p1]);
                c2 = max(c2, occ[c][p2]-occ[c][p1]);
                c3 = max(c3, occ[c][p3]-occ[c][p2]);
                c4 = max(c4, occ[c][n]-occ[c][p3]);
            }
            if (c1 && c2 && c3 && c4) res = max(res, c1+c2+c3+c4+3);
        }
        
        cout << res << "\n";
        
        
    }
    
	return 0;
}

















