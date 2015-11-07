#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> gr[1<<17];
int deg[1<<17], seen[1<<17], mx1[1<<17], mx2[1<<17];

pair<int,int> find_center(int u) {
	queue<int> q;
	queue<int> leafs;
	
	q.push(u); seen[u] = 1;
	int last = u;

	int n = 0;
	while (!q.empty()) {
		u = q.front(); q.pop();
		n++;
		if (deg[u] == 1) {
			leafs.push(u);
			deg[u]--;
		}

		for (int &v : gr[u]) {
			if (!seen[v]) {
				q.push(v);
				seen[v] = 1;
			}
		}
	}

	while (!leafs.empty()) {
		last = leafs.front(); leafs.pop();
		for (int &v : gr[last]) {
			if ((mx1[last]+1) >= mx1[v]) {
				mx2[v] = mx1[v];
				mx1[v] = mx1[last]+1;
			} else if ((mx1[last]+1) >= mx2[v]) {
				mx2[v] = mx1[last]+1;
			}
			deg[v]--;
			if (deg[v] == 1) leafs.push(v);
		}
	}

	return make_pair(mx1[last], mx2[last]);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int c, l, u, v;
    cin >> c >> l;
    for (int i = 0; i < l; ++i) {
    	cin >> u >> v;
    	gr[u].push_back(v);
    	gr[v].push_back(u);
    	deg[u]++; deg[v]++;
    }

    int ans = 0;
    int d1 = -1, d2 = -1, d3 = -1;
    for (int i = 0; i < c; ++i) {
    	if (!seen[i]) {
    		pair<int,int> center = find_center(i);
    		ans = max(ans, center.first + center.second);
    		if (center.first >= d1) {
    			d3 = d2;
    			d2 = d1;
    			d1 = center.first;
    		} else if (center.first >= d2) {
    			d3 = d2;
    			d2 = center.first;
    		} else if (center.first > d3) {
    			d3 = center.first;
    		}
    	}
    }

    if (d3 == d1) ans = max(ans, d1+d3+2);
    if (d2 != -1) ans = max(ans, d1+d2+1);

    cout << ans << "\n";

	return 0;
}
