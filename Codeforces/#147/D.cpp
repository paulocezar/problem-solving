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

#define FILL(X, V) memset((X), (V), sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = (a).begin(); i != (a).end(); ++i)

#define PB push_back
#define MP make_pair
    
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

const double EPS = 1e-9;
inline int SGN(double a) {
    return ((a > EPS)?(1):((a < -EPS)?(-1):(0)));
}
inline int CMP(double a, double b) {
    return SGN(a - b);
}

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bool leaf[100001];

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	
    int n;
    
    cin >> n;
    cout << n-1 << "\n";
    
    vector< int > l[n+1], r[n+1];
    REP(i,n-1) {
        int u, v; cin >> u >> v;
        cout << "2 " << u << " " << v << "\n";
        l[ min(u,v) ].PB(i+1);
        r[ max(u,v) ].PB(i+1);
    }
    
    FOR(i,1,n) {
        int a = SIZE(l[i]);
        int b = SIZE(r[i]);
        
        if (a > 1) REP(j,a-1) cout << l[i][j] << " " << l[i][j+1] << "\n";
        if (b > 1) REP(j,b-1) cout << r[i][j] << " " << r[i][j+1] << "\n";    
        if (a && b) cout << l[i][0] << " " << r[i][0] << "\n";
        
    }
       
	
	return 0;
}

















