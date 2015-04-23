#include <bits/stdc++.h> 

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

bool cache[2048][2048];
char cached[2048][2048], now;

int K;
string s;

bool can_win(int pos, int cakes) {
    if (cakes <= K) return true;
    if (cached[pos][cakes] == now) return cache[pos][cakes];
    cached[pos][cakes] = now;
    
    for (int eat = K; eat > 0; eat--) {
        if (can_win(pos+1, cakes-eat) == (s[pos] == s[pos+1])) return (cache[pos][cakes] = true);
    }
    
    return (cache[pos][cakes] = false);
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N, M;
        cin >> N >> M >> K;
        cin >> s;
        now++;
        cout << "Case #" << tc << ": ";
        if (can_win(0,M))  cout << s[0] << "\n";
        else cout << ((s[0] == 'A') ? "B\n" : "A\n");
    }

	return 0;
}

















