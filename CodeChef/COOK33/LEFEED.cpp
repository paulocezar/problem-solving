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

int a[64];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    cout << fixed << setprecision(13);
    
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        
        FOR(i,1,N) cin >> a[i];
        a[0] = a[N+1] = -1;
        
        double chance[N+1];
        
        int len = 1;
        while (len <= N) {
            double res = 0.0;
            
            int i = 1;
            while ((i+len-1) <= N) {
                
                tr1::unordered_set<int> seen;
                
                double p = 1.0;
        
                FOR(j,i,i+len-1) {
                    
                    if (a[j] == 0) p *= (1.0 / M);
                    else seen.insert(a[j]);
                    
                    if (SIZE(seen) > 1) break;
                }
                if (SIZE(seen) <= 1) {
                    if (a[i-1] != -1) {
                        if (a[i-1] == 0) p *= (1.0 - (1.0/M));
                        else if (seen.count(a[i-1])) p = 0.0;
                    }
                    
                    if (a[i+len] != -1) {
                        if (a[i+len] == 0) p *= (1.0 - (1.0/M));
                        else if (seen.count(a[i+len])) p = 0.0;
                    }
                    
                    res +=  p ;
                }
                
                i++;
            }
            chance[len] = res;
            len++;
        }
        
        double res = 0.0;
        
        FOR(len,1,N) {
            
            double pp = chance[len];
            FOR(grt,len+1,N) {
                pp *= (1.0 - chance[grt]);
            }
            res += len * pp;
            
        }
        
        cout << res << "\n";
    }
    
    
    
	return 0;
}

















