#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, M, A, B;
    while (cin >> N >> M && N) {
        vector<string> grid(N);
        for (int i = 0; i < N; ++i) cin >> grid[i];
        cin >> A >> B;
        int lt = A/N, ct = B/M;
        int cntl = 0, cntc = 0;
        for (int i = 0; i < N; ) {
            for (int j = 0; j < M; ) {
                cout << grid[i][j];
                cntc++;
                if (cntc == ct) {
                    cntc = 0;
                    j++;
                }
            }
            cout << "\n";
            cntl++;
            if (cntl == lt) {
                cntl = 0; i++;
            }
        }
        cout << "\n";
    }

    return 0;
}

