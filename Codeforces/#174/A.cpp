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

#define MAXN 200000
int64 a[MAXN];
int64 add[MAXN];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    cout << fixed << setprecision(13);
    
    int n;
    cin >> n;
    
    int len = 1;
    a[0] = 0;
    add[0] = 0;
    
    int64 sum = 0LL;
    int ai, xi, ki;
    
    REP(i, n) {
        int cmd; cin >> cmd;
        switch (cmd) {
            case 1: cin >> ai >> xi;
                sum += int64(ai*xi);
                add[ai-1] += xi;
            break;
            case 2: cin >> ki;
                add[len] = 0;
                a[len] = ki;
                sum += ki;
                len++;
            break;
            case 3:
                add[len-2] += add[len-1];
                sum -= (a[len-1]+add[len-1]);
                len--;
            break;
        }
        cout << ((long double)sum) / ((long double)len) << "\n";
    }
    
    
	return 0;
}

















