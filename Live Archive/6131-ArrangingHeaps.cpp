#include <iostream>

using namespace std;

#define MAXN 1024

long long P[MAXN], SW[MAXN], G[MAXN];
long long dp[2][MAXN];

struct point_t {
    long long x, y;
    point_t(long long _x = 0LL, long long _y = 0LL) : x(_x), y(_y) {}
};

inline bool check(point_t& a, point_t& b, point_t& c) {
    return ((a.y - b.y) * (c.x - a.x)) < ((a.y - c.y) * (b.x - a.x));
}

int stk_sz, min_pos;
point_t stk[MAXN];

inline void add(point_t pt) {
    while (stk_sz >= 2 && !check(stk[stk_sz - 2], stk[stk_sz - 1], pt)) {
        if (min_pos == (stk_sz - 1)) --min_pos;
        --stk_sz;
    }
    stk[stk_sz++] = pt;
}

inline long long eval(int pos, long long x) { return stk[pos].y + stk[pos].x * x; }

long long get_min(long long x) {
    while (((min_pos + 1) < stk_sz) && (eval(min_pos,x) > eval(min_pos + 1,x)))
        ++min_pos;
    return eval(min_pos,x);
}

int main() {
    ios::sync_with_stdio(false);
    
    int N, K;
    while (cin >> N >> K) {
        
        for (int i = 1; i <= N; ++i) {
            cin >> P[i] >> SW[i];
            G[i] = G[i-1] + SW[i]*P[i];
            SW[i] += SW[i-1];
            
            dp[1][i] = P[i] * SW[i] - G[i];
        }
        
        for (int j = 2, r = 0; j <= K; ++j, r ^= 1) {
            stk_sz = 0, min_pos = 0;
            for (int i = j; i <= N; ++i) {
                add(point_t(-SW[i-1], G[i-1] + dp[r^1][i-1]));  
                dp[r][i] = P[i]*SW[i] - G[i] + get_min(P[i]);
            }
        }
        
        cout << dp[K & 1][N] << "\n";
    }
    
    return 0;
}