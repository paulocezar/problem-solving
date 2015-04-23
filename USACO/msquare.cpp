/*
ID: knightp2
PROG: msquare
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

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int chng[3][8] = {{7,6,5,4,3,2,1,0},
                  {3,0,1,2,5,6,7,4},
                  {0,6,1,3,4,2,5,7}};

map<vector<int>, char> parent;

void apply(vector<int> &from, char op, vector<int> &to) {
    REP(i,8) to[i] = from[chng[op-'A'][i]];   
}

void undo(vector<int> &from, char op, vector<int> &to) {
    REP(i,8) to[chng[op-'A'][i]] = from[i];
}

void show(vector<int> &cur, int depth = 0) {
    if (parent[cur] == ' ') {
        cout << depth << "\n";
    } else {
        vector<int> aux(8);
        undo(cur,parent[cur],aux);
        show(aux,depth+1);
        cout << parent[cur];
    }
}

int main(int argc, char* argv[]) {
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);

    vector<int> desired(8);
    REP(i, 8) cin >> desired[i];

    vector<int> cur(8);
    REP(i,8) cur[i] = i+1;

    parent[cur] = ' ';
    queue< vector<int> > q;
    q.push(cur);
    vector<int> nxt(8);
    while (!q.empty()) {
        cur = q.front(); q.pop();
        if (cur == desired) {
            show(cur); cout << "\n";
            break;
        }
        for (char op = 'A'; op <= 'C'; ++op) {
            apply(cur, op, nxt);
            if (!parent.count(nxt)) {
                parent[nxt] = op;
                q.push(nxt);
            }
        }
    }
        
	return 0;
}

















