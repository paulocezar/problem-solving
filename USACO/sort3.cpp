/*
ID: knightp2
PROG: sort3
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

int a[1024];

int cnt[4];
int ccnt[4][4];

int main(int argc, char* argv[]) {
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");	
    
    int N;
    fin >> N;
    REP(i,N) {
        fin >> a[i];
        cnt[ a[i] ]++;
    }
    
    int cur = 1;
    int cc = 0;
    REP(i,N) {
        ++cc;
        ccnt[ cur ][ a[i] ]++;
        if (cc == cnt[cur]) {
            ++cur;
            cc = 0;
        }
    }
    
    int res = 0;
    int swp12 = min(ccnt[1][2],ccnt[2][1]);
    res += swp12;
    ccnt[1][1] += swp12;
    
    int swp13 = min(ccnt[1][3],ccnt[3][1]);
    res += swp13;
    ccnt[1][1] += swp13;
    
    int swp23 = min(ccnt[2][3],ccnt[3][2]);
    res += swp23;
    
    res += 2*(cnt[1]-ccnt[1][1]);
    fout << res << "\n";
        
	return 0;
}

















