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

#define LGN 19
int segt[2][1<<(LGN+1)];

int pos, val, tree;
void inc(int node, int lo, int hi) {
    if (lo == hi) {
        segt[tree][node] += val;
    } else {
        int ls = (node<<1) + 1;
        int rs = ls + 1;
        int mid = (lo+hi) >> 1;
        if (mid >= pos) inc(ls,lo,mid);
        if (mid+1 <= pos) inc(rs,mid+1,hi);
        segt[tree][node] = max(segt[tree][ls],segt[tree][rs]);
    }
}


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    string cmd;
    while (Q--) {
        cin >> cmd >> pos >> val; pos--;
        if (cmd[0] == 'R') tree = 0;
        else tree = 1;
        inc(0,0,N-1);
    }

    cout << segt[0][0] + segt[1][0] << "\n";
    
	return 0;
}

















