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
#include <deque>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> fr[100001], pd[100001];
int dist[100001];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int n, m, u, v;
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) dist[i] = 2e9;
    
    while (m--) {
        cin >> u >> v;
        fr[u].push_back(v);
        pd[v].push_back(u);
    }
    
    deque<int> q;
    q.push_back(1); dist[1] = 0;
        
    while (!q.empty()) {
        
        u = q.front(); q.pop_front();
        
        for (int i = 0; i < int(fr[u].size()); ++i) {
            v = fr[u][i];
            if (dist[v] > dist[u]) {
                dist[v] = dist[u];
                q.push_front(v);
            }
        }
        
        for (int i = 0; i < int(pd[u].size()); ++i) {
            v = pd[u][i];
            if (dist[v] > (dist[u]+1)) {
                dist[v] = dist[u]+1;
                q.push_back(v);
            }
        }
           
    }
    
    if (dist[n] != 2e9) cout << dist[n] << "\n";
    else cout << "-1\n";

	return 0;
}

















