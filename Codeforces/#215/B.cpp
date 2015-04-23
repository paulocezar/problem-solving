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

#define MAXN 202020
int a[MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m, p;
    cin >> n >> m >> p;
    
    FOR (i, 1, n) cin >> a[i];
    
    map<int, int> cntb;
    REP(i, m) {
        int x; cin >> x;
        cntb[x]++;
    }
        
    vector<int> res;
    
    for (int qq = 1; qq <= p; ++qq) {
    
        int64 opa = qq + int64(m-1)*int64(p);
        
        if (opa > int64(n)) break;
        
        map<int, int> cnta;
        
        int init = qq;
        for (int put = 0; put < m; ++put) cnta[a[init + put * p]]++;
        int last = init + (m-1)*p;
        
        int correct = 0;
        FORIT(val, cntb) {
            if (cnta[val->first] == (val->second)) correct++;
        }
        
        while (true) {
            if (correct == SIZE(cntb)) res.push_back(init);
            if ((last + p) > n) break;
            
            if (cntb.count(a[init])) {
                if (cnta[a[init]] == cntb[a[init]]) correct--;
                cnta[a[init]]--;
                if (cnta[a[init]] == cntb[a[init]]) correct++;
            } else cnta[a[init]]--;
            
            init += p;
            last += p;
            
            if (cntb.count(a[last])) {
                if (cnta[a[last]] == cntb[a[last]]) correct--;
                cnta[a[last]]++;
                if (cnta[a[last]] == cntb[a[last]]) correct++;
            } else cnta[a[last]]++;            
        }        
    }
    
    
    cout << SIZE(res) << "\n";
    sort(ALL(res));
    REP(i, SIZE(res)) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
    
    
        
	return 0;
}

















