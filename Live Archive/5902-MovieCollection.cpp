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

#define MAXN 100000
#define MAXM 100000

int bit[MAXN+MAXM+1];
int under[MAXN+1];
int bsz;

void up(int idx) {
    while (idx <= bsz) {
        bit[idx]++;
        idx += (idx & -idx);
    }
}

int get(int idx) {
    int res = 0;
    while (idx > 0) {
        res += bit[idx];
        idx -= (idx & -idx);
    }
    return res;
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        bsz = n+m;
        
        FOR(i,1,n) under[i] = n-i+1;
        
        int at = n;        
        while (m--) {
            int x; cin >> x;
            int runder = under[x] - get(under[x]-1);
            int above = n - runder;
            up(under[x]);
            under[x] = ++at;
            cout << above << (m?" ":"\n");
        }
                
        
        if(t) memset(bit,0,sizeof(int)*(bsz+1));
    }
    
    return 0;
}
















