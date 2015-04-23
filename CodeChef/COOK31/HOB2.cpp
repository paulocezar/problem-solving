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

#define MAXN 314159

int ar[MAXN];
int in[MAXN];
int pr[MAXN];
int st[MAXN];

int rm[MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    while (t--) {
        
        int R, N;
        cin >> R >> N;
        int guests = 0;
        REP(i, N) st[i] = 0;
        REP(i, N) {
            cin >> ar[i] >> in[i];
            if (in[i] == R) {
                pr[i] = 0, st[i] = 1;
            } else {
                if (guests == R) {
                    st[rm[R-1]] = ar[i] - ar[rm[R-1]];
                    guests--;
                }
                pr[i] = guests - in[i];
                rm[guests] = i;
                guests++;
            }
        }
        
        
        REP(i, N) {
            if (st[i] == 0) st[i] = ar[N-1]+1; 
            cout << pr[i] << " " << st[i] << "\n";
        }
    }
    
	return 0;
}

















