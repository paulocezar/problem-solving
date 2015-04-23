/*
ID: knightp2
PROG: humble
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

#define MAXK 128
int64 prime[MAXK];
int nxt[MAXK];

#define MAXN 100001
int64 humble[MAXN];


int main(int argc, char* argv[]) {
    ifstream fin("humble.in");
    ofstream fout("humble.out");	
    
    int K, N;
    fin >> K >> N;
    REP(i,K) {
        fin >> prime[i];
        nxt[i] = 0;
    }
    
    int seen = 0;
    humble[0] = 1;
    while (seen != N) {
                
        int64 best = 1LL<<33;
        int id = -1;
        
        REP(i,K) {
            while (humble[nxt[i]] * prime[i] <= humble[seen]) ++nxt[i];
            if (humble[nxt[i]]*prime[i] < best) {
                best = humble[nxt[i]] * prime[i];
                id = i;
            }
        }

        humble[++seen] = best;
        nxt[id]++;
        
    }
    fout << humble[N] << "\n";
        
	return 0;
}

















