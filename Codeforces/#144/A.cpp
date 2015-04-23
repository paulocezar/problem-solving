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

int64 cycles(int64 n) {
    return (n*(n-1LL)*(n-2LL))/6LL;
}

vector<string> get(int64 k) {
    
    int n = 0;
    while (cycles(n) < k) ++n;
    
    int64 cur = cycles(n);
    vector<string> gr(n);
    REP(i,n) {
        gr[i] = "";
        REP(j,n) gr[i] += ((i==j)?'0':'1');
    }
    
    int i = 0, j = 1;
    int rem = n-2;
    while(cur > k) {
        gr[i][j] = gr[j][i] = '0';
        cur -= rem;
        rem--;
        j++;
        if (j == n) {
            ++i;
            if (i == n) break;
            j = i+1;
            rem = n-(j+1);
        }
    }
    
    if (cur == 0) return gr;
    vector<string> ngr = get(k-cur);
    
    int nn = SIZE(ngr);
    string none = "";
    REP(i,n) none += "0";
    
    REP(i,nn) gr.PB(none + ngr[i]);
    REP(i,n){
        REP(j,nn) gr[i] += "0";
    }
    return gr;
}

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int64 k;
    cin >> k;
    
    vector<string> res = get(k);
    cout << SIZE(res) << "\n";
    REP(i,SIZE(res)) cout << res[i] << "\n";
    
    
    return 0;
}
















