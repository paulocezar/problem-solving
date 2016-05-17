#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


vector<int> gr[1<<17];
bitset< (1<<17) > removed;
int visited[1<<17], visited_now;

int get_size(int v) {
    int res = 0;
    queue<int> q;
    q.push(v);
    visited[v] = visited_now;
    while (!q.empty()) {
        res++;
        v = q.front(); q.pop();
        for (int u : gr[v]) {
            if (removed[u]) continue;
            if (visited[u] == visited_now) continue;
            visited[u] = visited_now;
            q.push(u);
        }
    }

    return res;
}

int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    int m;
    cin >> m;

    int ans = 0;
    while (m--) {
        int ax; cin >> ax;
        int v = ax ^ ans;
        visited_now++;
        ans = get_size(v);
        cout << ans << "\n";
        removed.set(v);
    }


    return 0;
}
