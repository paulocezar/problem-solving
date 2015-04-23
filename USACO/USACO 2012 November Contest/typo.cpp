/*
ID: knightp2
PROG: typo
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

#define MAXN 100010
int pref[MAXN], mn[MAXN];

int main(int argc, char* argv[]) {
    ifstream fin("typo.in");
    ofstream fout("typo.out");	
    
    string s;
    fin >> s;
    
    int n = SIZE(s);
    
    REP(i, n) {
        if (i) pref[i] = pref[i-1];
        
        if (s[i] == '(') pref[i]++;
        else pref[i]--;
    }
    
    mn[n-1] = pref[n-1];
    RREP(i,n-1) mn[i] = min(mn[i+1], pref[i]);
    
    int res = 0;
    
    bool neg = false;
    REP(i,n) {
        if (neg) break;
        if (s[i] == '(') {
            mn[i] -= 2;
            if (mn[i] >= 0 && pref[n-1] == 2) res++;
        } else { 
            mn[i] += 2;
            if (mn[i] >= 0 && pref[n-1] == -2) res++;
        }
        if (pref[i] < 0) neg = true;
    }
    
    fout << res << "\n";
        
	return 0;
}

















