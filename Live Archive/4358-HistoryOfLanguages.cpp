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

int autA[2001][26];
int autB[2001][26];
int fA[2001], fB[2002];

int seen[2001][2001], seen_now;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    int T;
    int tc = 1;
    while (cin >> T && T) {
        int nA;
        cin >> nA;
        REP(i,nA) {
            cin >> fA[i];
            REP(j,T) {
                cin >> autA[i][j];
                if (autA[i][j] == -1) autA[i][j] = nA;
            }
        }
        
        int nB;
        cin >> nB;
        REP(i,nB) {
            cin >> fB[i];
            REP(j,T) {
                cin >> autB[i][j];
                if (autB[i][j] == -1) autB[i][j] = nB;
            }
        }
        
        fA[nA] = 0;
        fB[nB] = 0;
        REP(i,T) {
            autA[nA][i] = nA;
            autB[nB][i] = nB;
        }
        
        queue< pair<int,int> > q;
        q.push(MP(0,0));
        seen[0][0] = ++seen_now;
        bool ok = (fA[0] == fB[0]);
    
        while (ok && !q.empty()) {
            
            int u = q.front().first;
            int v = q.front().second; q.pop();
                        
            REP(i,T) {
                int nu = autA[u][i];
                int nv = autB[v][i];
                if (fA[nu] != fB[nv]) {
                    ok = false; goto hell;
                }
                if (seen[nu][nv] != seen_now) {
                    q.push(MP(nu,nv));
                    seen[nu][nv] = seen_now;
                }
            }
            
        }
    hell:
        
        cout << "Case #" << tc << ": " << (ok?"Yes\n":"No\n"); 
        ++tc;            
    }    
    
	
	
	return 0;
}

















