#include <bits/stdc++.h>

using namespace std;

typedef long long int64;


int main() {
    ios::sync_with_stdio(false);
    
    int64 C, M;
    int N;
    
    cin >> C >> M >> N;

    int len = 4*N - 2;
    
    int64 a2 = 5LL % M, a1 = 8LL % M;
    C %= M;
    C = (C*C) % M;

    unordered_set<int64> S;

    for (int i = 6; i <= len; i+=2) {
        a2 += a1;
        a2 %= M;
        S.insert((C * a2)%M);
        a1 += a2;
        a1 %= M;
    }

    cout << int64(S.size())%M << "\n";

    return 0;
}
