#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int pile[1<<16];

bool possible(int from, int to, int bottom, int top) {
    while (from <= to) {
        if (pile[from] == (bottom+1)) { bottom++; from++; }
        else if (pile[from] == (top-1)) { top--; from++; }
        else if (pile[to] == (bottom+1)) { bottom++; to--; }
        else if (pile[to] == (top-1)) { top--; to--; }
        else return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> pile[i];
        bool ok = possible(0, N-2, pile[N-1], pile[N-1]) || possible(1, N-1, pile[0], pile[0]);
        cout << "Case #" << tc << ": " << (ok?"yes\n":"no\n");
    }

	return 0;
}

















