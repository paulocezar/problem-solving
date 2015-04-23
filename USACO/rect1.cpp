/*
ID: knightp2
PROG: rect1
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
    rect_t(int a = 0, int b = 0, int c = 0, int d = 0) 
                                                : x1(a), y1(b), x2(c), y2(d) {}
    bool intersect(rect_t &r) {
        int xa = max(x1, r.x1);
        int xb = min(x2, r.x2);
        int ya = max(y1, r.y1);
        int yb = min(y2, r.y2);
        return ((xa <= xb) && (ya <= yb));
    }
};


#define MAXN 1024
rect_t rect[MAXN];
int cc[MAXN];

int main(int argc, char* argv[]) {
    ifstream fin("rect1.in");
    ofstream fout("rect1.out");	
    
    int A, B, N;
    fin >> A >> B >> N;
    
    rect[0] = rect_t(0,0,A-1,B-1); cc[0] = 1;
        
    vector<int> xx, yy;
    xx.PB(0), xx.PB(A);
    yy.PB(0), yy.PB(B);
    
    FOR(i, 1, N) {
        fin >> rect[i].x1 >> rect[i].y1 >> rect[i].x2 >> rect[i].y2 >> cc[i];
        xx.PB(rect[i].x1), xx.PB(rect[i].x2);
        yy.PB(rect[i].y1), yy.PB(rect[i].y2);
        rect[i].x2--, rect[i].y2--;
    }
     
    sort(ALL(xx));
    sort(ALL(yy));
    
    xx.resize(unique(ALL(xx)) - xx.begin());
    yy.resize(unique(ALL(yy)) - yy.begin());
    
    rect_t cur;
    map<int, int> colorc;
    
    REP(i, SIZE(xx)-1) {
        cur.x1 = xx[i], cur.x2 = xx[i+1]-1;
        REP(j, SIZE(yy)-1) {
            cur.y1 = yy[j], cur.y2 = yy[j+1]-1;
            
            RFOR(k,N,0) if (cur.intersect(rect[k])) {
                colorc[cc[k]] += ((cur.x2-cur.x1+1)*(cur.y2-cur.y1+1));
                break;
            }
        }
    }
    
    FORIT(color,colorc) fout << color->first << " " << color->second << "\n";
        
	return 0;
}

















