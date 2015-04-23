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
#include <tr1/unordered_map>
#include <tr1/unordered_set>

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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

typedef long long TYPE;

struct pt {
    TYPE x, y;
    pt(TYPE x = 0, TYPE y = 0) : x(x), y(y) {}
    TYPE operator%(pt p) { return x*p.y - y*p.x; }
    pt operator-(pt p) { return pt(x - p.x, y - p.y); }
};

TYPE area(pt a, pt b, pt c) { return (a-c)%(b-c); }

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    int64 minarea, maxarea;
    int minind = -1, maxind = -1;
    
    pt a, b, c;
    
    for (int i = 1; i <= N; ++i) {
        
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        
        TYPE cur_area = abs(area(a,b,c));
        
        if (minind == -1 || cur_area <= minarea) {
            minarea = cur_area;
            minind = i;
        }
        if (maxind == -1 || cur_area >= maxarea) {
            maxarea = cur_area;
            maxind = i;
        }
    }
    cout << minind << " " << maxind << "\n";
	return 0;
}

















