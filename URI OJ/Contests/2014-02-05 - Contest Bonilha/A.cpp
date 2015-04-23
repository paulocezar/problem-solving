#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a,b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);

    int N, A, B;
    while (cin >> N >> A >> B && N) {
        int res = N / A;
        res += N / B;
        res -= N / (A*B/gcd(A,B));
        cout << res << "\n";
    }

    return 0;
}

