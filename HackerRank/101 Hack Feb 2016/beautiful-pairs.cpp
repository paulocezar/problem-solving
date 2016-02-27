#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int AA[1024], BB[1024];

int main(int argc, char* argv[]) {
    
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    map<int, int> A, B;

    for (int i = 0; i < N; ++i) {
        cin >> AA[i];
        A[AA[i]]++;
    }
    for (int i = 0; i < N; ++i) {
        cin >> BB[i];
        B[BB[i]]++;
    }

    int eq = 0;
    for (auto &val : B) {
        eq += min(val.second, A[val.first]);
    }

    int peq = 0;
    for (int i = 0; i < N; ++i) if (AA[i] == BB[i]) peq++;

    if (eq < N) eq++;
    else if (eq == N) eq--;
    
    cout << eq << endl;
    
    return 0;
}
