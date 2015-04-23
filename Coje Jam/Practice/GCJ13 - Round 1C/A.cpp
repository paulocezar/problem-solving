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

inline bool cons(const char &c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int cpos[1<<20];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int kases;
    cin >> kases;
    FOR(kase,1,kases) {
        string name; int n;
        cin >> name >> n;
        
        int L = SIZE(name);
        int64 res = 0LL;
       
        int pc = 0;
        REP(i,L) if (cons(name[i])) cpos[pc++] = i;
        
        int last = -1;

        REP(x,pc) {
            if ((x+n-1) >= pc) break;
            int i = cpos[x];
            int j = cpos[x+n-1];
            if ((j-i+1) == n) {
                res += int64(i-last) * int64(L-j);
                last = i;
            }
        }
        cout << "Case #" << kase << ": " << res << "\n";
    }
    
	return 0;
}

















