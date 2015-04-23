/*
ID: knightp2
PROG: concom
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

int ocontrol[101][101], control[101][101];
bool own[101];

int main(int argc, char* argv[]) {
    ifstream fin("concom.in");
    ofstream fout("concom.out");	
    
    int n;
    fin >> n;
    while (n--) {
        int i, j, k;
        fin >> i >> j >> k;
        ocontrol[i][j] += k;
    }
    
    FOR(i,1,100) {
        
        memcpy(control,ocontrol,sizeof(ocontrol));
        
        FOR(j,1,100) own[j] = false;
        own[i] = true;
        while (true) {
            queue<int> q;
            FOR(j,1,100) {
                if (control[i][j] > 50 && !own[j]) q.push(j);
            }
            
            if (q.empty()) break;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                own[u] = true;
                FOR(j,1,100) control[i][j] += control[u][j];
            }
        }
        own[i] = false;
        FOR(j,1,100) if (own[j]) fout << i << " " << j << "\n";
        
    }
        
	return 0;
}

















