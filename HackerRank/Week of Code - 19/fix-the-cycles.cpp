#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<pair<int,int>> edges = {{3, 0}, {0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}};
vector<int> edge_weights(6);

bool has_cycle() {
    vector<int> dist = {0, 1<<20, 1<<20, 1<<20};
    int steps = 4;
    while (steps--) {
        for (int i = 0; i < int(edges.size()); ++i) {
            int ndist = dist[edges[i].first] + edge_weights[i];
            if (ndist < dist[edges[i].second]) dist[edges[i].second] = ndist;
        }
    }
    for (int i = 0; i < int(edges.size()); ++i) {
        int ndist = dist[edges[i].first] + edge_weights[i];
        if (ndist < dist[edges[i].second]) return true;
    }
    return false;
}

bool fix_the_cycles(int p) {
    for (auto &w : edge_weights) {
        w += p;
        bool hc = has_cycle();
        w -= p;
        if (!hc) return true;
    }
    return false;
}

int main(int argc, char* argv[]) {
    
    ios::sync_with_stdio(false);
    
    for (auto &w : edge_weights) cin >> w;

    int lo = 0, hi = 1024;
    while (lo <= hi) {
        int mid = (lo+hi) >> 1;

        if (fix_the_cycles(mid)) hi = mid-1;
        else lo = mid+1;
    }

    if (lo > 1024) lo = -1;
    cout << lo << "\n";

    return 0;
}
