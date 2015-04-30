#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

int deg[1<<14], u[1<<17], v[1<<17]; 

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) deg[i] = 0;
        for (int i = 0; i < M; ++i) {
            cin >> u[i] >> v[i];
            deg[u[i]]++;
            deg[v[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < M; ++i) {
            ans += deg[u[i]] + deg[v[i]];
        }
        cout << ans << "\n";
        if (T) cout << "\n";
    }

	return 0;
}

















