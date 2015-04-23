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


int wut;
char nm[16];

inline void next_int() {
    wut = 0;
    char c = getchar_unlocked();
    while (!isdigit(c) && c != '-') c = getchar_unlocked();
    if (c == '-') {
        c = getchar_unlocked();
        while (isdigit(c)) {
            wut = 10*wut + (c-'0');
            c = getchar_unlocked();
        }
        wut = -wut;
    } else {
        while (isdigit(c)) {
            wut = 10*wut + (c-'0');
            c = getchar_unlocked();
        }   
    }
}

inline void next_str() {
    int ps = 0;
    nm[ps] = getchar_unlocked();
    while ('a' <= nm[ps] && nm[ps] <= 'z') {
        ps++;
        nm[ps] = getchar_unlocked();
    }
    nm[ps] = '\0';
}

int mtop = 0, stop = 0;

vector<string> ns;
vector<int> ss;
vector<int> ms;

void push() {
    if (SIZE(ss) < stop+1) ss.PB(wut), ns.PB(nm);
    else {
        ss[stop] = wut;
        ns[stop] = nm;
    }
    stop++;
    
    if (!mtop || wut <= ms[mtop-1]) {
        if (SIZE(ms) < mtop+1) ms.PB(wut);
        else ms[mtop] = wut;
        mtop++;
    }
}
    
void pop() {
    if (ss[stop-1] == ms[mtop-1]) mtop--;
    stop--;
}
    
int main(int argc, char* argv[]) {
	
	next_int();
    int n = wut;
        
    while (n--) {
        next_int();
    
        if (wut == -1) {
            int rem = 0;
            
            while (ms[mtop-1] != ss[stop-1]) {
                pop();
                rem++;
            }
            
            printf("%d %s\n", rem, ns[stop-1].c_str());
            pop();
            
        } else {
            next_str();
            if (wut) push(); 
        }
    }
	 
	return 0;
}

















