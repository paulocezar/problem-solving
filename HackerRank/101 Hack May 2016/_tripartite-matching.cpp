#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

vector<vector<int>> gr[3];



int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < 3; ++i) {
        gr[i].resize(n+1);
        int m;
        cin >> m;
        while (m--) {
            int a, b;
            cin >> a >> b;
            gr[i][a].push_back(b);
            gr[i][b].push_back(a);
        }
    }

    for (int i = 1; i <= n; ++i) sort(gr[2][i].begin(), gr[2][i].end());

    // YEAP, N^3 log N and still almost a full score ..
    int res = 0;
    for (int a = 1; a <= n; ++a) {
        for (int b : gr[0][a]) {
            if (a == b) continue;
            for (int c : gr[1][b]) {
                if (a == c || b == c) continue;
                if (binary_search(gr[2][c].begin(), gr[2][c].end(), a)) {
                    res++;
                }
            }
        }
    }
    cout << res << "\n";

    return 0;
}
