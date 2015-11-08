#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<int> gr[1<<17];
int deg[1<<17];

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);

	ifstream in("graph.in");
	ofstream out("graph.out");

	int n, m, k;
	in >> n >> m >> k;

	while (m--) {
		int u, v;
		in >> u >> v;
		gr[u].push_back(v);
		deg[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> qmin;
    priority_queue<int> qmax;
    for (int i = 1; i <= n; ++i) {
    	if (deg[i] == 0) {
    		qmin.push(i);
    	}
    }

    vector<int> topo;
    vector<pair<int,int>> added;

    while (int(topo.size()) < n) {
    	if (k) {
    		int add = 0;
    		while (int(qmin.size()) > 1 && add < k) {
    			qmax.push(qmin.top()); qmin.pop();
    			add++;
    		}
    		if (add < k && !qmax.empty() && qmax.top() > qmin.top()) {
    			qmax.push(qmin.top()); qmin.pop();	
    			add++;
    		}
    		k -= add;
    	}

    	if (!qmin.empty()) {
	    	int u = qmin.top(); qmin.pop();
    		topo.push_back(u);

	    	for (int &v : gr[u]) {
    			deg[v]--;
    			if (deg[v] == 0) {
    				qmin.push(v);
    			}
    		}
    	}

    	if (qmin.empty() && !qmax.empty()) {
    		added.push_back(make_pair(topo.back(), qmax.top()));
    		qmin.push(qmax.top());
    		qmax.pop();
    	}
    }

    for (int i = 0; i < n; ++i) {
    	if (i) out << ' ';
    	out << topo[i];
    }
    out << "\n" << added.size() << "\n";
    for (auto &v : added) {
    	out << v.first << " " << v.second << "\n";
    }

	return 0;
}
