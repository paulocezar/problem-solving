/*
ID: knightp2
PROG: castle
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

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int grid[64][64];
int comp[64][64];
int compsz[64*64];

int N, M, cur_comp;

void flood(int x, int y) {
    compsz[comp[x][y]]++;
    for (int dir = 0; dir < 4; ++dir) {
        if (grid[x][y] & (1<<dir)) continue;
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if (!comp[nx][ny]) {
            comp[nx][ny] = cur_comp;
            flood(nx,ny);
        }
    }
} 

int main(int argc, char* argv[]) {
    ifstream fin("castle.in");
    ofstream fout("castle.out");	
    
    fin >> M >> N;
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            fin >> grid[i][j];
    
    cur_comp = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!comp[i][j]) {
                cur_comp++;
                comp[i][j] = cur_comp;
                flood(i,j);
            }
        }
    }
    fout << cur_comp << "\n";
    int largest = 0;
    for (int room = 1; room <= cur_comp;  ++room) largest = max(largest, compsz[room]);
    fout << largest << "\n";
    
    int joint = 0, bx, by, bd;
    for (int y = 0; y < M; ++y) {
    for (int x = N-1; x >= 0; --x) {
            for (int dir = 0; dir < 4; ++dir) {
                if (grid[x][y] & (1<<dir)) {
                    int nx = x+dx[dir];
                    int ny = y+dy[dir];
                    if (nx == N || ny == M || nx == -1 || ny == -1) continue;
                    if (comp[x][y] != comp[nx][ny]) {
                        int njoint = compsz[comp[x][y]] + compsz[comp[nx][ny]];
                        if (njoint > joint) {
                            joint  = njoint;
                            bx = x, by = y, bd = dir;
                        }
                    }
                }
            }                        
        }
    }
    fout << joint << "\n";
    
    char bdr;
    switch(bd) {
        case 0: bdr = 'W'; break;
        case 1: bdr = 'N'; break;
        case 2: bdr = 'E'; break;
        case 3: bdr = 'S'; break;
    }
    
    fout << (bx+1) << " " << (by+1) << " " << bdr << "\n";   
	return 0;
}

















