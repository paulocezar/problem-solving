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

struct info {
    int pos, type, ref;
    info (int aa = 0, int bb = 0, int cc = 0)  : pos(aa), type(bb), ref(cc) {}
    bool operator < (const info& i) const {
        if (pos != i.pos) return pos < i.pos;
        return type < i.type;
    }
};

int open[1024];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    info ev[2*n];

    REP(i, n) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a,b);
        ev[2*i] = info(a,0, i);
        ev[2*i+1] = info(b,1,i);
    }
    sort(ev,ev+2*n);
    vector<int> res;

    stack<int> s;

    REP(i,2*n) {
        if (!ev[i].type) {
            open[ev[i].ref] = 1;
            s.push(ev[i].ref);
        } else  {
            if (open[ev[i].ref]) {
                res.push_back(ev[i].pos);
                while (!s.empty()) {
                    open[s.top()] = 0;
                    s.pop();
                }
            }        
        }
    }
    
    cout << SIZE(res) <<  "\n";
    REP(i,SIZE(res)) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
	return 0;
}

















