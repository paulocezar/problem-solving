/*
ID: knightp2
PROG: hillwalk
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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

struct hill_t {
    int x1, y1, x2, y2;
    explicit hill_t(int a = 0, int b = 0, int c = 0, int d = 0) : x1(a), y1(b), x2(c), y2(d) {}
    bool operator < (const hill_t &a) const {
        if (x2 != a.x2) return x2 < a.x2;
        if (x1 != a.x1) return x1 < a.x1;
        if (y2 != a.y2) return y2 < a.y2;
        return y1 < a.y1;
    }
};

class hghst{
public:
    bool operator() (const hill_t &a, const hill_t &b) {
        if (a.y2 != b.y2) return a.y2 < b.y2;
        if (a.y1 != b.y1) return a.y1 < b.y1;
        if (a.x2 != b.x2) return a.x2 < b.x2;
        return a.x1 < b.x1;        
    }
};

#define MAXHILLS 100000
hill_t hill[MAXHILLS];

int main(int argc, char* argv[]) {
    freopen("hillwalk.in", "r", stdin);
    freopen("hillwalk.out", "w", stdout);
    
    int n; cin >> n;
    REP(i,n) cin >> hill[i].x1 >> hill[i].y1 >> hill[i].x2 >> hill[i].y2;
    sort(hill+1, hill+n);
    
    int l = 1, r = 1;
    int seen = 1;
    hill_t cur = hill[0];
    
    set< hill_t, hghst > active;
    while (true) {
        
        while (r < n && hill[r].x1 <= cur.x2) active.insert(hill[r++]);
        while (l < r && hill[l].x2 <= cur.x2) active.erase(hill[l++]);
        
        if (l >= r) break;
        cur = *active.begin(); active.erase(cur);
        seen++;
        
    }
    cout << seen << "\n";
    
	return 0;
}

















