#include <iostream>

using namespace std;

#define MAXN 1024
#define MAX_EXTRA 10

int up[MAXN], down[MAXN], N;

int cache[2][MAX_EXTRA][MAXN];
int last_cached[2][MAX_EXTRA][MAXN], cached_now;

int solve(int dir, int extra, int pos) {

    if (pos == N) return 0LL;

    int &res = cache[dir][extra][pos];
    if (last_cached[dir][extra][pos] == cached_now) return res;
    last_cached[dir][extra][pos] = cached_now;
    res = 2e9;
    
    if (pos && ((extra+1) < MAX_EXTRA)) res = min(res, 26+solve(dir,extra+1,pos));
    
    res = min(res, (dir ? down[pos] : up[pos]) + solve(1-dir,0,pos+1));
        
    int cur = (pos ? (dir ? up[pos-1] : down[pos-1]) : 0);
    int want = (dir ? up[pos] : down[pos]);
    
    if (cur >= want) {
        res = min(res, solve(dir, extra, pos+1));
        if ((extra+1) < MAX_EXTRA)
            res = min(res, 26-cur+want+solve(dir,extra+1, pos+1));
    } else {
        res = min(res, want-cur+solve(dir,extra,pos+1));
        if (extra) res = min(res, solve(dir,extra-1,pos+1));
    }
    
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    
    string s;
    while (cin >> s && (s[0] != '*')) {
        N = int(s.size());
        for (int i = 0; i < N; ++i) {
            up[i] = int(s[i]-'a');
            down[i] = (s[i]=='a' ? 0 : (26-int(s[i]-'a')));
        }
        cached_now++;
        cout << solve(0,0,0) << "\n";
    }
    
    
    return 0;
}