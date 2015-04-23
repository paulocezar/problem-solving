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

int dis[16];
int u[128], v[128], c[128];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
    int t;
    cin >> t;
    while (t--) {
        
        int n;
        cin >> n;
        
        for (int i = 0; i <= n; ++i) dis[i] = 0;
        
        int ed = 0;
        for(int i = 1; i <= n; ++i) {
            char sg; cin >> sg;
            
            int c1 = -10, c2 = 10;
            switch (sg) {
                case '0': c1 = 0, c2 = 0; break; 
                case '+': c1 = 1; break;
                case '-': c2 = -1; break;
            }
            
            u[ed] = i-1, v[ed] = i, c[ed] = c2; ++ed;
            u[ed] = i, v[ed] = i-1, c[ed] = -c1; ++ed;
                        
            
            for (int j = i+1; j <= n; ++j) {
                cin >> sg;
                switch (sg) {
                    case '+':
                        u[ed] = j, v[ed] = i-1, c[ed] = -1; ++ed;
                        break;
                    case '-':
                        u[ed] = i-1, v[ed] = j, c[ed] = -1; ++ed;
                        break;
                    case '0':
                        u[ed] = j, v[ed] = i-1, c[ed] = 0; ++ed;
                        u[ed] = i-1, v[ed] = j, c[ed] = 0; ++ed;
                        break;
                }
            }
        }
        
        //REP(i,ed) cout << u[i] << " " << v[i] << "  " << c[i] << endl;
        
        bool change = true;
        while (change) {
            change  = false;
            
            REP(i,ed) {
                if (dis[ u[i] ] + c[ i ] < dis[ v[i] ]) {
                    dis[ v[i] ] = dis[ u[i] ] + c[ i ];
                    change = true;
                }
            }
            
        }
        
        REP(i,n) {
            if (i) cout << " ";
            cout << dis[i+1]-dis[i];
        }
        cout << "\n";
    }
	
	
	return 0;
}

















