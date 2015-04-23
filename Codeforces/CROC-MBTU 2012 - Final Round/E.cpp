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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

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

const double EPS = 1e-9;
inline int SGN(double a){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP(double a, double b){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

string grid[128];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    REP(i, n) {
        cin >> grid[i];
        grid[i] = "#" + grid[i] + "#";
    }
    
    int64 res = 0;
    
    int i = 0;
    int dir = 1;
    
    int l = 1, r = 1, cur = 1;
    bool looped = false;
    
    while (i != n-1) {
        
        //cout << i << " " << cur << endl;
        
        l = min(l, cur);
        r = max(r, cur);
        
        if (grid[i+1][cur] == '.') {
            res++;
            i++;
            l = cur, r = cur;
            looped = false;
            continue;
        }
                
        if (dir) cur++;
        else cur--;
        res++;
        
        if (grid[i][cur] == '+') {
            grid[i][cur] = '.';
            l = min(l, cur);
            r = max(r, cur);
            dir = !dir;
            if (dir) cur++;
            else cur--;
            looped = false;
        } else if (grid[i][cur] == '#') {
            if (looped) {
                cout << "Never\n"; return 0;
            } else looped = true;
            dir = !dir;
            if (dir) cur++;
            else cur--;
        } else {
            looped = false;
            continue;
        }
        if (dir) {
            res += (r-cur);
            cur = r;
        } else {
            res += (cur-l);
            cur = l;
        }
        
    }
    
    cout << res << "\n";
	 
	return 0;
}

















