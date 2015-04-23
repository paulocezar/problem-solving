/*
ID: knightp2
PROG: zerosum
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

string xpr;
int pos;

int eval() {
    if (pos == SIZE(xpr)) return 0;
    char sig = '+';
    if (!isdigit(xpr[pos])) sig = xpr[pos++];
    int res = 0;
    while (pos < SIZE(xpr) && isdigit(xpr[pos])) {
        res = 10*res + (xpr[pos]-'0');
        ++pos;
    }
    if (sig == '-') res = -res;
    return res + eval();
}

int main(int argc, char* argv[]) {
    ifstream fin("zerosum.in");
    ofstream fout("zerosum.out");	
    
    string op = " +-";
    
    int N;
    fin >> N;
    char n = char('0'+N);
    
    int masks = 1;
    REP(i,N-1) masks *= 3;
    
    vector< string > ans;
    REP(mask,masks) {
        xpr = "1";
        string pxpr = "1";
        
        int cur = mask;
        for (char c = '2'; c <= n; ++c) {
            pxpr += op[cur%3];
            if (cur%3) xpr += op[cur%3];
            
            cur /= 3;
            xpr += c;
            pxpr += c;
        }
        pos = 0;
        if (!eval()) ans.PB(pxpr);
    }
    sort(ALL(ans));
    REP(i,SIZE(ans)) fout << ans[i] << "\n";    
        
	return 0;
}

















