/*
ID: knightp2
PROG: hshoe
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

int di[4] = {1,-1,0,0};
int dj[4] = {0,0,1,-1};

bool seen[6][6];
string grid[6];

int n, mx, i, j, pref, len, res;

void go() {
    if (pref == 0) { res = max(res, len); return; }
    if (pref > mx) return;
    if (pref != len && len+pref < res) return;
    
    seen[i][j] = true;
    
    REP(dir,4) {
        i += di[dir];
        j += dj[dir];
        
        if (0 <= i && i < n && 0 <= j && j < n) {
            if (!seen[i][j]) {
                if (grid[i][j] == '(') {
                    if (pref == len) {
                        pref++;
                        len++;
                        go();
                        pref--;
                        len--;
                    }
                } else {
                    pref--;
                    len++;
                    go();
                    pref++;
                    len--;
                }
            }
        }
        
        i -= di[dir];
        j -= dj[dir];
    }
    
    seen[i][j] = false;
}

int main(int argc, char* argv[]) {
    ifstream fin("hshoe.in");
    ofstream fout("hshoe.out");	
        
    fin >> n;
    REP(x, n) fin >> grid[x];
    
    int opn = 0, cls = 0;
    REP(x, n) REP(y, n) { 
        if (grid[x][y] == '(') opn++;
        else cls++;
    }
    
    mx = (n*n)/2;
    mx = min(mx, opn);
    mx = min(mx, cls);
    
    res = 0;
    i = 0, j = 0, pref = 1, len = 1;
    
    if (grid[0][0] == '(') go();
    
    fout << res << "\n";
    
	return 0;
}

















