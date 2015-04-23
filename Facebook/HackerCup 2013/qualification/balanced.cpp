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

string s;

int calc[128][128], last_calc;
bool memo[128][128];

inline bool okay(char c) {
    return (('a' <= c && c <= 'z') || (c == ' ') || (c == ':'));
}

bool balanced(int from, int to) {
    if (from > to) return true;
    
    bool &res = memo[from][to];
    if (calc[from][to] == last_calc) return res;
    calc[from][to] = last_calc;
    res = false;
    
    bool cool = true;
    FOR(i,from,to) {
        cool = cool && okay(s[i]);
        if (!cool) break;
    }
    if (cool) return (res = true);
    
    bool cooler = false;
    if (to == (from+1)) {
        if (s[from] == ':' && s[to] == ')') cooler = true;
        if (s[from] == ':' && s[to] == '(') cooler = true;
    }
    if (cooler) return (res = true);
    
    if (s[from] == '(' && s[to] == ')') {
        if (balanced(from+1, to-1)) return (res = true);
    }
    
    int mid = from;
    while (mid < to && !res) {
        res = balanced(from, mid) && balanced(mid+1, to);
        mid++;
    }

    return res;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T; cin.ignore();
    FOR(kase,1,T) {
        getline(cin, s);
        last_calc++;
        string res = (balanced(0,SIZE(s)-1) ? "YES\n": "NO\n");
        cout << "Case #" << kase << ": " << res;
    }
    
	 
	return 0;
}

















