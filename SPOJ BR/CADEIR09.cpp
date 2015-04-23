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

int a[222][222];

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int L, C;
    cin >> L >> C;
    
    vector< pair<char, pair<int,int> > > ans;
    
    
    REP(i,L) REP(j,C) cin >> a[i][j];
    
    REP(i,L) {   
        int mn = 2e9;
        REP(j,C) mn = min(mn,a[i][j]);
        
        REP(j,C) {
            if(a[i][j] != mn) {
                FOR(k,j+1,C-1) if(a[i][k] == mn) {
                    if(!i) ans.PB( MP('C', MP(j+1,k+1)));
                    a[i][k] = a[i][j];
                    break;
                }
            }
            a[i][j] = mn++;
        }     
    }
    
    int mn = 1;
    REP(i,L) {
        if(a[i][0] != mn){
            FOR(k,i+1,L-1) if(a[k][0] == mn) {
                ans.PB( MP('L',MP(i+1,k+1)) );
                a[k][0] = a[i][0];
                break;
            }
        }
        mn += C;
    }
    
    cout << SIZE(ans) << "\n";
    REP(i,SIZE(ans)) {
        cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
    }
    
    return 0;
}
















