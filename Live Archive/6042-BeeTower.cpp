#include <iostream>
#include <algorithm>

using namespace std;

#define INF 0x3F3F3F3F

int cache[64][512], last_cached[64][512], p[64], h[64], id[64], ps[64], hg[64];
int len, N, H, W, cached_now;


int solve(int pos, int curx) {
    
    if ((pos+1) == len) return ((hg[pos] <= H) ? 0 :  INF);
    if (hg[pos] <= H) return 0;
    
    int &ret = cache[pos][curx];
    if (last_cached[pos][curx] == cached_now) return ret;
    last_cached[pos][curx] = cached_now;
    ret = INF;
    
    if ((hg[pos+1]+H) >= hg[pos]) {
        
        int nx = ps[pos+1];
        int cst = 0;
        
        if (nx <= curx) {
            cst += (curx+1-nx) * hg[pos+1];
            nx = curx+1;
        }
        
        while ((curx+W) < nx) {
            cst += hg[pos+1];
            nx--;
        }
        ret = cst + solve(pos+1, nx);
        
         
        while (((curx+W) >= (nx+1)) && ((nx+1) < 512)) {
            cst += hg[pos+1];
            nx++;
            ret = min(ret, cst + solve(pos+1, nx));
        }
        
    }
    
    return ret;
}


int main() {
    ios::sync_with_stdio(false);
    
    int kases;
    cin >> kases;
    for (int kase = 1; kase <= kases; ++kase) {
        
        cin >> N >> H >> W;
        int mx = 0;
        for (int i = 0; i < N; ++i) {
            cin >> p[i] >> h[i];
            mx = max(mx, h[i]);
        }
        
        int res = INF;
        for (int i = 0; i < N; ++i) {
            if (h[i] != mx) continue;
            
            len = 0;
            while ((i + len) < N) {
                if (len && (h[i+len] == mx)) break;
                ps[len] = abs(p[i]-p[i+len]);
                hg[len] = h[i+len];
                len++;
            }
            cached_now++;
            res = min(res, solve(0,0));           
            
            len = 0;
            while ((i - len) >= 0) {
                if (len && (h[i-len] == mx)) break;
                ps[len] = abs(p[i]-p[i-len]);
                hg[len] = h[i-len];
                len++;
            }
            cached_now++;
            res = min(res, solve(0,0));           
        }
        if (res == INF) res = -1;
        
        cout << "Case #" << kase << ": " << res << "\n";
        
    }
    
    return 0;
}