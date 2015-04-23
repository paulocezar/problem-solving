/*
ID: knightp2
PROG: cowfind
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

int bit[50005];
int n;


void up(int idx) {
    while (idx <= n) {
        bit[idx]++;
        idx += (idx & -idx);
    }
}


int get(int idx) {
    int res = 0;
    while (idx > 0) {
        res += bit[idx];
        idx -= (idx & -idx);
    }
    return res;
}

int main(int argc, char* argv[]) {
    ifstream fin("cowfind.in");
    ofstream fout("cowfind.out");	
    
    
    string s;
    fin >> s;
    
    n = SIZE(s);
    
    vector<int> xcand, ycand;
    
    REP(y,SIZE(s)-1) {
        if (s[y] == ')' && s[y+1] == ')')  up(y+1);
    }
    
    
    int res = 0;
    REP(x,SIZE(s)-1) {
        if (s[x] == '(' && s[x+1] == '(')  {
            res += get(n) - get(x+1);
        }
    }
    fout << res << "\n";
    
        
	return 0;
}

















