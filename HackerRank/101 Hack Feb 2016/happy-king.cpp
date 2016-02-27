#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

typedef vector<vector<int>> matrix;

const int MOD = 1e9 + 7;

#define LEN 4
matrix ax = matrix(LEN, vector<int>(LEN));

void mult(matrix &a, matrix& b) {
    for (int i = 0; i < LEN; ++i) {
        for (int j = 0; j < LEN; ++j) {
            ax[i][j] = 0;
            for (int k = 0; k < LEN; ++k) {
                ax[i][j] += (int64(a[i][k]) * int64(b[k][j])) % MOD;
                ax[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < LEN; ++i) {
        for (int j = 0; j < LEN; ++j) {
            a[i][j] = ax[i][j];
        }
    }
}

int detachments(int qnt) {
    vector<vector<int>> tr = {{1, 1, 0, 0},
                              {0, 1, 1, 0},
                              {0, 0, 1, 1},
                              {1, 0, 0, 1}};


    vector<vector<int>> id = {{1, 0, 0, 0},
                              {0, 1, 0, 0},
                              {0, 0, 1, 0},
                              {0, 0, 0, 1}};

    while (qnt) {
        if (qnt & 1) mult(id, tr);
        mult(tr, tr);
        qnt >>= 1;
    }

    return id[0][0];
}

int A[1<<14], N;

int cache[128][1<<14];
char cached[128][1<<14];

int solve(int at, int need) {
    if (need == 0) return 1;
    if (at == N) return 0;

    int &ret = cache[need][at];
    if (cached[need][at]) return ret;
    cached[need][at] = 1;

    ret = solve(at+1, need);

    ret += (int64(A[at]) * int64(solve(at+1, need-1))) % MOD;
    ret %= MOD;

    return ret;
}

int main(int argc, char* argv[]) {
    
    ios::sync_with_stdio(false);
    
    int K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
     
    for (int i = 0; i < N; ++i) {
        A[i] = detachments(A[i]);
    }

    memset(cached, 0, sizeof(cached));
    cout << solve(0, K) << "\n";


    return 0;
}
