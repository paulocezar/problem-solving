/*
ID: knightp2
PROG: pprime
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

bitset< 10001 > bs;
vector<int> primes;

void sieve() {
    for (int i = 1; i <= 10000; ++i)
        bs[i] = i&1;
    bs[1] = false;
    bs[2] = true;
    
    for (int i = 3; i <= 100; i += 2) if (bs[i]) {
        for (int j = i*i; j <= 10000; j += i) bs[j] = false;
    }
   
    primes.PB(2);
    for (int i = 3; i <= 10000; i+=2) if (bs[i]) primes.PB(i);
}

bool isprime(int x) {
    if (x <= 10000) return bs[x];
    REP(i,SIZE(primes)) {
        if (x % primes[i] == 0) return false;
        if (primes[i]*primes[i] > x) break;
    }
    return true;
}

int a, b;
bool check(int x){  
    return (a <= x) && (x <= b) && isprime(x);  
}

int main(int argc, char* argv[]) {
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");	
    
    sieve();
    fin >> a >> b;
    
    vector<int> ans;
    for (int d1 = 1; d1 <= 9; ++d1) {
        int s1 = d1;
        if (check(s1)) ans.PB(s1);
        int s2 = 10*d1 + d1;
        if (check(s2)) ans.PB(s2);
        for (int d2 = 0; d2 <= 9; ++d2) {
            int s3 = 100*d1 + 10*d2 + d1;
            if (check(s3)) ans.PB(s3);
            int s4 = 1000*d1 + 100*d2 + 10*d2 + d1;
            if (check(s4)) ans.PB(s4);
            for (int d3 = 0; d3 <= 9; ++d3) {
                int s5 = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
                if (check(s5)) ans.PB(s5);
                int s6 = 100000*d1 + 10000*d2 + 1000*d3 + 100*d3 + 10*d2 + d1;
                if (check(s6)) ans.PB(s6);
                for (int d4 = 0; d4 <= 9; ++d4) {
                    int s7 = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;    
                    if (check(s7)) ans.PB(s7);
                    int s8 = 10000000*d1 + 1000000*d2 + 100000*d3 + 10000*d4 + 1000*d4 + 100*d3 + 10*d2 + d1;    
                    if (check(s8)) ans.PB(s8);
                }
            }
        }
    }
    
    sort(ALL(ans));
    REP(i,SIZE(ans)) fout << ans[i] << "\n";
        
	return 0;
}

















