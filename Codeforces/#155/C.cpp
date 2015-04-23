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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

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

template<typename T> T inline SQR(const T &a) { return a*a; }
template<typename T> T inline ABS(const T &a) { return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN(double a){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP(double a, double b){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s, t;
    cin >> s >> t;
    
    map<char, int> cnts, cntt;
    
    REP(i, SIZE(s)) cnts[s[i]]++;
    REP(i, SIZE(t)) cntt[t[i]]++;
    
    int res = 0;
    
    map<char, int> rm;
    map<char, int> ad;
    
    for (char c = 'A'; c <= 'Z'; ++c) {
        res += abs(cnts[c]-cntt[c]);
        if (cnts[c] > cntt[c]) rm[c] += cnts[c]-cntt[c];
        if (cnts[c] < cntt[c]) ad[c] += cntt[c]-cnts[c];
    }
    res /= 2;
    cout << res << "\n";
	
    t = "";
    char nxt = 'A';
    while (nxt <= 'Z' && !ad[nxt]) nxt++;
    
    REP(i, SIZE(s)) {
        if (!rm[s[i]]) {
            t += s[i]; 
            cnts[s[i]]--;
        } else {
            if (nxt < s[i] || (nxt > s[i] && (cnts[s[i]]-1) < rm[s[i]])) {
                ad[nxt]--;
                cnts[s[i]]--;
                rm[s[i]]--;
                t += nxt;
            } else {
                cnts[s[i]]--;
                t += s[i];     
            }
        }
        while (nxt <= 'Z' && !ad[nxt]) nxt++;
    }
    cout << t << "\n";
    
	return 0;
}

















