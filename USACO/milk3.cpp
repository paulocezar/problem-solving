/*
ID: knightp2
PROG: milk3
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

char seen[21][21][21];

struct state_t{
    int a, b, c;
    explicit state_t(int aa = 0, int bb = 0, int cc = 0) : a(aa), b(bb), c(cc) {}
};

int main(int argc, char* argv[]) {
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");	
    
    int cap[3];
    REP(i,3) fin >> cap[i];
    
    seen[0][0][cap[2]] = 1;
    
    queue< state_t > q;
    q.push(state_t(0,0,cap[2]));
    
    int cur[3], nxt[3];
    
    while (!q.empty()) {
        cur[0] = q.front().a;
        cur[1] = q.front().b;
        cur[2] = q.front().c; q.pop();
        
        REP(i,3) REP(j,3) {
            if (i == j) continue;
            REP(k,3) nxt[k] = cur[k];
            int trns = min(cur[i],cap[j]-cur[j]);
            nxt[i] -= trns;
            nxt[j] += trns;
            if (!seen[nxt[0]][nxt[1]][nxt[2]]) {
                seen[nxt[0]][nxt[1]][nxt[2]] = true;
                q.push(state_t(nxt[0],nxt[1],nxt[2]));
            }
        }
    }
    
    bool f = true;
    FOR(c,0,cap[2]) {
        if (seen[0][cap[2]-c][c]) {
            if (f) f = false;
            else fout << " ";
            fout << c;
        }
    }
    fout << "\n";
    
    
	return 0;
}

















