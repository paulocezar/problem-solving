#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long int64;

const int all = (1<<10) - 1;

int age[128];
vector< int > ways[128];

inline int popc(int x) {
    int res = 0;
    while (x > 0) { res++; x -= (x & -x); }
    return res;
}

int mask[128];
int getmask(int v) {
    int mask = 0;
    int digs = 0;
    while (v) {
        int dig = v % 10;
        digs++;
        mask |= (1<<dig);
        v /= 10;
    }
    if (digs != popc(mask)) return all;
    return mask;
}

int64 val[1<<10];
int64 getval(int vmask) {
    int64 res = 0;
    for (int dig = 9; dig >= 0; --dig) {
        if (vmask & (1<<dig)) res = 10LL*res + int64(dig);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    
    for (int vmask = 1; vmask <= all; ++vmask) val[vmask] = getval(vmask);
    for (int x = 1; x <= 100; ++x) mask[x] = getmask(x);
    
    for (int x = 1; x <= 100; ++x) {
        ways[x].clear();
        
        int alone = mask[x];
        if (alone != all) ways[x].push_back(alone);
        
        for (int a = 1; a <= (x/2); ++a) {
            if (mask[a] & mask[x-a]) continue;
            ways[x].push_back(mask[a] | mask[x-a]);
        }
        sort(ways[x].begin(), ways[x].end());
        ways[x].resize( unique(ways[x].begin(),ways[x].end()) - ways[x].begin() ); 
    }
    
    int n;
    int tc = 0;
    while (cin >> n && n) {
        ++tc;
        for (int i = 0; i < n; ++i) cin >> age[i];
        
        int64 best = 1e15;
        for (int now = 1; now <= all; ++now) {
            
            bool ok = true;
            for (int i = 0; i < n; ++i) {
                bool cando = false;
                
                for (size_t j = 0, sz = ways[age[i]].size(); j < sz; ++j) {
                    int need = ways[age[i]][j];
                    if ((now & need) == need) { cando = true; break; }
                }
                
                if (!cando) { ok = false; break; }
            }
            
            if (ok) best = min( best, val[now]);
        }         
        cout << "Case " << tc << ": " << best << "\n";
    }
    
    return 0;
}