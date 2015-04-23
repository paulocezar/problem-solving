#include <iostream>

using namespace std;

int get(int N, int K, int C) {
    int fr = K / N; fr *= N;
    if (fr >= C) return C;
    int tr = N-(K-fr);
    return C + tr;
}

int main() {
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        int N, K, C;
        cin >> N >> K >> C;
        
        int res = get(N, K, C);
        if (K > N) {
            for (int empty = 1; empty < N; ++empty) {
                res = min(res, empty + get(N-empty,K,C));
            }
        }
        
        cout << "Case #" << kase << ": " << res << "\n";
    }
    
    return 0;
}
