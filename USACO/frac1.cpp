/*
ID: knightp2
PROG: frac1
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

bool comp(pair<int,int> a, pair<int,int> b) {
    return (b.second * a.first) < (b.first * a.second); 
}

int main(int argc, char* argv[]) {
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");	
    
    int N;
    fin >> N;
    
    int den = 1;
    vector< pair<int,int> > res;
    while (den <= N) {
        
        int num = 0;
        while (num <= den) {
            if (__gcd(num,den) == 1) res.PB(MP(num,den)); 
            ++num;
        }
        
        ++den;
    }
    sort(ALL(res), comp);
    REP(i,SIZE(res)) fout << res[i].first << "/" << res[i].second << "\n";
        
	return 0;
}

















