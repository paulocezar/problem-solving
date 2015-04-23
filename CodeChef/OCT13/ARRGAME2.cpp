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
#include <tr1/unordered_map>
#include <tr1/unordered_set>

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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

typedef double TYPE;


#define MAXN 100001

int x[MAXN], y[MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    cout << fixed << setprecision(13);
    
    int t;
    cin >> t;
    while (t--) {
        
        int N;
        cin >> N;

        REP(i, N) cin >> x[i];
        
        int cnt1 = 0, cnt2 = 0;
        REP(i, N) {
            cin >> y[i];
            if (y[i] == 1) cnt1++;
            else if (y[i] == 2) cnt2++;
        }
        sort(y, y+N, greater<int>() );
        
        int64 num = 0;        
        
        REP(i, N) {
            
            if (x[i] == 1) continue;
            
            num += cnt1;
            if (x[i] == 3) num += cnt2;             
            if (x[i] == 2) x[i] = 4;
            
            int lo = 0, hi = N-1;
            
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                
                if (y[mid] > x[i]) lo = mid+1;
                else hi = mid-1;     
            }
            
            num += lo;
        }
        
        cout << (double) num / N << "\n";
    }    
        
	return 0;
}



















