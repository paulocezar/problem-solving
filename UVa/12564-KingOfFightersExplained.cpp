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

struct rect_t {
  int x1, y1, x2, y2;
  rect_t (int a = 0, int b = 0, int c = 0, int d = 0) 
                                                 : x1(a), y1(b), x2(c), y2(d) {}
  int intersect(rect_t &r) {
      int xa = max(x1, r.x1);
      int xb = min(x2, r.x2);
      int ya = max(y1, r.y1);
      int yb = min(y2, r.y2);
      int dx = max(0, xb-xa);
      int dy = max(0, yb-ya);
      return dx*dy;
  }
  
};

rect_t at1[8], wk1[8];
rect_t at2[8], wk2[8];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    FOR(tc, 1, t) {
        
        bool first = false, second = false;
        
        int a1, w1, a2, w2;
        
        cin >> a1 >> w1;
        REP(i, a1)
            cin >> at1[i].x1 >> at1[i].y1 >> at1[i].x2 >> at1[i].y2;
        REP(i, w1)
            cin >> wk1[i].x1 >> wk1[i].y1 >> wk1[i].x2 >> wk1[i].y2;
        
        cin >> a2 >> w2;
        REP(i, a2)
            cin >> at2[i].x1 >> at2[i].y1 >> at2[i].x2 >> at2[i].y2;
        REP(i, w2)
            cin >> wk2[i].x1 >> wk2[i].y1 >> wk2[i].x2 >> wk2[i].y2;
        
        REP(i, a1) REP(j, w2) {
            if (at1[i].intersect(wk2[j])) second = true;
        }
        
        REP(i, a2) REP(j, w1) {
            if (at2[i].intersect(wk1[j])) first = true;
        }
        
        
        cout << "Case " << tc << ": ";
        
        if (first && second)
            cout << "Both\n";
        else if (first)
             cout << "First\n";
        else if (second) 
            cout << "Second\n";
        else cout << "Neither\n";
    }    
	 
	return 0;
}

















