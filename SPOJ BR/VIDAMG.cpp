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

int ds[][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

int main( int argc, char* argv[] ){
    
    ios::sync_with_stdio( false );
    
    int N;
    while (cin >> N && N) {
        
        set< pair<int,int> > alive[2];
        queue< pair<int,int> > q;
        
        REP(i,N) {
            int x, y;
            cin >> x >> y;
            alive[0].insert(MP(x,y));
            q.push(MP(x,y));
        }
        int old = 0, cur = 1;
        int K;
        cin >> K;     
        REP(stp,K) {
            alive[cur].clear();
            map< pair<int,int>, int > ng;
            
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second; q.pop();
                
                REP(dir,8) ng[MP(x+ds[dir][0], y+ds[dir][1])]++;
            }
            
            FORIT(cand,ng) {
                int na = cand->second;
                if(na < 2) continue;
                if(na > 3) continue;
                if(alive[old].count(cand->first) || na == 3) {
                    alive[cur].insert(cand->first);
                    q.push(cand->first);
                }
            }
            
            swap(old,cur);
        }    
        cout << SIZE(alive[old]) << "\n";
        FORIT(cell,alive[old]) cout << cell->first << " " << cell->second << "\n";
        
    }
    
    return 0;
}
















