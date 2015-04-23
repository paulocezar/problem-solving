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
#include <random>

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
	
    default_random_engine gen, gen2;    
    uniform_int_distribution<int> dm1(2,100);
    uniform_int_distribution<int> dm2(2,100000);
    
    string tin[] = {"", "1.in", "2.in", "3.in", "4.in", "5.in", "6.in", "7.in", "8.in", "9.in", "10.in", "11.in", "12.in", "13.in", "14.in", "15.in" };
    
    FOR(test, 1, 5) {
       freopen(tin[test].c_str(), "w", stdout); 
       int N = dm1(gen);
       default_random_engine eng;
       uniform_int_distribution<int> agen(0,1000000006);
       cout << N << "\n";
       REP(i, N) cout << agen(eng) << " ";
       cout << "\n";
    }
    FOR(test, 6, 10){
        freopen(tin[test].c_str(), "w", stdout);
        int N = dm2(gen2);
        default_random_engine eng;
        uniform_int_distribution<int> agen(0,1000000006);
        cout << N << "\n";
        REP(i, N) cout << agen(eng) << " ";
        cout << "\n";
    }
    FOR(test, 11, 15) {
        freopen(tin[test].c_str(), "w", stdout);
        int N = 100000;
        default_random_engine eng;
        uniform_int_distribution<int> agen(0,1000000006);
        cout << N << "\n";
        REP(i, N) cout << agen(eng) << " ";
        cout << "\n";
    }   
	 
	return 0;
}

















