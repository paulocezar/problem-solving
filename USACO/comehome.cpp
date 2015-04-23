/*
ID: knightp2
PROG: comehome
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

int getid(char c) {
    if ('a' <= c && c <= 'z') return (c-'a');
    return 26 + (c-'A');
}

int cost[64][64];
int dist[64];

int main(int argc, char* argv[]) {
    ifstream fin("comehome.in");
    ofstream fout("comehome.out");	
    
    int P;
    fin >> P;
    while (P--) {
        char u, v; int c;
        fin >> u >> v >> c;
        int uu = getid(u);
        int vv = getid(v);
        if (cost[uu][vv]) {
            cost[uu][vv] = min(cost[uu][vv], c);
            cost[vv][uu] = cost[uu][vv];
        } else {
            cost[uu][vv] = c;
            cost[vv][uu] = c;
        }
    }
    
    memset(dist,0x3f,sizeof(dist));
    priority_queue< pair<int,int> > q;
    
    dist[getid('Z')] = 0;
    q.push(MP(0,getid('Z')));
    while (!q.empty()) {
      int cc = -q.top().first;
      int u = q.top().second; q.pop();
      for (char cow = 'A'; cow <= 'Y'; ++cow) {
          int v = getid(cow);
          if (!cost[u][v]) continue;
          if (cc+cost[u][v] < dist[v]) {
              dist[v] = cc+cost[u][v];
              q.push(MP(-dist[v],v));
          }
      }
      for (char barn = 'a'; barn <= 'z'; ++barn) {
          int v = getid(barn);
          if (!cost[u][v]) continue;
          if (cc+cost[u][v] < dist[v]) {
              dist[v] = cc+cost[u][v];
              q.push(MP(-dist[v],v));
          }
      }
      
    }
    
    int res = 0x3F3F3F3F;
    char c = '.';
    for (char cow = 'A'; cow <= 'Y'; ++cow) if (dist[getid(cow)] < res) {
        res = dist[getid(cow)];
        c = cow;
    }
    fout << c << " " << res << "\n";
	return 0;
}

















