/*
ID: knightp2
PROG: contact
LANG: C++
*/
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
#include <fstream>
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

bool comp(const string &a, const string &b) {
    if (SIZE(a) != SIZE(b)) return SIZE(a) < SIZE(b);
    return a < b;
}

int main(int argc, char* argv[]) {
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    
    int A, B, N;
    cin >> A >> B >> N;
    
    string ss, s = "";
    while (cin >> ss) s += ss;
    
    map<string, int> seen;
    
    FOR(len, A, B) {
        
        string cur = "";
        int i = 0;
        while (i < len && i < SIZE(s)) cur += s[i++];
        
        if (i != len) break;
        
        seen[cur]++;
        while (i < SIZE(s)) {
            cur.erase(cur.begin());
            cur += s[i++];
            seen[cur]++;
        } 
    }
    
    map<int, vector<string> > show;
    FORIT(x, seen) show[ x->second ].PB(x->first);
    
    map<int, vector<string> >::reverse_iterator it = show.rbegin();
    while (N--) {
        sort(ALL(it->second), comp);
        cout << it->first << "\n";
        int cnt = 0;
        REP(i, SIZE(it->second)) {
            if (cnt) cout << " ";
            cout << it->second[i];
            cnt++;
            if (cnt == 6 && i+1 != SIZE(it->second)) {
                cout << "\n";
                cnt = 0;
            }
        }
        cout << "\n";
        it++;
        if (it == show.rend()) break;
    }
        
	return 0;
}

















