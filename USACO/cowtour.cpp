/*
ID: knightp2
PROG: cowtour
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

double x[150], y[150];
double dist[150][150];
double diam[150];
int comp[150], cur_comp;

int main(int argc, char* argv[]) {
    ifstream fin("cowtour.in");
    ofstream fout("cowtour.out");	
    
    int n;
    fin >> n;
    REP(i,n) fin >> x[i] >> y[i];

    REP(i,n) {
        string adj; fin >> adj;
        REP(j,n) {
            dist[i][j] = (i==j)?0:2e15;
            if (adj[j] == '1') {
                double dx = x[i]-x[j];
                double dy = y[i]-y[j];
                dist[i][j] = sqrt(dx*dx + dy*dy);
            }
        }
    }

    
    REP(k,n) REP(i,n) REP(j,n)
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    
    REP(i,n) if (!comp[i]) {
        ++cur_comp;
        REP(j,n) if (dist[i][j] != 2e15) comp[j] = cur_comp;
    }   
    
    FOR(i,1,cur_comp) diam[i] = 0;
    REP(i,n) REP(j,n) if (comp[i] == comp[j])
        diam[comp[i]] = max(diam[comp[i]], dist[i][j]);
    
    double res = 2e15;
    REP(i,n) REP(j,n) if (comp[i] != comp[j]){
        
        double da = 0, db = 0;
        REP(k,n) {
            if (comp[k] == comp[i]) da = max(da,dist[i][k]);
            if (comp[k] == comp[j]) db = max(db,dist[j][k]);
        }
        
        double dx = x[i]-x[j];
        double dy = y[i]-y[j];
        double cur = max(diam[comp[i]], max(diam[comp[j]], da+db+sqrt(dx*dx+dy*dy)));
        res = min(res,cur);
        
    }
    fout << fixed << setprecision(6) << res << "\n";
    
	return 0;
}

















