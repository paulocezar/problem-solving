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

double fixed_fee[10], prctg_fee[10], assets[10];
double ratio[10];
    
int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
	
	int NINSTRUMENTS, NTERMS, NREBALANCE;
	while (cin >> NINSTRUMENTS >> NTERMS >> NREBALANCE) {
	        
       REP(i,NINSTRUMENTS) cin >> fixed_fee[i];
       REP(i,NINSTRUMENTS) cin >> prctg_fee[i];
      
       double all = 0.0;
       REP(i,NINSTRUMENTS) {
           cin >> assets[i];     
           all += assets[i];     
       }
       REP(i,NINSTRUMENTS) ratio[i] = assets[i]/all;     
       
       REP(term,NTERMS) {
           if (term && (term%NREBALANCE==0)) {
               all = 0.0;
               REP(i,NINSTRUMENTS) all += assets[i];     
               REP(i,NINSTRUMENTS) assets[i] = ratio[i]*all;
           }
           
           REP(i,NINSTRUMENTS) {
               double gain; cin >> gain;
               
               double trnsctn = (gain - prctg_fee[i]) * assets[i] - fixed_fee[i];
               assets[i] += trnsctn;
               if (assets[i] < 1e-14) assets[i] = 1e-15;               
           }
       }
       
       REP(i,NINSTRUMENTS) {
           if (i) cout << " ";
           assets[i] += 0.005;
           assets[i] = int(100.0*assets[i]);
           cout << fixed << setprecision(2) << assets[i]/100.0;
       }
       cout << "\n";
    
     
	}
    
	return 0;
}

















