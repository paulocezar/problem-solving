#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (auto &v : a) cin >> v;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (((a[i]+a[j])%k) == 0) res++;
        }
    }

    cout << res << "\n";

    return 0;
}
