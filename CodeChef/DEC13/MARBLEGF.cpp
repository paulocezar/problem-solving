#include <iostream>

using namespace std;

long long bit[1<<20];

int main() {
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 1; i <= N; ++i) {
        long long val; cin >> val;
        int idx = i;
        while (idx <= N) {
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }
    
    char cmd;
    int a, b, idx;
    long long sum1, sum2;
    while (Q--) {
        cin >> cmd >> a >> b;
        switch (cmd) {
            case 'S':
                 sum1 = sum2 = 0;
                 idx = b+1;
                 while (idx > 0) {
                     sum1 += bit[idx];
                     idx -= (idx & -idx);
                 }
                 idx = a;
                 while (idx > 0) {
                     sum2 += bit[idx];
                     idx -= (idx & -idx);
                 }
                 cout << (sum1-sum2) << "\n";
                 break;
            case 'G':
                idx = a+1;
                while (idx <= N) {
                    bit[idx] += b;
                    idx += (idx & -idx);
                }
                break;
            case 'T':
                idx = a+1;
                while (idx <= N) {
                    bit[idx] -= b;
                    idx += (idx & -idx);
                }
        }
    }
    
    return 0;
}