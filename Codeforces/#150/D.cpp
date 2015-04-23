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

#define MAXN 100000
#define MAXM 100000

vector<int> gr[MAXN+1];
int u[MAXM], v[MAXM];

vector<int> inter(MAXN+1);

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m, h, t;
    cin >> n >> m >> h >> t;
    REP(i,m) {
        cin >> u[i] >> v[i];
        gr[u[i]].PB(v[i]);
        gr[v[i]].PB(u[i]);
    }
    
    FOR(i,1,n) sort(ALL(gr[i]));
    
    bool find = false;
    REP(i,m) {
        // u ~ heads
        // v ~ tail
        if (h < t) {
            if (SIZE(gr[v[i]]) < SIZE(gr[u[i]]))
                swap(u[i],v[i]);
        } else {
            if (SIZE(gr[v[i]]) > SIZE(gr[u[i]]))
                swap(u[i],v[i]);
        }
        
        if (SIZE(gr[u[i]]) > h && SIZE(gr[v[i]]) > t) {
            vector<int>::iterator it;
            it = set_intersection(ALL(gr[u[i]]), ALL(gr[v[i]]), inter.begin());
            
            int intr = it - inter.begin();
            
            int ru = SIZE(gr[u[i]]) - intr - 1;
            int rv = SIZE(gr[v[i]]) - intr - 1;
            
            int ndu = max(h - ru, 0);
            int ndv = max(t - rv, 0);
            
            if (ndu+ndv <= intr) {
                cout << "YES\n" << u[i] << " " << v[i] << "\n";
                
                set<int> seen;
                seen.insert(u[i]);
                seen.insert(v[i]);
                
                vector<int> uu, vv;
                REP(j,ndu) {
                    uu.PB(inter[j]);
                    seen.insert(inter[j]);
                }
                REP(j,ndv) {
                    vv.PB(inter[ndu+j]);
                    seen.insert(inter[ndu+j]);
                }
                
                int cur = 0;
                while (SIZE(uu) < h) {
                    while (seen.count(gr[u[i]][cur])) cur++;
                    uu.PB(gr[u[i]][cur]);
                    seen.insert(gr[u[i]][cur]);
                }
                
                cur = 0;
                while (SIZE(vv) < t) {
                    while (seen.count(gr[v[i]][cur])) cur++;
                    vv.PB(gr[v[i]][cur]);
                    seen.insert(gr[v[i]][cur]);
                }
                
                REP(j,h) {
                    if (j) cout << " ";
                    cout << uu[j];
                }
                cout << "\n";
                
                
                REP(j,t) {
                    if (j) cout << " ";
                    cout << vv[j];
                }
                cout << "\n";
                
                find = true;
                break;
            }                        
        }
    }
    
    if (!find) cout << "NO\n";
    
    return 0;
}

















