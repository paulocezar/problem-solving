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

vector<int> gr[16];


int dist[15][1<<15];
int pa[2][15][1<<15];
int seen[15][1<<15], seen_now, n;

void show(int u, int m) {
    if (pa[0][u][m] == -1) return;
    
    if (u != pa[0][u][m]) {
        show(pa[0][u][m], m);
        cout << (pa[0][u][m]+1) << " " << (u+1) << "\n";
    } else {
        show(u, pa[1][u][m]);
        int old, cur;
        REP(i, n) {
            if ((pa[1][u][m] & (1<<i)) && !(m & (1<<i))) old = i;
            else if (!(pa[1][u][m] & (1<<i)) && (m & (1<<i))) cur = i;
        } 
        cout << (old+1) << " " << (cur+1) << "\n";
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    FOR(kase, 1, T) {
        int m, s, t;
        cin >> n >> m >> s >> t;
        
        s--, t--;
        
        REP(i, n) gr[i].clear();
        
        int mask = 0;
        REP(i, m) {
            int u; cin >> u; u--;
            mask |= (1<<u);
        }
        
        REP(i, n-1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            
            gr[u].PB(v);
            gr[v].PB(u);
        }
        
        bool ok = false;
        cout << "Case " << kase << ": ";
        
        seen_now++;
        
        queue< pair<int,int> > q;
        q.push( MP(s, mask));
        seen[s][mask] = seen_now;
        dist[s][mask] = 0;
        pa[0][s][mask] = -1;
        
        while (!q.empty()) {
            int uu = q.front().first;
            int mm = q.front().second; q.pop();
            int dd = dist[uu][mm];
            
            //cout << ":: " << uu << " - ";
            //REP(i,n) if (mm & (1<<i)) cout << 1; else cout << 0; 
            //cout << endl;
            
            if (uu == t) {
                ok = true;
                cout << dd << "\n";
                show(uu, mm);
                break;
            }
            
            REP(i, SIZE(gr[uu])) {
                int v = gr[uu][i];
                if (mm & (1<<v)) continue;
                if (seen[v][mm] == seen_now) continue;
                
                seen[v][mm] = seen_now;
                dist[v][mm] = dd+1;
                pa[0][v][mm] = uu;
                pa[1][v][mm] = mm;
                q.push(MP(v,mm));
            }
            
            REP(i, n) {
                if (mm & (1<<i)) {
                    
                    REP(j, SIZE(gr[i])) {
                        int v = gr[i][j];
                        if (mm & (1<<v)) continue;
                        if (v == uu) continue;
                        int nm = mm;
                        nm ^= (1<<i);
                        nm |= (1<<v);
                        if (seen[uu][nm] == seen_now) continue;
                
                        seen[uu][nm] = seen_now;
                        dist[uu][nm] = dd+1;
                        pa[0][uu][nm] = uu;
                        pa[1][uu][nm] = mm;
                        q.push(MP(uu,nm));
                        
                    }
                }
            }
        }
        
        if (!ok) cout << "-1\n";
        cout << "\n";
        
    }
	 
	return 0;
}

















