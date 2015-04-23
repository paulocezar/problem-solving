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
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 100000
int p[MAXN], f[MAXN], id[MAXN];

bool comp(int i, int j) {
    return (p[i]+f[i]) > (p[j]+f[j]);
}

int next_int(){
    int res = 0;
    char c = getchar_unlocked();
    while (!isdigit(c)) c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    return res;
}

int main( int argc, char* argv[] ){
    
    int N = next_int();
    
    int total_weight = 0;
    REP(i,N) {
        p[i] = next_int();
        f[i] = next_int();
        total_weight += p[i];
        id[i] = i;
    }
    
    sort(id,id+N,comp);
    
    priority_queue<int> q;
    
    int *seen = id;
    int *add = id;
    int *end = id+N;
    while (add != end) {
    
        while (seen != end && f[*seen] >= total_weight-p[*seen]) { q.push(-(*seen)); seen++; }
        
        if (q.empty()) break;
        total_weight -= p[-q.top()];
        *add = 1-q.top(); q.pop(); add++;
    }
    
    if (add != end) puts("IMPOSSIVEL");
    else REP(i,N) printf("%d\n", id[i]);
    
    return 0;
}
















