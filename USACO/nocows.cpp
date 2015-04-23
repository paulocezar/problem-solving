/*
ID: knightp2
PROG: nocows
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

const int mod = 9901;

bool calc[202][101];
bool calc2[202][101];
int dp[202][101];
int dp2[202][101];

int solve2(int n, int k) {
    if (k == 0) return 0;
    if (n == 1) return 1;
    if (k == 1) return ((n==1) ? 1 : 0); 
    int &res = dp2[n][k];
    if (calc2[n][k]) return res;
    calc2[n][k] = true;
    res = 0;
    int nn = n-1;
    
    for (int l = 1; l < nn; ++l) {
        res += (solve2(l,k-1) * solve2(nn-l,k-1))%mod;
        res %= mod;
    }
    return res;
}

int solve(int n, int k) {
    
    if (k == 1) return ((n==1)?1:0);
    
    int &res = dp[n][k];
    if (calc[n][k]) return res;
    calc[n][k] = true;
    res = 0;
    int nn = n-1;
    for (int l = 1; l < nn; ++l) {
        int a1 = solve(l,k-1) * solve(nn-l,k-1); // both exactaly k-1
        int a2 = solve2(l,k-2) * solve(nn-l,k-1); // left at most k-2, right exactaly k-1
        int a3 = solve(l,k-1) * solve2(nn-l,k-2); // left exactaly k-1, right at most k-2
        res += (a1+a2+a3)%mod;
        res %= mod;
    }
    return res;
}

int main(int argc, char* argv[]) {
    ifstream fin("nocows.in");
    ofstream fout("nocows.out");	
    
    int N, K;
    fin >> N >> K;
    fout << solve(N,K) << "\n";
        
	return 0;
}

















