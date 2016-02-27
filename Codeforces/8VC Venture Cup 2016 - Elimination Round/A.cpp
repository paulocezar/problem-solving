#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int main(int argc, char* argv[]) {

    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int xx = 0, yy = 0;
        for (int j = i; j < n; ++j) {
            switch (s[j]) {
                case 'U': xx++; break;
                case 'D': xx--; break;
                case 'L': yy++; break;
                case 'R': yy--; break;
            }
            if (xx == 0 && yy == 0) ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}
