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

#define MAXN 300000
#define MAXQ 200000

struct point_t {
    int x, y;
    bool operator < (const point_t &a) const { return x < a.x; }
    bool operator > (const point_t &a) const { return y < a.y; }
};

struct query_t {
    int x, y, d, id, res;
    bool operator < (const query_t &q) const { return x < q.x; }
    bool operator > (const query_t &q) const { return y < q.y; }
};

inline bool comp(const query_t &a, const query_t &b) { return a.id < b.id; }

point_t pt[MAXN];
query_t qr[MAXQ];

int bit[600001];

int get(int idx) {
    int res = 0;
    while (idx > 0) {
        res += bit[idx];
        idx -= (idx & -idx);
    }
    return res;
}

int lo, hi;
int query() {
    hi = min(hi, 600000);
    lo = min(lo-1, hi-1);
    return get(hi)-get(lo);
}

int nval;
void add() {
    int idx = nval;
    while (idx <= 600000) {
        bit[idx]++;
        idx += (idx & -idx);
    }
}
void rem() {
    int idx = nval;
    while (idx <= 600000) {
        bit[idx]--;
        idx += (idx & -idx);
    }
}

int main(int argc, char* argv[]) {
	
    int N, Q;
    N = next_int(); Q = next_int();
    
    REP(i, N) { pt[i].x = next_int(); pt[i].y = next_int(); }

    REP(i, Q) {
        qr[i].x = next_int(); qr[i].y = next_int(); qr[i].d = next_int();
        qr[i].res = 0;
        qr[i].id = i;
    }
    
    sort(pt, pt+N);
    sort(qr, qr+Q);
    
    int pos = 0;
    
    REP(i, Q) {
        while (pos < N && pt[pos].x < qr[i].x) {
            nval = pt[pos].x + pt[pos].y; add();
            pos++;
        }        
        lo = qr[i].x + qr[i].y;
        hi = lo + qr[i].d;
        qr[i].res -= query();
    }
    
    REP(i, N) { nval = pt[pos].x + pt[pos].y; rem(); }
    
    sort(pt, pt+N, greater<point_t>());
    sort(qr, qr+Q, greater<query_t>());
    
    pos = 0;
    REP(i, Q) {
        while (pos < N && pt[pos].y < qr[i].y) {
            nval = pt[pos].x + pt[pos].y; add();
            pos++;
        }        
        lo = qr[i].x + qr[i].y;
        hi = lo + qr[i].d;
        qr[i].res -= query();
    }
    
    while (pos < N) {
        nval = pt[pos].x + pt[pos].y; add();
        pos++;
    }
    
    sort(qr, qr+Q, comp);
    REP(i, Q) {
        lo = qr[i].x + qr[i].y;
        hi = lo + qr[i].d;
        qr[i].res += query();
    }
    
    REP(i, Q) printf("%d\n", qr[i].res);
    
	return 0;
}

















