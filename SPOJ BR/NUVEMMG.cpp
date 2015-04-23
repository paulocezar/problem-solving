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

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

pair<int,int> serv[555];

int dp[2][555];

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int K, L;
    while(cin >> K >> L && (K || L)) {
        
        REP(i,K) {
            int D, P;
            cin >> D >> P;
            serv[i] = MP(D,P);
        }
        sort(serv,serv+K);
        
        REP(i,K) dp[0][i] = (i+1)*serv[i].second;
        int old = 0;
        int cur = 1;
        
        FOR(types,2,L) {
            REP(pos,K) {
                dp[cur][pos] = 2e9;
                REP(bf,pos)
                    dp[cur][pos] = min(dp[cur][pos], (pos-bf)*serv[pos].second + dp[old][bf]);
            }
            old = !old;
            cur = !cur;
        }
        
        cout << dp[old][K-1] << "\n";
                
    }    
    
    return 0;
}
















