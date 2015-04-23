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

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

#define MAXN 1024
string grid[MAXN];

int n, m, d;


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n >> m >> d;
    REP(i, n) cin >> grid[i];
    
    int rats = 0;
    REP(i, n) REP(j, m) if (grid[i][j] == 'R') rats++;
    
    
    vector< pair<int,int> > cand;
    int xa, ya, xb, yb;
    
    REP(j, m) {
        REP(i, n) {
            if (grid[i][j] == 'R') { 
                xa = i, ya = j;
                goto getnxt;
            }
        }
    }
    getnxt:
    RREP(j, m) {
        RREP(i, n) {
            if (grid[i][j] == 'R') { 
                xb = i, yb = j;
                goto getcand;
            }
        }
    }
    getcand:
    
    REP(i, n) REP(j, m) {
        if (grid[i][j] == 'X') continue;
        bool z1 = (xa-d <= i && i <= xa+d && ya-d <= j && j <= ya+d);
        bool z2 = (xb-d <= i && i <= xb+d && yb-d <= j && j <= yb+d);
    
        if (z1 || z2) cand.PB(MP(i,j));
    }
    
    bool fodel = true;
        
    REP(i, SIZE(cand)) {
        FOR(j, i+1, SIZE(cand)-1) {
                
            queue< pair<int,int> > q;
            map< pair<int,int>, int > seen;
            seen[cand[i]] = 0;
            seen[cand[j]] = 0;
                    
            q.push(cand[i]);
            q.push(cand[j]);
                
            int curcnt = 0;
            while (!q.empty()) {
                pair<int,int> cur = q.front(); q.pop();
                if (grid[cur.first][cur.second] == 'R') curcnt++;
                int dd = seen[cur] + 1;
                if (dd > d) continue;
                
                REP(dir, 4) {
                    cur.first += dx[dir];
                    cur.second += dy[dir];
                    
                    if (grid[cur.first][cur.second] != 'X') {
                        if (!seen.count(cur)) {
                            seen[cur] = dd;
                            q.push(cur);
                        }
                    }
                        
                    cur.first -= dx[dir];
                    cur.second -= dy[dir];
                }
            }
                
            if (curcnt == rats) {
                cout << cand[i].first+1 << " " << cand[i].second+1 << " ";
                cout << cand[j].first+1 << " " << cand[j].second+1 << "\n";
                fodel = false;
                goto hell;
            }
                
        }
    }
    hell:
        
    if (fodel) {
        
        REP(i, SIZE(cand)) {
            
            queue< pair<int,int> > q;
            map< pair<int,int>, int > seen;
            seen[cand[i]] = 0;
            q.push(cand[i]);
            
            int curcnt = 0;
            while (!q.empty()) {
                pair<int,int> cur = q.front(); q.pop();
                if (grid[cur.first][cur.second] == 'R') curcnt++;
                int dd = seen[cur] + 1;
                if (dd > d) continue;
                
                REP(dir, 4) {
                    cur.first += dx[dir];
                    cur.second += dy[dir];
                    
                    if (grid[cur.first][cur.second] != 'X') {
                        if (!seen.count(cur)) {
                            seen[cur] = dd;
                            q.push(cur);
                        }
                    }
                    
                    cur.first -= dx[dir];
                    cur.second -= dy[dir];
                }
            }
            
            if (curcnt == rats) {
                cout << cand[i].first+1 << " " << cand[i].second+1 << " ";
                REP(xx, n) REP(yy, m) {
                    if (grid[xx][yy] == 'X') continue;
                    if (xx != cand[i].first || yy != cand[i].second) {
                        cout << xx+1 << " " << yy+1 << "\n";
                        return 0;
                    }
                }
                fodel = false;
                break;
            }
            if (curcnt == rats-1) {
                cout << cand[i].first+1 << " " << cand[i].second+1 << " ";
                REP(xx, n) REP(yy, m) {
                    if (grid[xx][yy] != 'R') continue;
                    if (xx != cand[i].first || yy != cand[i].second) {
                        if (!seen.count(MP(xx,yy))) {
                            cout << xx+1 << " " << yy+1 << "\n";
                            return 0;
                        }
                    }
                }
                
                fodel = false;
                break;
            }
        }
        
        cout << "-1\n";
    }
    
	 
	return 0;
}

















