/*
ID: knightp2
PROG: ttwo
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

string grid[10];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int seen[10*10*4*10*10*4];

int encode(int a, int b, int c, int d, int e, int f) {
    int res = a;
    res *= 10;  res += b;
    res *= 4;   res += c;
    res *= 10;  res += d;
    res *= 10;  res += e;
    res *= 4;   res += f;
    return res;
}

void decode(int &a, int &b, int &c, int &d, int &e, int &f) {
    f = a%4;    a /= 4;
    e = a%10;   a /= 10;
    d = a%10;   a /= 10;
    c = a%4;    a /= 4;
    b = a%10;   a /= 10;
}

void move(int &x, int &y, int &dir) {
    if (0 <= x+dx[dir] && x+dx[dir] < 10 && 0 <= y+dy[dir] && y+dy[dir] < 10) {
        if (grid[x+dx[dir]][y+dy[dir]] != '*') {
            x += dx[dir];
            y += dy[dir];
            return;
        }
    }
    dir++;
    if (dir == 4) dir = 0;
}

int main(int argc, char* argv[]) {
    ifstream fin("ttwo.in");
    ofstream fout("ttwo.out");	
    
    REP(i,10) fin >> grid[i];
    
    int xf, yf, df, xc, yc, dc;
    REP(x,10) REP(y,10) {
        if (grid[x][y] == 'C') xc = x, yc = y;
        if (grid[x][y] == 'F') xf = x, yf = y;        
    }
    
    df = 0, dc = 0;
    seen[ encode(xf,yf,df,xc,yc,dc) ] = 1;
    
    queue< int > q;
    q.push(encode(xf,yf,df,xc,yc,dc));
    
    while (!q.empty()) {
        xf = q.front(); q.pop();
        int cur = seen[xf];
        decode(xf,yf,df,xc,yc,dc);
        
        move(xf,yf,df);
        move(xc,yc,dc);
        
        if (xf == xc && yf == yc) {
            fout << cur << "\n";
            goto hell;
        }
        
        int ns = encode(xf,yf,df,xc,yc,dc);
        if (!seen[ns]) { seen[ns] = cur+1; q.push(ns); }
    }
    fout << "0\n";
hell:
	return 0;
}

















