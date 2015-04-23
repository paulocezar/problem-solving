#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, M;
    while (cin >> N >> M && (N || M)) {
        int has_solved[N];
        int solved_by[M];
        
        for (int i = 0; i < N; ++i) has_solved[i] = 0;
        for (int i = 0; i < M; ++i) solved_by[i] = 0;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int x;
                if (cin >> x && x) { has_solved[i]++; solved_by[j]++; }
            }
        }
        
        int got = 4;
        for (int i = 0; i < N; ++i) if (!has_solved[i]) { got--; break; }
        for (int i = 0; i < N; ++i) if (has_solved[i] == M) { got--; break; }
        for (int i = 0; i < M; ++i) if (!solved_by[i]) { got--; break; }
        for (int i = 0; i < M; ++i) if (solved_by[i] == N) { got--; break; }
        
        cout << got << "\n";
    }

    return 0;
}

