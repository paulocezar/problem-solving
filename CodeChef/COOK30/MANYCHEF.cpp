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

#define MAXN 2014

string s;
int n;

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
   string chef = "FEHC";
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        n = SIZE(s);
        RREP(i, n) {
            if (s[i] == '?' || s[i] == 'F') {
                int cool = 0;
                REP(j, 4) cool += (((s[i-j]==chef[j])||(s[i-j]=='?'))?(1):(0));
                if (cool == 4) {
                    REP(j, 4) s[i-j] = chef[j];
                } else if (s[i] == '?') s[i] = 'A';
            }
        }
        cout << s << "\n";
    }

	return 0;
}

















