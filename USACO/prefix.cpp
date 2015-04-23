/*
ID: knightp2
PROG: prefix
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

char seen[200002];
string pr[202];
string s;

int main(int argc, char* argv[]) {
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");	

    int p = 0;
    while (fin >> pr[p] && pr[p] != ".")  ++p;
    
    
    s = "";
    string x;
    while (fin >> x) s += x;
    
        
    int ans = 0;
    queue<int> q;
    q.push(0);
    seen[0] = 1;
    int N = SIZE(s);

    while (!q.empty()) {
        int pos = q.front(); q.pop();
        ans = max(ans,pos);
        if (ans == N) break;
        if (pos == N) continue;
        
        REP(pp,p) {
            int len = SIZE(pr[pp]);    
            if ((pos+len <= N) && !seen[pos+len]) {
                bool ok = true;
                REP(i,len) if (s[pos+i] != pr[pp][i]) {
                    ok = false; break;
                }
                if (ok) { seen[pos+len] = 1; q.push(pos+len); }  
            }
        }
    }

    fout << ans << "\n";
        
	return 0;
}

















