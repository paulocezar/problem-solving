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
    vector<int> pos, neg, zer;
    REP(i,n) {
        int a; cin >> a;
        if (a < 0) neg.PB(a);
        else if (a > 0) pos.PB(a);
        else zer.PB(a);
    }

    if (pos.empty()) {
        pos.PB(neg.back()); neg.pop_back();
        pos.PB(neg.back()); neg.pop_back();
    }
    if (!(SIZE(neg) & 1)) {
        zer.PB(neg.back()); neg.pop_back();
    }
    
    cout << SIZE(neg);
    REP(i, SIZE(neg)) cout << " " << neg[i];
    cout << "\n";

    cout << SIZE(pos);
    REP(i, SIZE(pos)) cout << " " << pos[i];
    cout << "\n";

    cout << SIZE(zer);
    REP(i, SIZE(zer)) cout << " " << zer[i];
    cout << "\n";

	return 0;
}

















