#include <iostream>
#include <algorithm>

using namespace std;

int t[100000];

int main() {
    ios::sync_with_stdio(false);
    int T, Q;
    while ((cin >> T >> Q) && (T || Q)) {
        
        for (int i = 0; i < T; ++i) { cin >> t[i]; t[i] <<= 1; }
        
        int d = -1;
        for (int i = 0; i < T-1; ++i) {
            if (d == -1) d = t[i]-t[T-1];
            else d = __gcd(t[i]-t[T-1], d);
        }
        
        while (Q--) {
            int S, D;
            cin >> S >> D;
            if (T == 1) {
                cout << ((t[0] == S+D) ? "Y" : "N");
            } else {
                int even = !((D-S) % d);
                int odd = !((D-S-t[T-1]) % d);
                cout << ((even || odd) ? "Y" : "N");
            }
            if (Q) cout << " ";
            else cout << "\n";
        }
    }
    
    
    return 0;
}