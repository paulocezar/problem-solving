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

int H[64], D[64], v[64];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int kases;
    cin >> kases;
    while (kases--) {
        
        int N;
        cin >> N;
        REP(i, N) cin >> H[i];
        REP(i, N) cin >> D[i];
        
        int S = 0;
        REP(i, N) {
            v[i] = (D[i]-H[i]);
            S += v[i];
        }
        
        int T = -1;
        
        if (N == 1) {
            if (v[0] <= 0) T = -v[0];
        } else if (N == 2) {
            if ((v[0]+v[1]) == 0) T = abs(v[0]);
        } else if ((S >= 0) && ((S % (N-2)) == 0)) {
            T = S / (N-2);
            int sum = 0;
            REP(i, N) {
                if ((T-v[i]) & 1) {
                    T = -1;
                    break;
                }
                int xi = (T-v[i]) / 2;
                if (xi < 0) {
                    T = -1;
                    break;
                }
                //cout << (T-v[i]) / 2 << endl;
                sum += xi;
            }
            if (sum != T) T = -1;
        } 
        
        cout << T << "\n";
    }  
        
	return 0;
}

















