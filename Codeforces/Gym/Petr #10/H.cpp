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

#define MAX2KN 100100
pair<int, int> a[MAX2KN];


vector< vector<int> > grp;

int main(int argc, char* argv[]) {
	ifstream fin("students.in");
    ofstream fout("students.out");
    
    int k, n;
    fin >> k >> n;
    
    grp.resize(n);
    REP(i,n) grp[i] = vector<int>();
    
    int nn = 2*k*n;
    
    REP(i,nn) fin >> a[i].first;
    REP(i,nn) fin >> a[i].second;
    
    sort(a,a+nn);
    
    int lwr = 0, upr = 0;
    int lct = 0, uct = 0;
    
    int res = 0;
    REP(i,nn) {
        
        if (a[i].second == 0) {
            if (lwr < n) {
                grp[lwr].PB(a[i].first);
                lct++;
                res++;
                if (lct == k) {
                    lwr++;
                    lct = 0;
                }
            } else {
                grp[upr].PB(a[i].first);
                uct++;
                if (uct == k) {
                    upr++;
                    uct = 0;
                }
            }           
        } else {
            if (upr < lwr) {
                grp[upr].PB(a[i].first);
                uct++;
                res++;
                if (uct == k) {
                    upr++;
                    uct = 0;
                }
            } else {
                grp[lwr].PB(a[i].first);
                lct++;
                if (lct == k) {
                    lwr++;
                    lct = 0;
                }
            }
        }
    }
    fout << res << "\n";
    REP(i,n) {
        REP(j,SIZE(grp[i])) {
            if (j) fout << " ";
            fout << grp[i][j];
        }
        fout << "\n";
    }
	return 0;

}
