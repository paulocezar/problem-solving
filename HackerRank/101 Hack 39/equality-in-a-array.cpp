#include <bits/stdc++.h>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;



int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map<int,int> cnt;

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int ax; cin >> ax;
        cnt[ax]++;
        mx = max(mx, cnt[ax]);
    }

    cout << n - mx << "\n";

    return 0;
}
