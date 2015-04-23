/*
ID: knightp2
PROG: runround
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

int64 ans, N;

int num[10];
int pos, used;
bool seen[10];

bool check() {
    REP(i,pos) seen[i] = false;
    seen[0] = true;
    int ns = 0;
    int cur = 0;
    do {
        seen[cur] = true;
        ns++;
       int nxt = cur;
       REP(x,num[cur]){
           nxt++;
           if (nxt == pos) nxt = 0; 
       }
       cur = nxt;
    } while (!seen[cur]);
    return (ns == pos && cur == 0);
}


void gen(int64 val) {
    
    if (val > N) {
        if (check()){
            ans = min(ans, val);
            return;
        }
    }
    if (val > ans) return;
    
    for (int dig = 1; dig <= 9; ++dig) {
        if (used & (1<<dig)) continue;
        used |= 1<<dig;
        num[pos++] = dig;
        gen(10LL*val + dig);
        used ^= 1<<dig;
        --pos;
    }
    
}
    
int main(int argc, char* argv[]) {
    ifstream fin("runround.in");
    ofstream fout("runround.out");	
    
    fin >> N;
    
    pos = 0;
    ans = 2e15;
    used = 0;
    gen(0);
    
    fout << ans << "\n";
        
	return 0;
}

















