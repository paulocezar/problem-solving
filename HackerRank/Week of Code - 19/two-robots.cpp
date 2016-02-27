#include <bits/stdc++.h>

using namespace std;

int a[1024], b[1024];
int cache[1024][1024];
int last_solved[1024][1024], solved_now;
int N;

int solve(int l1, int l2) {
    int cur = max(l1, l2)+1;
    if (cur > N) return 0;

    int &res = cache[l1][l2];
    if (last_solved[l1][l2] == solved_now) return res;
    last_solved[l1][l2] = solved_now;
    res = 2e9;

    res = min(res, (l1 ? abs(b[l1]-a[cur]) : 0) + solve(cur, l2));
    res = min(res, (l2 ? abs(b[l2]-a[cur]) : 0) + solve(l1, cur));
    res += abs(a[cur]-b[cur]);

    return res;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);

    int T, M;
    cin >> T;
    while (T--) {
        cin >> M >> N;

        for (int i = 1; i <= N; ++i) cin >> a[i] >> b[i];

        solved_now++;
        cout << solve(0, 0) << "\n";
    }

    return 0;
}
