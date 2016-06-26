#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> cnt(k, 0);
    for (int i = 0; i < n; ++i) {
        int ax; cin >> ax;
        cnt[ax%k]++;
    }

    int res = 0;
    for (int i = 0; i < k; ++i) {
        int op = ((k<<1)-i) % k;
        if ((i == op) && (cnt[i] || cnt[op])) res++;
        else res += max(cnt[i], cnt[op]);
        cnt[i] = cnt[op] = 0;
    }
    cout << res << "\n";

    return 0;
}
