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
    
    int n;
    cin >> n;
    vector<int> neg;
    
    int x;
    while (n--) {
        cin >> x; if (x < 0) neg.push_back(x);
    }
    cin >> x;
    sort(neg.begin(), neg.end());
    
    int nneg = SIZE(neg);
    int all = 0;
    int64 res = 0;
    while (nneg) {
        if (nneg >= x) {
            res -= int64(neg[nneg-1]+all) * int64(x);
            all -= (neg[nneg-1]+all);
            while (nneg && !(neg[nneg-1]+all)) nneg--;
        } else {
            res -= int64(neg[nneg-1]+all);
            nneg--;
        }
    }
    cout << res << "\n";
    
	return 0;
}

















