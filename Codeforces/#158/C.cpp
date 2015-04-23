#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <deque>
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

#define MAXN 100000
int64 a[MAXN+10];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, x;
    cin >> n >> x;
    
    int64 mn = int64(2e9);
    vector<int> pos;
    
    FOR(i, 1, n) {
        cin >> a[i];
        if (a[i] < mn) {
            pos.clear();
            mn = a[i];
            pos.PB(i);
        } else if (a[i] == mn) pos.PB(i);
    }
    
    FOR(i, 1, n) a[i] -= mn;
    
    if (a[x] == 0) { // i = x
        a[x] = int64(n) * mn;
    } else {
        int p = lower_bound(ALL(pos), x) - pos.begin();
        p--;
        if (p >= 0) { // i < x
            int i = pos[p];
            int64 ax = n*mn;            
            FOR(j, i+1, x) { a[j]--; ax++; }
            a[i] = ax;
        } else {
            int i = pos[SIZE(pos)-1];
            int64 ax = int64(n) * mn;
            FOR(j, 1, x) { ax++; a[j]--; }
            FOR(j, i+1, n) {ax++; a[j]--; }
            a[i] = ax;
        }
        
    }
    
    
    FOR(i, 1, n) {
        if (i != 1) cout << " ";
        cout << a[i];
    }
    cout << "\n";
    
	return 0;
}

















