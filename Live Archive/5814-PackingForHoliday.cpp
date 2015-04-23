#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int L, H, W;
        cin >> L >> H >> W;
        bool ok = ((L <= 20) && (H<=20) && (W<=20));
        cout << "Case " << tc << ": " << (ok?"good":"bad") << "\n";
    }
    
    return 0;
}