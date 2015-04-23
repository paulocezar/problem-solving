#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> gr[1<<17];

int dp[1<<17][2];
int seen[1<<17][2], seen_now;

int solve(int u, int paired, int pa) {
    int &ret = dp[u][paired];
    if (seen[u][paired] == seen_now) return ret;
    
    seen[u][paired] = seen_now;
    ret = 0;
    
    int ok = 0;
    for (int i = 0; i < int(gr[u].size()); ++i) {
        int v = gr[u][i];
        if (v != pa) ok += solve(v, 0, u);
    }
    
    if (paired) {
        
        if ((ok+((pa==-1) ?  0 : 1)) == gr[u].size()) ret = 1;
        return ret;
    }
    
    for (int i = 0; i < int(gr[u].size()); ++i) {
        int v = gr[u][i];
        if (v != pa) {
            int bef = solve(v, 0, u);
            int aft = solve(v, 1, u);
            if (aft && ((ok-bef+aft+((pa==-1) ?  0 : 1)) == gr[u].size())) {
                ret = 1;
                return ret;
            }
        }
    }
    
    return ret;
}

void build(int u, int paired, int pa, vector< pair<int,int> > &res) {
    
    if (paired) {
        for (int i = 0; i < int(gr[u].size()); ++i) {
            int v = gr[u][i];
            if (v != pa) build(v, 0, u, res);
        }
        return;
    }
    
    int ok = 0;
    for (int i = 0; i < int(gr[u].size()); ++i) {
        int v = gr[u][i];
        if (v != pa) ok += solve(v, 0, u);
    }
    
    int matched = -1;
    pair<int,int> cur;
    for (int i = 0; i < int(gr[u].size()); ++i) {
        int v = gr[u][i];
        if (v != pa) {
            int bef = solve(v, 0, u);
            int aft = solve(v, 1, u);
            if (aft && ((ok-bef+aft+((pa==-1) ?  0 : 1)) == gr[u].size())) {
                if (matched == -1) {
                    cur = make_pair(min(u,v), max(u,v));
                    matched = v;
                } else if (make_pair(min(u,v), max(u,v)) < cur) {
                    cur = make_pair(min(u,v), max(u,v));
                    matched = v;
                }
            }
        }
    }
    res.push_back(cur);
    build(matched,1,u,res);
    for (int i = 0; i < int(gr[u].size()); ++i) {
        int v = gr[u][i];
        if ((v != pa) && (v != matched)) {
            build(v,0,u,res);
        }
    }        
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int N;
    while (cin >> N) {
        seen_now++;
        
        for (int i = 0; i < N; ++i) gr[i].clear();
        
        for (int i = 1; i < N; ++i) {
            int u, v; cin >> u >> v; u--, v--;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        
        vector< pair<int,int> > res1, res2;
        bool ok1 = solve(0,0,-1);
        bool ok2 = solve(0,1,-1);
        
        if (ok1) { build(0,0,-1, res1); sort(res1.begin(), res1.end()); }
        if (ok2) { build(0,1,-1, res2); sort(res2.begin(), res2.end()); }

        if (ok1 || ok2) {
            
            vector< pair<int,int> > res = (ok1&&ok2) ? min(res1,res2) : (ok1 ? res1 : res2);
            cout << "Y\n";
            for (int i = 0; i < int(res.size()); ++i) cout << res[i].first+1 << ' ' << res[i].second+1 << "\n";
        } else cout << "N\n";
        
    }
    

	return 0;
}

















