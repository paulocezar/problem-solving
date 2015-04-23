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

pair<int,int> prop[1000000];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    cout << fixed << setprecision(2);
    
    int n; int town = 1;
    bool first = true;
    while (cin >> n && n) {
        if (!first) cout << "\n";
        first = false;
        
        cout << "Cidade# " << town << ":\n"; town++;
        double pop = 0, cons = 0;
        REP(i, n) {
            cin >> prop[i].second >> prop[i].first;
            pop += prop[i].second;
            cons += prop[i].first;
            prop[i].first /= prop[i].second;
        }
        sort(prop, prop+n);
        bool print = false;
        
        REP(i, n) {
            if (i+1 < n && prop[i].first == prop[i+1].first) {
                prop[i+1].second += prop[i].second;
            } else {
                if (print) cout << " ";
                cout << prop[i].second << "-" << prop[i].first;
                print = true;
            }
        }
        double med = int(cons * 100.0 / pop) / 100.0;
        cout << "\nConsumo medio: " << med << " m3.\n";
    }
    
	 
	return 0;
}

















