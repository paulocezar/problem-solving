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

#define MAXV (100+26+2)
#define MAXE 2*(26+26*100+100+100)

int dist[MAXV], last_edge[MAXV], d_visited[MAXV], bg_prev[MAXV], pot[MAXV], capres[MAXV];
int prev_edge[MAXE], adj[MAXE], cap[MAXE], cost[MAXE], flow[MAXE];

int nedges;
priority_queue<pair<int, int> > d_q;

inline void bg_edge(int v, int w, int capacity, int cst, bool r = false) {
    prev_edge[nedges] = last_edge[v];
    adj[nedges] = w;
    cap[nedges] = capacity;
    flow[nedges] = 0;
    cost[nedges] = cst;
    last_edge[v] = nedges++;

    if(!r) bg_edge(w, v, 0, -cst, true);
}

inline int rev(int i) { return i ^ 1; }
inline int from(int i) { return adj[rev(i)]; }

inline void bg_init() {
    nedges = 0;
    memset(last_edge, -1, sizeof last_edge);
    memset(pot, 0, sizeof pot);
}

void bg_dijkstra(int s, int num_nodes = MAXV) {
    memset(dist, 0x3f, sizeof dist);
    memset(d_visited, 0, sizeof d_visited);
    d_q.push(make_pair(dist[s] = 0, s));
    capres[s] = 0x3f3f3f3f;

    while(!d_q.empty()) {
        int v = d_q.top().second; d_q.pop();
        if(d_visited[v]) continue; d_visited[v] = true;

        for(int i = last_edge[v]; i != -1; i = prev_edge[i]) {
            if(cap[i] - flow[i] == 0) continue;
            int w = adj[i], new_dist = dist[v] + cost[i] + pot[v] - pot[w];

            if(new_dist < dist[w]) {
                d_q.push(make_pair(-(dist[w] = new_dist), w));
                bg_prev[w] = rev(i);
                capres[w] = min(capres[v], cap[i] - flow[i]);
            }
        }
    }
}

pair<int, int> busacker_gowen(int src, int sink, int num_nodes = MAXV) {
    int ret_flow = 0, ret_cost = 0;

    bg_dijkstra(src, num_nodes);
    while(dist[sink] < 0x3f3f3f3f) {
        int cur = sink;
        while(cur != src) {
            flow[bg_prev[cur]] -= capres[sink];
            flow[rev(bg_prev[cur])] += capres[sink];
            ret_cost += cost[rev(bg_prev[cur])] * capres[sink];
            cur = adj[bg_prev[cur]];
        }
        ret_flow += capres[sink];

        for(int i = 0; i < MAXV; ++i)
            pot[i] = min(pot[i] + dist[i], 0x3f3f3f3f);

        bg_dijkstra(src, num_nodes);
    }
    return make_pair(ret_flow, ret_cost);
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	
    string txt; cin >> txt;
    int n; cin >> n;
    
    int source = 0;
    int sink = 26+n+1;
     
    bg_init();
     
    map<int,int> occ;   
    REP(i,SIZE(txt)) occ[ (txt[i]-'a')+1 ]++;
    
    FORIT(v,occ) bg_edge(source, v->first, v->second, 0);
    
    FOR(i,1,n) {
        string s; int a;
        cin >> s >> a;
        
        bg_edge(26+i, sink, a, i);
        occ.clear();
        REP(j,SIZE(s)) occ[ (s[j]-'a')+1 ]++;
        FORIT(v,occ) bg_edge(v->first,26+i,v->second,0);
	}
    
    pair<int,int> ans = busacker_gowen(source, sink);
    if (ans.first != SIZE(txt)) cout << "-1\n";
    else cout << ans.second << "\n";
    
    
	return 0;
}

















