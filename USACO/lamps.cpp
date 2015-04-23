/*
ID: knightp2
PROG: lamps
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

bool fixedon[101], fixedoff[101], ison[101];

int main(int argc, char* argv[]) {
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");	
    
    int N;
    fin >> N;
    int C;
    fin >> C;
    
    int on;
    fin >> on;
    while (on != -1) {
        fixedon[on] = true;
        fin >> on;
    }
    
    int off;
    fin >> off;
    while (off != -1) {
        fixedoff[off] = true;
        fin >> off;
    }
    vector<string> ans;
    REP(mask,1<<4) {
        int odd = 0;
        REP(i,4) if (mask & (1<<i)) odd++;
        
        if ((odd & 1) == (C & 1)) {
            if (C >= odd) {
                
                FOR(x,1,N) ison[x] = true;
                
                if (mask & 1) FOR(x,1,N) ison[x] = !ison[x];
                if (mask & 2) FOR(x,1,N) if (x&1) ison[x] = !ison[x];
                if (mask & 4) FOR(x,1,N) if (!(x&1)) ison[x] = !ison[x];
                if (mask & 8) FOR(x,1,N) if (x%3 == 1) ison[x] = !ison[x];
                
                bool ok = true;
                FOR(x,1,N) if ((ison[x] && fixedoff[x]) || (!ison[x] && fixedon[x])) {
                    ok = false;
                    break;
                }
                if (ok) {
                    string res = "";
                    FOR(x,1,N) if(ison[x]) res += "1"; else res += "0";
                    ans.PB(res);
                } 
            }
        }                
    }
    
    sort(ALL(ans));
    if (SIZE(ans)) REP(i,SIZE(ans)) fout << ans[i] << "\n";
    else fout << "IMPOSSIBLE\n";
    
        
	return 0;
}

















