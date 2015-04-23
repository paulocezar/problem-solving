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
#include <fstream>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define FILL(X, V) memset((X), (V), sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = (a).begin(); i != (a).end(); ++i)

#define PB push_back
#define MP make_pair
    
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

const double EPS = 1e-9;
inline int SGN(double a) {
    return ((a > EPS)?(1):((a < -EPS)?(-1):(0)));
}
inline int CMP(double a, double b) {
    return SGN(a - b);
}

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 128

int n;

string s;
int ss[MAXN];

bool calcmax[MAXN][2];
bool calcmin[MAXN][2];
int dp[MAXN][2];

int minimize(int pos, int last) {
    if (pos == n) return 0;
    
    int &res = dp[pos][last];
    
    if (calcmin[pos][last]) return res;
    calcmin[pos][last] = true;
    
    res = 0;
        
    if (ss[pos] == -1) {
        res = min(minimize(pos+1,last), 1+minimize(pos+1,1-last));
    } else {
        if (ss[pos] == last) {
            res = minimize(pos+1,last);
        } else res = 1 + minimize(pos+1,1-last);    
    }
    return res;
}


int maximize(int pos, int last) {
    if (pos == n) return 0;
    
    int &res = dp[pos][last];
    
    if (calcmax[pos][last]) return res;
    calcmax[pos][last] = true;
    
    res = 0;
        
    if (ss[pos] == -1) {
        res = max(maximize(pos+1,last), 1+maximize(pos+1,1-last));
    } else {
        if (ss[pos] == last) {
            res = maximize(pos+1,last);
        } else res = 1 + maximize(pos+1,1-last);    
    }
    return res;
}

int main(int argc, char* argv[]) {
	ifstream fin("rle-size.in");
    ofstream fout("rle-size.out");	
    
    fin >> n;
    fin >> s;
    
    REP(i,n) {
        switch(s[i]) {
            case '+': ss[i] = 0; break;
            case '-': ss[i] = 1; break;
            case '?': ss[i] = -1; break;
        }
    }
    
    if (s[0] == '?') {
        fout << (1+min(minimize(1,0),minimize(1,1))) << " " << (1+max(maximize(1,0),maximize(1,1))) << "\n";
    } else fout << (1+minimize(1,ss[0])) << " " << (1+maximize(1,ss[0])) << "\n";
    
	return 0;

}
