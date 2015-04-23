#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int x[1024], y[1024], t[1024], K;

int memo[1024][1024];
int last_seen[1024][1024], seen_now;

int solve(int last, int cur) {
    if (cur > K) return 0;
        
    int &ret = memo[last][cur];
    if (last_seen[last][cur] == seen_now) return ret;
    last_seen[last][cur] = seen_now;
    ret = solve(last, cur+1);
    
    int mn = max(abs(x[cur]-x[last]), abs(y[cur]-y[last]));
    int hs = t[cur]-t[last];
     
    if (hs >= mn) ret = max(ret, 1 + solve(cur, cur+1));
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    int N, M;
    while (cin >> N >> M >> K && N) {
        
        for (int i = 1; i <= K; ++i) {
            cin >> x[i] >> y[i] >> t[i];
        }
        cin >> x[0] >> y[0]; t[0] = 0;
        seen_now++;
        cout << solve(0,1) << "\n";
    }

    return 0;
}

