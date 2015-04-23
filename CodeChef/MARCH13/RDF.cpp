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


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    cout << fixed << setprecision(13);
    
    while (t--) {
        
        int n, k;
        cin >> n >> k;
        
        if (k == 0) cout << n << "\n";
        else if (k >= n) cout << "0\n";
        else {
            
            double sum = (int64(n-k+1LL)*int64(n-k)) / 2LL;
            double asum = 0;
            
            double res = sum / ((double)n-k+1);
            int64 rem = n-k;
            int64 cur = n-k+2;
            
            REP(i,k-1) {
                sum -= rem;
                asum += sum / ((double)2+i);
                res = (res + asum) / ((double)cur);
                cur++;
                if (cur > 35) break;
                if (rem >= 1) rem--;
            }
            
            cout << res << "\n";
        }        
        
    }
    
	return 0;
}

















