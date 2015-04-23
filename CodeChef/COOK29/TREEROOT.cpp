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

#define MAXN 32

int n;
pair<int,int> node[MAXN];

inline int next_int() {
    int res = 0;
    char c = getchar_unlocked();
    while (!isdigit(c)) c = getchar_unlocked();
    while (isdigit(c)) {
        res = 10*res + (c-'0');
        c = getchar_unlocked();
    }
    return res;
}

int main(int argc, char* argv[]) {
	
	int t = next_int();
    while (t--) {
        n = next_int();
        REP(i, n) {
            node[i].first = next_int();
            node[i].second = next_int();
        }
        sort(node, node+n);
        
        set< int > rooted[n];
        REP(i, n) if (node[i].second == 0) rooted[i].insert(1<<i);
        
        bool changed = true;
        while (changed) {
            changed = false;
            REP(i, n) {
                
                REP(j, n) if (i != j && (node[i].second == node[j].first)) {
                    FORIT(tree,rooted[j]) {
                        if (*tree & (1<<i)) continue;
                        changed = changed || rooted[i].insert(*tree | (1<<i)).second;
                    }
                }
                
                REP(j, n) FOR(j2, j+1, n-1) {
                    if (i == j || i == j2) continue;
                    if (node[i].second != (node[j].first + node[j2].first)) continue;
                    FORIT(tree, rooted[j]) FORIT(tree2, rooted[j2]) {
                        if (*tree & *tree2) continue;
                        int x = *tree | *tree2;
                        if (x & (1<<i)) continue;
                        changed = changed || rooted[i].insert(x | (1<<i)).second;
                    }
                }
                
            }
            
        }
        bool fl = false;
        int all = (1<<n)-1;
        REP(i, n) {
            if (rooted[i].count(all)) {
                if (fl) printf(" ");
                else fl = true;
                printf("%d", node[i].first);
            }
        }
        puts("");
    }
    
	 
	return 0;
}

















