/*
ID: knightp2
PROG: maze1
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

#define MAXH 100
#define MAXW 38
string layout[2*MAXH+1];

vector< int > gr[MAXH*MAXW+1];
int dist[MAXH*MAXW+1];
int W, H;

int vert(int x, int y) {
    if (1 <= x && x <= H && 1 <= y && y <= W)
        return (x-1)*W + y;
    return 0;
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(int argc, char* argv[]) {
    ifstream fin("maze1.in");
    ofstream fout("maze1.out");	
    
    fin >> W >> H; fin.ignore();
    
    REP(i,2*H+1) getline(fin,layout[i]);
    
    REP(u,W*H+1) dist[u] = INF;
    dist[0] = 0;
    
    FOR(i,1,H) FOR(j,1,W) {
        
        int ri = 2*i - 1;
        int rj = 2*j - 1;
        
        REP(dir,4) if (layout[ri+dx[dir]][rj+dy[dir]] == ' ') {
            int u = vert(i,j);
            int v = vert(i+dx[dir],j+dy[dir]);
            gr[u].PB(v);
            if (v == 0) gr[v].PB(u);
        }
            
                        
    }
    
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        REP(i,SIZE(gr[u])) {
            int v = gr[u][i];
            if (dist[u]+1 < dist[v]) {
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    
    int mx = 0;
    REP(u,W*H+1) mx = max(mx,dist[u]);
    fout << mx << "\n";
        
	return 0;
}

















