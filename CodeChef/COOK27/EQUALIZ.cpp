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

#define NUMCHOICES 10
int choice[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

#define MAXN 30

int a[MAXN];

int solve(int N) {
    
    REP(i, NUMCHOICES) if (N % choice[i] == 0) {
        if (N == choice[i]) return 1;
        int bucket = N / choice[i];
        return choice[i]*solve(bucket) + bucket;
    }

    return 0;
    
}


void show(int N, int from) {
    
    REP(i, NUMCHOICES) if (N % choice[i] == 0) {
        if (N == choice[i]) {
            cout << N;
            REP(j,N) cout << " " << from+j;
            cout << "\n";
            return;
        }
        int bucket = N / choice[i];
        REP(j,choice[i]) show(bucket, from+j*bucket);
        
        REP(j,bucket) {
            cout << choice[i];
            REP(k, choice[i]) cout << " " << from+k*bucket;
            cout << "\n";
            from++;
        }
        return;
    }
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int N; cin >> N;
        REP(i,N) cin >> a[i];
        cout << solve(N) << "\n";
        show(N,1);
    }
	
	return 0;
}

















