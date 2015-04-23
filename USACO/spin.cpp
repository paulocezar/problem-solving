/*
ID: knightp2
PROG: spin
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

int main(int argc, char* argv[]) {
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    
    int speed[5];
    vector< pair<int,int> > wedge[5];
    REP(i, 5) {
        cin >> speed[i];
        int n; cin >> n;
        while (n--) {
            int x, y;
            cin >> x >> y;
            wedge[i].PB(MP(x,(x+y)%360));
        }
    }
    
    int t = 0;
    while (t < 360) { 
        bool found = false;
        REP(deg, 360) {
            bool ok = true;
            REP(i, 5) {
                ok = false;
                REP(j, SIZE(wedge[i])) {
                    int x = (wedge[i][j].first + t*speed[i])%360;
                    int y = (wedge[i][j].second + t*speed[i])%360;
                    
                    if (x <= y) {
                        if (x <= deg && deg <= y) ok = true;
                    } else {
                        if (x <= deg && deg <= 359) ok = true;
                        if (0 <= deg && deg <= y) ok = true;
                    } 
                    if (ok) break;
                }
                if (!ok) break;
            }
            if (ok) { found = true; break; }
        }
        if (found) { cout << t << "\n"; break; }
        ++t;
    }
    if (t == 360) cout << "none\n";

	return 0;
}

















