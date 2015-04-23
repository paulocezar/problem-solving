/*
ID: knightp2
PROG: island
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

int di[] = { 1, -1,  0,  0};
int dj[] = { 0,  0,  1, -1};

string grid[55];

int R, C;
int id[55][55], islands;

void flood(int i, int j) {
    id[i][j] = islands;
    REP(dir, 4) {
        int ni = i + di[dir];
        int nj = j + dj[dir];
        if ((0 <= ni) && (ni < R)
         && (0 <= nj) && (nj < C)
         && (grid[ni][nj] == 'X')
         && (id[ni][nj] == -1))
            flood(ni, nj);
    }
}

int dist[15][15];
int seen[55][55], seen_now;

int cost[15][1<<15];

int main(int argc, char* argv[]) {
    freopen("island.in", "r", stdin);
    freopen("island.out", "w", stdout);
    
    cin >> R >> C;
    REP(i, R) cin >> grid[i];
    
    memset(id,-1,sizeof(id));
    islands = 0;
    REP(i, R) REP(j, C) {
        if (id[i][j] != -1) continue;
        if (grid[i][j] != 'X') continue;
        flood(i,j);
        islands++;
    }
    
    REP(i, islands) REP(j, islands)
        dist[i][j] = (i==j)?(0):(INF);

    for (int island = 0; island < islands; ++island) {
        seen_now++;
        queue< pair<int,int> > q;

        REP(i, R) REP(j, C) {
            if (id[i][j] == island) {
                seen[i][j] = seen_now;
                q.push(MP(i,j));
            }
        }
        
        int depth = -1;
        
        while (!q.empty()) {
            depth++;
            int sz = SIZE(q);
            while (sz--) {
                int i = q.front().first;
                int j = q.front().second; q.pop();
            
                bool expand = true;
                if ((id[i][j] != -1) && (id[i][j] != island)) {
                    int od = dist[island][id[i][j]];
                    dist[island][id[i][j]] = min(od, depth-1);
                    expand = false;
                }

                if (expand) REP(dir, 4) {
                    int ni = i + di[dir];
                    int nj = j + dj[dir];
                    if ((ni < 0) || (nj < 0) || (ni >= R) || (nj >= C)) continue;
                    if ((grid[ni][nj] == 'X') || (grid[ni][nj] == 'S')) {
                        if (seen[ni][nj] != seen_now) {
                            seen[ni][nj] = seen_now;
                            q.push(MP(ni,nj));
                        }
                    }
                }
            }
        }
    }
    
    priority_queue< pair<int, pair<int,int> > > pq;
    int all = (1<<islands) - 1;
    
    for (int i = 0; i < islands; ++i) {
        for (int j = 0; j <= all; ++j)
            cost[i][j] = INF;
        cost[i][1<<i] = 0;
        pq.push(MP(0, MP(i, 1<<i)));
    }
    
    while (!pq.empty()) {
        int cc = -pq.top().first;
        int i = pq.top().second.first;
        int mask = pq.top().second.second; pq.pop();
        if (cc > cost[i][mask]) continue;

        if (mask == all) {
            cout << cc << "\n";
            break;
        }

        for (int j = 0; j < islands; ++j) {
            if ((cc + dist[i][j]) < cost[j][mask|(1<<j)]) {
                cost[j][mask|(1<<j)] = cc + dist[i][j];
                pq.push(MP(-cost[j][mask|(1<<j)], MP(j, mask|(1<<j))));
            }
        }

    }

	return 0;
}

















