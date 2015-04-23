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

#define MAXM 10001

int strange[MAXM];
int nxtstrg[MAXM];
double pstrg[MAXM];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
    int t;
    cin >> t;
    while (t--) {
        int N, M, P;
        cin >> N >> M >> P;
        
        REP(i, M) { cin >> strange[i]; pstrg[i] = 1.0; nxtstrg[i] = i+1; }
        sort(strange,strange+M);
        double pwin = double(P) / 100.0;
        
        int K = 0;
        while ((1<<K) != N) K++;
        
        REP(rnd,K) {
            int cur = 0;
            
            while (cur < M) {
                int nxt = nxtstrg[cur];
                
                bool compete = false;
                if (nxt < M) {
                    if (((strange[cur]+1)/2) == ((strange[nxt]+1)/2)) compete = true;
                }
                
                if (compete) {
                    
                    double np = (pstrg[nxt] * pstrg[cur]) 
                                + (pwin * pstrg[nxt] * (1.0 - pstrg[cur])
                                + (pwin * (1.0 - pstrg[nxt]) * pstrg[cur]));
                    pstrg[cur] = np;
                                        
                    strange[cur] = (strange[cur]+1)/2;
                    nxt = nxtstrg[nxt];
                    nxtstrg[cur] = nxt;
                } else { 
                    pstrg[cur] *= pwin;
                    strange[cur] = (strange[cur]+1)/2;
                }
                
                
                cur = nxt;
            }
        }
        
        cout << fixed << setprecision(14) << (100.0 * pstrg[0]) << "\n";
        
    }
	
	return 0;
}

















