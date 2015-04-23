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

char res[128], s[32];
    
int main( int argc, char* argv[] ){
    
    int N;
    scanf("%d", &N); getchar();
    gets(s);
    
    int K;
    int64 I;
    scanf("%d%lld",&K,&I);
    int cr = (K+1)/2;

    //N^fit < I
    
    int64 all = 1;
    int64 NN = N;
    int fit = (I != 1LL) ? (log(I-1LL)/log(N)) : 0;
    int xx = fit;
    
    while (xx) {
        if (xx & 1) all *= NN;
        NN *= NN;
        xx >>= 1;
    } 
    int fr = max(0,cr-fit-1);
    REP(i,cr) {
        int j = 0;
        if (i >= fr) {
            while (j < N) {
                if (I > all) I -= all;
                else break;
                j++;
            }
            all /= N;
        }
        res[i] = res[K-i-1] = s[j];
    }
    REP(i,K) putchar(res[i]);
    putchar('\n');
    
    return 0;
}
















