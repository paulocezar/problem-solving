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



int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    string dia, p2, pp2;
        
    int d1, d2;
    int h1, h2, m1, m2, s1, s2;
    
    cin >> dia >> d1;
    cin >> h1 >> p2 >> m1 >> pp2 >> s1;
    
    cin >> dia >> d2;
    cin >> h2 >> p2 >> m2 >> pp2 >> s2;
    
    int64 t1 = ((d1*24 + h1)*60 + m1)*60 + s1;
    int64 t2 = ((d2*24 + h2)*60 + m2)*60 + s2;
    
    int64 tt = t2-t1;
    int ss = tt%60;
    tt /= 60;
    int mm = tt%60;
    tt /= 60;
    int hh = tt%24;
    tt /= 24;
    
    cout << tt << " dia(s)\n";
    cout << hh << " hora(s)\n";
    cout << mm << " minuto(s)\n";
    cout << ss << " segundo(s)\n";
	 
	return 0;
}

















