#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>

using namespace std;

#define MAXN 1024


vector< int > gr[MAXN];
vector< pair<int, int> > sites[MAXN];

inline int dist(pair<int,int> &a, pair<int, int> &b) {
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

double cache[MAXN][64];
int last_cached[MAXN][64], cached_now;

double solve(int node, int psite, int pa) {
    double &res = cache[node][psite];
    
    if (last_cached[node][psite] == cached_now) return res;
    last_cached[node][psite] = cached_now;
    
    for (int i = 0; i < int(sites[node].size()); ++i) {
            
        double cur = 0.0;
        
        for (int j = 0; j < int(gr[node].size()); ++j) {
            int v = gr[node][j];
            if (v == pa) continue;
            cur += solve(gr[node][j], i, node);
        }
        
        if (psite != -1) cur += sqrt(dist(sites[node][i], sites[pa][psite]));
        
        if (i) res = min(res, cur);
        else res = cur;
    }
    
    return res;    
}


int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(1);
    
    int N;
    while (cin >> N && N) {
        
        map< string, int> hash;     
        for (int i = 0; i < N; ++i) {
            string name; int n_sites;
            cin >> name >> n_sites;
            hash[name] = i;
            gr[i].clear();
            
            vector< pair<int, int> > &cur = sites[i];
            cur.resize(n_sites);
            while (n_sites--) cin >> cur[n_sites].first >> cur[n_sites].second;
        }
        
        for (int edge = 1; edge < N; ++edge) {
            string u, v;
            cin >> u >> v;
            gr[hash[u]].push_back(hash[v]);
            gr[hash[v]].push_back(hash[u]);    
        }
        cached_now++;
        cout << solve(0,-1,0) << "\n";
    }
    
    return 0;
}